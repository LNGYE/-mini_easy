#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tac.h"
#include "obj.h"

/* global var */
int tos; /* top of static */
int tof; /* top of frame */
int oof; /* offset of formal */
int oon; /* offset of next frame */
struct rdesc rdesc[R_NUM];

/*清除指定寄存器 r 的描述符。表示该寄存器不再保存任何变量*/
void clear_desc(int r)    
{
	rdesc[r].var=NULL;
}    

// 将变量 n 插入到指定的寄存器 r 并设置其修改状态 mod
void insert_desc(int r, SYM *n, int mod)
{
	/* Search through each register in turn looking for "n". There should be at most one of these. */
	int or; /* Old descriptor */
	for(or=R_GEN; or < R_NUM; or++)
	{
		if(rdesc[or].var==n)
		{
			/* 找到了，清除它并退出循环 */
			clear_desc(or);
			break;
		}
	}

	/* 在新的描述符中插入变量 "n" */

	rdesc[r].var=n;
	rdesc[r].modified=mod;
}     
void insert_desc_new(int r, SYM *n, int mod, int m, int w, int pos1, int pos2, int pos3, int pos4)
{
	/* Search through each register in turn looking for "n". There should be at most one of these. */
	int or; /* Old descriptor */
	for(or=R_GEN; or < R_NUM; or++)
	{
		if(rdesc[or].var==n && rdesc[or].m==m)
		{
			/* 找到了，清除它并退出循环 */
			clear_desc(or);
			break;
		}
	}

	rdesc[r].var=n;
	rdesc[r].modified=mod;
    rdesc[r].m=m;
    rdesc[r].w=w;
    rdesc[r].pos1=pos1;
    rdesc[r].pos2=pos2;
    rdesc[r].pos3=pos3;
    rdesc[r].pos4=pos4;
}    
void insert_desc_ptr(int r, SYM *n, int mod, int m, int w, int pos1, int pos2, int pos3, int pos4, int offset, SYM *p)
{
	/* 在新的描述符中插入变量 "n" */
	rdesc[r].var=n;
	rdesc[r].modified=mod;
    rdesc[r].m=m;
    rdesc[r].w=w;
    rdesc[r].pos1=pos1;
    rdesc[r].pos2=pos2;
    rdesc[r].pos3=pos3;
    rdesc[r].pos4=pos4;
    rdesc[r].offset=offset;
    rdesc[r].p=p;
} 
// 用于将寄存器中的变量值溢出到内存。当寄存器中的变量被修改后，需要将其存储回内存以确保数据的一致性
void spill_one(int r)
{
    // printf("	rdesc[%d].var:%d  modified:%d\n",r,rdesc[r].var!=NULL,rdesc[r].modified);
	if((rdesc[r].var !=NULL) && rdesc[r].modified)
	{
		if(rdesc[r].var->store==1) /* local var */
		{
            if(rdesc[r].var->type==SYM_ARRAY && rdesc[r].m!=-1) printf("	STO (R%u+%u),R%u\n", R_BP, (rdesc[r].var->offset+4*(rdesc[r].m)), r);
            else printf("	STO (R%u+%u),R%u\n", R_BP, rdesc[r].var->offset, r);
		}
		else /* global var */
		{
            // LOD 指令将全局基地址加载到临时寄存器 R_TP 
			printf("	LOD R%u,STATIC\n", R_TP);
			printf("	STO (R%u+%u),R%u\n", R_TP, rdesc[r].var->offset, r);
		}
		rdesc[r].modified=UNMODIFIED;
	}
    // else printf("	spill_one: UNMODIFIED\n");
}

void spill_all(void)
{
	int r;
	for(r=R_GEN; r < R_NUM; r++) spill_one(r);
} 

// 用于清空所有寄存器的内容，确保所有寄存器中的变量被写回内存，并清除寄存器描述符
void flush_all(void)
{
	int r;

	spill_all();

	for(r=R_GEN; r < R_NUM; r++) clear_desc(r);

	clear_desc(R_TP); /* Clear result register */
}


void load_reg(int r, SYM *n ) 
{
	int s;

	/* 如果找到一个寄存器存了n 则直接从这个寄存器LOD到Rr*/
	for(s=0; s < R_NUM; s++)  
	{
		if(rdesc[s].var==n)
		{
			printf("	LOD R%u,R%u\n", r, s);
			insert_desc(r, n, rdesc[s].modified);
			return;
		}
	}
	
	/* 如果没有寄存器存n */
	switch(n->type)
	{
		case SYM_INT:
		printf("	LOD R%u,%u\n", r, n->value);
		break;

        case SYM_CHAR:
		printf("	LOD R%u,%u\n", r, n->value);
		break;

        // 从内存某处LOD到Rr
		case SYM_VAR:
		if(n->store==1) /* local var */
		{
			if((n->offset)>=0) printf("	LOD R%u,(R%u+%d)\n", r, R_BP, n->offset);
			else printf("	LOD R%u,(R%u-%d)\n", r, R_BP, -(n->offset));
		}
		else /* global var */
		{
			printf("	LOD R%u,STATIC\n", R_TP);
			printf("	LOD R%u,(R%u+%d)\n", r, R_TP, n->offset);
		}
		break;


		case SYM_TEXT:
		printf("	LOD R%u,L%u\n", r, n->label);
		break;
	}

	insert_desc(r, n, UNMODIFIED);
}   
void load_reg_new(int r, SYM *n ,int pos)  // w[2]
{
    int s;

	for(s=0; s < R_NUM; s++)  
	{
		if(rdesc[s].var==n && rdesc[s].m==pos)
		{
            printf("	# find rdesc[%d] whose var == %s and m == %d\n",s,n->name,pos);
			printf("	LOD R%u,R%u\n", r, s);
			insert_desc_new(r, n, rdesc[s].modified,pos,0,-1,-1,0,0);
			return;
		}
	}
	/* 如果没有寄存器存n */
	switch(n->type)
	{
		case SYM_INT:
		printf("	LOD R%u,%u\n", r, n->value);
		break;

        case SYM_CHAR:
		printf("	LOD R%u,%u\n", r, n->value);
		break;

        // 从内存某处LOD到Rr
		case SYM_VAR:
		if(n->store==1) /* local var */
		{
			if((n->offset)>=0) printf("	LOD R%u,(R%u+%d)\n", r, R_BP, n->offset);
			else printf("	LOD R%u,(R%u-%d)\n", r, R_BP, -(n->offset));
		}
		else /* global var */
		{
			printf("	LOD R%u,STATIC\n", R_TP);
			printf("	LOD R%u,(R%u+%d)\n", r, R_TP, n->offset);
		}
        break;

        case SYM_ARRAY:
		if(n->store==1) /* local var */
		{
			if((n->offset)>=0) printf("	LOD R%u,(R%u+%d)\n", r, R_BP, n->offset+4*pos);
			else printf("	LOD R%u,(R%u-%d)\n", r, R_BP, -(n->offset+4*pos));
		}
		else /* global var */
		{
			printf("	LOD R%u,STATIC\n", R_TP);
			printf("	LOD R%u,(R%u+%d)\n", r, R_TP, n->offset+4*pos);
		}
		break;


		case SYM_TEXT:
		printf("	LOD R%u,L%u\n", r, n->label);
		break;
	}

    // printf("	UNMODIFIED\n");
	insert_desc_new(r, n, UNMODIFIED,pos,0,-1,-1,0,0);
}  

/* Get the first reg as a destination reg. */
int get_first_reg(SYM *c)
{
	int r; 
	for(r=R_GEN; r < R_NUM; r++) /* Already in a register */
	{
		if(rdesc[r].var==c)
		{
            // 如果找到，溢出（保存）该寄存器的内容，然后返回该寄存器
			spill_one(r);
			return r;
		}
	}

	for(r=R_GEN; r < R_NUM; r++)
	{
        // 如果找到空闲寄存器（寄存器描述符的变量指针为空），加载变量 c 并返回该寄存器
		if(rdesc[r].var==NULL) /* Empty register */
		{
			load_reg(r, c);
			return r;
		}

	}
	
	for(r=R_GEN; r < R_NUM; r++)
	{
        // 如果找到未修改的寄存器，清除其描述符，加载变量 c 并返回该寄存器
		if(!rdesc[r].modified) /* Unmodifed register */
		{
			clear_desc(r);
			load_reg(r, c);
			return r;
		}
	}

	spill_one(R_GEN); /* Modified register */
	clear_desc(R_GEN);
	load_reg(R_GEN, c);
	return R_GEN;
} 
int get_first_reg_new(SYM *c,int pos)  // w[2]
{
	int r; 
	for(r=R_GEN; r < R_NUM; r++) /* Already in a register */
	{
		if(rdesc[r].var==c && rdesc[r].m==pos)
		{
            // 如果找到，溢出（保存）该寄存器的内容，然后返回该寄存器
            printf("	# find reg1 rdesc[%d] whose var == %s and m == %d\n",r,c->name,pos);
			spill_one(r);
			return r;
		}
	}

	for(r=R_GEN; r < R_NUM; r++)
	{
        // 如果找到空闲寄存器（寄存器描述符的变量指针为空），加载变量 c 并返回该寄存器
		if(rdesc[r].var==NULL) /* Empty register */
		{
            printf("	# find free reg1 rdesc[%d]\n",r);
			load_reg_new(r, c, pos);
			return r;
		}

	}
	
	for(r=R_GEN; r < R_NUM; r++)
	{
        // 如果找到未修改的寄存器，清除其描述符，加载变量 c 并返回该寄存器
		if(!rdesc[r].modified) /* Unmodifed register */
		{
			clear_desc(r);
			load_reg_new(r, c, pos);
			return r;
		}
	}

	spill_one(R_GEN); /* Modified register */
	clear_desc(R_GEN);
	load_reg(R_GEN, c);
	return R_GEN;
} 
/* Get the second reg as a source reg. Exclude the first reg. */
int get_second_reg(SYM *b, int first_reg)             
{
	int r;
	for(r=R_GEN; r < R_NUM; r++)
	{
		if(rdesc[r].var==b) /* Already in register */
		return r;
	}

	for(r=R_GEN; r < R_NUM; r++)
	{
		if(rdesc[r].var==NULL) /* Empty register */
		{
			load_reg(r, b);  //LOD R7,1
			return r;
		}
	}

	for(r=R_GEN; r < R_NUM; r++)
	{
		if(!rdesc[r].modified && (r != first_reg)) /* Unmodifed register */
		{
			clear_desc(r);
			load_reg(r, b);
			return r;
		}
	}

	for(r=R_GEN; r < R_NUM; r++)
	{
		if(r != first_reg) /* Modified register */
		{
			spill_one(r);
			clear_desc(r);
			load_reg(r, b);
			return r;
		}
	}
}

int get_second_reg_new(SYM *b, int pos, int first_reg)             
{
	int r;
	for(r=R_GEN; r < R_NUM; r++)
	{
		if(rdesc[r].var==b && rdesc[r].m==pos) /* Already in register */
        {
            printf("	# find reg2 rdesc[%d] whose var == %s and m == %d\n",r,b->name,pos);
            return r;
        }
	}

	for(r=R_GEN; r < R_NUM; r++)
	{
		if(rdesc[r].var==NULL) /* Empty register */
		{
            printf("	# find free reg2 rdesc[%d]\n",r);
			load_reg_new(r, b, pos);
			return r;
		}
	}

	for(r=R_GEN; r < R_NUM; r++)
	{
		if(!rdesc[r].modified && (r != first_reg)) /* Unmodifed register */
		{
			clear_desc(r);
			load_reg_new(r, b, pos);
			return r;
		}
	}

	for(r=R_GEN; r < R_NUM; r++)
	{
		if(r != first_reg) /* Modified register */
		{
			spill_one(r);
			clear_desc(r);
			load_reg(r, b);
			return r;
		}
	}
}

void asm_bin(char *op, SYM *a, SYM *b, SYM *c,int m,int w,int pos1,int pos2, int pos3, int pos4)
{
    SYM *p=b;
    SYM *q=c;
    int m1=pos1;
    int m2=pos2;
    if (b->type==SYM_PTR){
        int r;
        for(r=R_GEN; r < R_NUM; r++)
        {
            if(rdesc[r].var==b) {
                p=rdesc[r].p;
                if(p->type==SYM_ARRAY) m1=pos3;
                break;
            }
        }
    }
    if (c->type==SYM_PTR){
        int r;
        for(r=R_GEN; r < R_NUM; r++)
        {
            if(rdesc[r].var==c) {
                q=rdesc[r].p;
                if(q->type==SYM_ARRAY) m2=pos4;
                break;
            }
        }
    }

	int reg1=get_first_reg_new(p,m1); /* Result register */
	int reg2=get_second_reg_new(q,m2,reg1); /* One more register */

	printf("	%s R%u,R%u\n", op, reg1, reg2);

	/* Delete c from the descriptors and insert a */
	clear_desc(reg1);
	insert_desc_new(reg1, a, MODIFIED,m,w,pos1,pos2,pos3,pos4);
}   

void asm_cmp(int op, SYM *a, SYM *b, SYM *c)
{
	int reg1=get_first_reg(b); /* Result register */
	int reg2=get_second_reg(c, reg1); /* One more register */

	printf("	SUB R%u,R%u\n", reg1, reg2);
	printf("	TST R%u\n", reg1);

	switch(op)
	{		
		case TAC_EQ:
		printf("	LOD R3,R1+40\n");
		printf("	JEZ R3\n");
		printf("	LOD R%u,0\n", reg1);
		printf("	LOD R3,R1+24\n");
		printf("	JMP R3\n");
		printf("	LOD R%u,1\n", reg1);
		break;
		
		case TAC_NE:
		printf("	LOD R3,R1+40\n");
		printf("	JEZ R3\n");
		printf("	LOD R%u,1\n", reg1);
		printf("	LOD R3,R1+24\n");
		printf("	JMP R3\n");
		printf("	LOD R%u,0\n", reg1);
		break;
		
		case TAC_LT:
		printf("	LOD R3,R1+40\n");
		printf("	JLZ R3\n");
		printf("	LOD R%u,0\n", reg1);
		printf("	LOD R3,R1+24\n");
		printf("	JMP R3\n");
		printf("	LOD R%u,1\n", reg1);
		break;
		
		case TAC_LE:
		printf("	LOD R3,R1+40\n");
		printf("	JGZ R3\n");
		printf("	LOD R%u,1\n", reg1);
		printf("	LOD R3,R1+24\n");
		printf("	JMP R3\n");
		printf("	LOD R%u,0\n", reg1);
		break;
		
		case TAC_GT:
		printf("	LOD R3,R1+40\n");
		printf("	JGZ R3\n");
		printf("	LOD R%u,0\n", reg1);
		printf("	LOD R3,R1+24\n");
		printf("	JMP R3\n");
		printf("	LOD R%u,1\n", reg1);
		break;
		
		case TAC_GE:
		printf("	LOD R3,R1+40\n");
		printf("	JLZ R3\n");
		printf("	LOD R%u,1\n", reg1);
		printf("	LOD R3,R1+24\n");
		printf("	JMP R3\n");
		printf("	LOD R%u,0\n", reg1);
		break;
	}

	/* Delete c from the descriptors and insert a */
	clear_desc(reg1);
	insert_desc(reg1, a, MODIFIED);
}   

void asm_copy(SYM *a, SYM *b,int m,int w, int pos1, int pos2, int pos3, int pos4)
{
    // p=&a; p=w;   p:R5   q:R6   保持不变
    if (a->type==SYM_PTR){
        int r;
        for(r=R_GEN; r < R_NUM; r++)
	    {
            if(rdesc[r].var==NULL) break;
	    }
        insert_desc_ptr(r, a, MODIFIED,m,w,pos1,pos2,pos3,pos4,b->offset,b);
    }
    else {
        int r;
        SYM *q=b;  // 1:q=1   a:q=a  w[2]:q=w  q:w  p:a
        int pos=pos1;  // 1:pos=pos1=-1   a:pos=pos1=-1  w[2]:pos=pos1=2
        if(b->type==SYM_PTR){
            for(r=R_GEN; r < R_NUM; r++)
            {
                if(rdesc[r].var==b) {
                    q=rdesc[r].p;
                    if(q->type==SYM_ARRAY) pos=pos3;  // *(q+3)->w[3]:pos=pos3=3
                    break;
                }
            }
        }
        int reg1=get_first_reg_new(q,pos); /* Load b into a register */
        insert_desc_new(reg1, a, MODIFIED,m,w,pos1,pos2,pos3,pos4); /* Indicate a is there */
    }
}    

void asm_ptr(SYM *a, SYM *b,int m,int w, int pos1, int pos2, int pos3, int pos4)
{
    int r;
    int m1=m;
    int pos=pos1;
    SYM *p;
    SYM *q=b;
    for(r=R_GEN; r < R_NUM; r++)
    {
        if(rdesc[r].var==a) {
            p=rdesc[r].p;
            if(p->type==SYM_ARRAY) m1=w;
            break;
        }
    }
    if(b->type==SYM_PTR){
        for(r=R_GEN; r < R_NUM; r++)
        {
            if(rdesc[r].var==b) {
                q=rdesc[r].p;
                if(q->type==SYM_ARRAY) pos=pos3;
                break;
            }
        }
    }
    int reg1=get_first_reg_new(q,pos); /* Load b into a register */
    insert_desc_new(reg1, p, MODIFIED,m1,w,pos1,pos2,pos3,pos4); /* Indicate a is there */ 
}  


void asm_cond(char *op, SYM *a,  char *l)
{
	spill_all();

	if(a !=NULL)
	{
		int r;

		for(r=R_GEN; r < R_NUM; r++) /* Is it in reg? */
		{
			if(rdesc[r].var==a) break;
		}

		if(r < R_NUM) printf("	TST R%u\n", r);
		else printf("	TST R%u\n", get_first_reg(a)); /* Load into new register */
	}

	printf("	%s %s\n", op, l); 
} 
			   
void asm_return(SYM *a)
{
	if(a !=NULL)					/* return value */
	{
		spill_one(R_TP);
		load_reg(R_TP, a);
	}

	printf("	LOD R3,(R2+4)\n");	/* return address */
	printf("	LOD R2,(R2)\n");	/* restore bp */
	printf("	JMP R3\n");		/* return */
}   

void asm_head()
{
	char head[]=
	"	# head\n"
	"	LOD R2,STACK\n"
	"	STO (R2),0\n"
	"	LOD R4,EXIT\n"
	"	STO (R2+4),R4";

	puts(head);
}

void asm_lib()
{
	char lib[]=
	"\nPRINTN:\n"
	"	LOD R7,(R2-4) # 789\n"
	"	LOD R15,R7 # 789 \n"
	"	DIV R7,10 # 78\n"
	"	TST R7\n"
	"	JEZ PRINTDIGIT\n"
	"	LOD R8,R7 # 78\n"
	"	MUL R8,10 # 780\n"
	"	SUB R15,R8 # 9\n"
	"	STO (R2+8),R15 # local 9 store\n"
	"\n	# out 78\n"
	"	STO (R2+12),R7 # actual 78 push\n"
	"\n	# call PRINTN\n"
	"	STO (R2+16),R2\n"
	"	LOD R4,R1+32\n"
	"	STO (R2+20),R4\n"
	"	LOD R2,R2+16\n"
	"	JMP PRINTN\n"
	"\n	# out 9\n"
	"	LOD R15,(R2+8) # local 9 \n"
	"\nPRINTDIGIT:\n"
	"	ADD  R15,48\n"
	"	OUT\n"
	"\n	# ret\n"
	"	LOD R3,(R2+4)\n"
	"	LOD R2,(R2)\n"
	"	JMP R3\n"
	"\nPRINTS:\n"
	"	LOD R7,(R2-4)\n"
	"\nPRINTC:\n"
	"	LOD R15,(R7)\n"
	"	DIV R15,16777216\n"
	"	TST R15\n"
	"	JEZ PRINTSEND\n"
	"	OUT\n"
	"	ADD R7,1\n"
	"	JMP PRINTC\n"	
	"\nPRINTSEND:\n"
	"	# ret\n"
	"	LOD R3,(R2+4)\n"
	"	LOD R2,(R2)\n"
	"	JMP R3\n"

	"\n"
	"EXIT:\n"
	"	END\n";

	puts(lib);
}

void asm_str(SYM *s)
{
	char *t=s->name; /* The text */
	int i;

	printf("L%u:\n", s->label); /* Label for the string */
	printf("	DBS "); /* Label for the string */

	for(i=1; t[i + 1] !=0; i++)
	{
		if(t[i]=='\\')
		{
			switch(t[++i])
			{
				case 'n':
				printf("%u,", '\n');
				break;

				case '\"':
				printf("%u,", '\"');
				break;
			}
		}
		else printf("%u,", t[i]);
	}

	printf("0\n"); /* End of string */
}

void asm_static(void)
{
	int i;

	SYM *sl;

	for(sl=sym_tab_global; sl !=NULL; sl=sl->next)
	{
		if(sl->type==SYM_TEXT) asm_str(sl);
	}

	printf("STATIC:\n");
	printf("	DBN 0,%u\n", tos);				
	printf("STACK:\n");
}

void asm_code(TAC *c)
{
	int r;

	switch(c->op)
	{
		case TAC_UNDEF:
		error("cannot translate TAC_UNDEF");
		return;

		case TAC_ADD:
        // printf("	# m:%d,w:%d,pos1:%d,pos2:%d,pos3:%d,pos4:%d\n",c->m,c->w,c->pos1,c->pos2,c->pos3,c->pos4);
		asm_bin("ADD", c->a, c->b, c->c,c->m,c->w,c->pos1,c->pos2,c->pos3,c->pos4);
		return;

		case TAC_SUB:
		asm_bin("SUB", c->a, c->b, c->c,c->m,c->w,c->pos1,c->pos2,c->pos3,c->pos4);
		return;

		case TAC_MUL:
		asm_bin("MUL", c->a, c->b, c->c,c->m,c->w,c->pos1,c->pos2,c->pos3,c->pos4);
		return;

		case TAC_DIV:
		asm_bin("DIV",c->a, c->b, c->c,c->m,c->w,c->pos1,c->pos2,c->pos3,c->pos4);
		return;

		case TAC_NEG:
		asm_bin("SUB", c->a, c->b, c->c,c->m,c->w,c->pos1,c->pos2,c->pos3,c->pos4);
		return;

		case TAC_EQ:
		case TAC_NE:
		case TAC_LT:
		case TAC_LE:
		case TAC_GT:
		case TAC_GE:
		asm_cmp(c->op, c->a, c->b, c->c);
		return;

		case TAC_COPY:
        // printf("	# m:%d,w:%d,pos1:%d,pos2:%d,pos3:%d,pos4:%d\n",c->m,c->w,c->pos1,c->pos2,c->pos3,c->pos4);
		asm_copy(c->a, c->b,c->m,c->w,c->pos1,c->pos2,c->pos3,c->pos4);
		return;

        case TAC_COPY_PTR:
        case TAC_COPY_PTR_NEW:
        // printf("	# m:%d,w:%d,pos1:%d,pos2:%d,pos3:%d,pos4:%d\n",c->m,c->w,c->pos1,c->pos2,c->pos3,c->pos4);
        asm_ptr(c->a, c->b,c->m,c->w,c->pos1,c->pos2,c->pos3,c->pos4);
        return;

		case TAC_GOTO:
		asm_cond("JMP", NULL, c->a->name);
		return;

		case TAC_IFZ:
		asm_cond("JEZ", c->b, c->a->name);
		return;

		case TAC_LABEL:
		flush_all();
		printf("%s:\n", c->a->name);
		return;

		case TAC_ACTUAL:
		r=get_first_reg(c->a);
		printf("	STO (R2+%d),R%u\n", tof+oon, r);
		oon += 4;
		return;

		case TAC_CALL:
		flush_all();
		printf("	STO (R2+%d),R2\n", tof+oon);	/* store old bp */
		oon += 4;
		printf("	LOD R4,R1+32\n"); 				/* return addr: 4*8=32 */
		printf("	STO (R2+%d),R4\n", tof+oon);	/* store return addr */
		oon += 4;
		printf("	LOD R2,R2+%d\n", tof+oon-8);	/* load new bp */
		printf("	JMP %s\n", (char *)c->b);	/* jump to new func */
		if(c->a !=NULL) insert_desc(R_TP, c->a, MODIFIED);
		oon=0;
		return;

		case TAC_BEGINFUNC:
		/* We reset the top of stack, since it is currently empty apart from the link information. */
		scope_local=1;
		tof=LOCAL_OFF;
		oof=FORMAL_OFF;
		oon=0;
		return;

		case TAC_FORMAL:
		c->a->store=1; /* parameter is special local var */
		c->a->offset=oof;
		oof -=4;
		return;

		case TAC_VAR:
		if(scope_local)
		{
			c->a->store=1; /* local var */
            c->a->offset=tof;
            printf("	offset:%d\n",c->a->offset);
			if (c->a->type==SYM_ARRAY) tof +=4*(c->a->upper);
            else tof +=4;
		}
		else
		{
			c->a->store=0; /* global var */
            c->a->offset=tos;
            printf("	offset:%d\n",c->a->offset);
            if (c->a->type==SYM_ARRAY) tos +=4*(c->a->upper);
            else tos +=4;
		}
		return;

		case TAC_RETURN:
		asm_return(c->a);
		return;

		case TAC_ENDFUNC:
		asm_return(NULL);
		scope_local=0;
		return;

        case TAC_AND:
		case TAC_OR:
        case TAC_NOT:
        return;

		default:
		/* Don't know what this one is */
		error("unknown TAC opcode to translate");
		return;
	}
}

void tac_obj()
{
    // LOCAL_OFF 8 		/* local var 局部变量的偏移*/
	tof=LOCAL_OFF; /* TOS allows space for link info */
	oof=FORMAL_OFF;
	oon=0;

    // 遍历所有寄存器描述符，将变量指针设置为空，表示没有变量存储在寄存器中。
    // 在 R0 寄存器中插入一个表示常量 0 的描述符。
	int r;
	for(r=0; r < R_NUM; r++) 
		rdesc[r].var=NULL;
	insert_desc(0, mk_const(0), UNMODIFIED); /* R0 holds 0 */

	asm_head();

	TAC * cur;
	for(cur=tac_first; cur!=NULL; cur=cur->next)
	{
		printf("\n	# ");
		tac_print(cur);
		printf("\n");
		asm_code(cur);
	}
	asm_lib();
	asm_static();
} 

