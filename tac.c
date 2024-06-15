#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tac.h"

/* global var */
int scope_local, next_tmp, next_label; /*当前局部作用域的深度,生成临时变量的编号,生成标签的编号*/
SYM *sym_tab_global, *sym_tab_local;   /*全局和局部符号表*/
TAC *tac_first, *tac_last;

/*初始化了一些全局变量*/
void tac_init()
{
	scope_local=0;
	sym_tab_global=NULL;
	sym_tab_local=NULL;	
	next_tmp=0;
	next_label=1;
}
/*完成 TAC链表的构建*/
void tac_complete()
{
	TAC *cur=NULL; 		/* Current TAC */
	TAC *prev=tac_last; 	/* Previous TAC */

	while(prev !=NULL)
	{
		prev->next=cur;
		cur=prev;
		prev=prev->prev;
	}

	tac_first = cur;
}
/*在给定的符号表 symtab 中查找符号名为 name 的符号, 回该符号的指针 or NULL*/
SYM *lookup_sym(SYM *symtab, char *name)
{   
	SYM *t=symtab;
	while(t !=NULL)
	{
		if(strcmp(t->name, name)==0) break; 
		else t=t->next;
	}
	
	return t; /* NULL if not found */
}
/*将新的符号节点 sym 插入到符号表的头部*/
void insert_sym(SYM **symtab, SYM *sym)
{
	sym->next=*symtab; /* Insert at head */
	*symtab=sym;
}
/*创建一个新的符号节点，并返回指向该节点的指针*/
SYM *mk_sym(void)
{
	SYM *t;
	t=(SYM *)malloc(sizeof(SYM));
	return t;
}
/*创建一个新的变量符号，并将其插入到相应的符号表中,全局 or 局部 返回该符号节点的指针*/
SYM *mk_var(char *name)
{
	SYM *sym=NULL;

	if(scope_local)  
		sym=lookup_sym(sym_tab_local,name);
	else
		sym=lookup_sym(sym_tab_global,name);

	/* var already declared */
	if(sym!=NULL)
	{
		error("variable already declared");
		return NULL;
	}

	/* var unseen before, set up a new symbol table node, insert_sym it into the symbol table. */
	sym=mk_sym();// 创建一个新的符号
	sym->type=SYM_VAR;
	sym->name=name; /* ysj */
	sym->offset=-1; /* Unset address */
    sym->upper=1; 

	if(scope_local)  
		insert_sym(&sym_tab_local,sym);
	else
		insert_sym(&sym_tab_global,sym);

	return sym;
}
SYM *mk_arr(char *name,char *num)
{
	SYM *sym=NULL;

	if(scope_local)  
		sym=lookup_sym(sym_tab_local,name);
	else
		sym=lookup_sym(sym_tab_global,name);

	/* var already declared */
	if(sym!=NULL)
	{
		error("variable already declared");
		return NULL;
	}

	/* var unseen before, set up a new symbol table node, insert_sym it into the symbol table. */
	sym=mk_sym();// 创建一个新的符号
	sym->type=SYM_ARRAY;
	sym->name=name; 
	sym->offset=-1; /* Unset address */
    sym->upper=atoi(num); /*数组大小*/

	if(scope_local)  
		insert_sym(&sym_tab_local,sym);
	else
		insert_sym(&sym_tab_global,sym);

	return sym;
}
SYM *mk_ptr(char *name)
{
	SYM *sym=NULL;

	if(scope_local)  
		sym=lookup_sym(sym_tab_local,name);
	else
		sym=lookup_sym(sym_tab_global,name);

	/* var already declared */
	if(sym!=NULL)
	{
		error("variable already declared");
		return NULL;
	}

	/* var unseen before, set up a new symbol table node, insert_sym it into the symbol table. */
	sym=mk_sym();// 创建一个新的符号
	sym->type=SYM_PTR;
	sym->name=name; /* ysj */
	sym->offset=-1; /* Unset address */
    sym->ptr_upper=0;   /*指针偏移量,如果指向var则ptr_upper=0,如果指向array则ptr_upper=upper-1*/

	if(scope_local)  
		insert_sym(&sym_tab_local,sym);
	else
		insert_sym(&sym_tab_global,sym);

	return sym;
}
/*连接两个 TAC 链表，即将两个 TAC 链表连接成一个,最后返回第二个链表的头部，即合并后的链表*/
TAC *join_tac(TAC *c1, TAC *c2)
{
	TAC *t;

	if(c1==NULL) return c2;
	if(c2==NULL) return c1;

	/* Run down c2, until we get to the beginning and then add c1 */
	t=c2;
	while(t->prev !=NULL) 
		t=t->prev;

	t->prev=c1;
	return c2;
}
/*创建一个表示变量声明的 TAC*/
TAC *declare_var(char *name)
{
	return mk_tac(TAC_VAR,mk_var(name),NULL,NULL);
}

TAC *declare_ptr(char *name)
{
	return mk_tac(TAC_VAR,mk_ptr(name),NULL,NULL);
}

/*创建一个表示数组变量声明的 TAC*/
TAC* declare_arr_new(char* name,char* num)
{
    return mk_tac_new(TAC_VAR,mk_arr(name,num),NULL,NULL,atoi(num),0,-1,-1,0,0);
}


/*创建一个新的 TAC 节点*/
TAC *mk_tac(int op, SYM *a, SYM *b, SYM *c)
{
	TAC *t=(TAC *)malloc(sizeof(TAC));

	t->next=NULL; /* Set these for safety */
	t->prev=NULL;
	t->op=op;
	t->a=a;
	t->b=b;
	t->c=c;
    t->m=-1;
    t->w=0;
    t->pos1=-1;
    t->pos2=-1;
    t->pos3=0;
    t->pos4=0;

	return t;
}  
TAC *mk_tac_new(int op, SYM *a, SYM *b, SYM *c,int num1,int num2,int pos1,int pos2,int pos3,int pos4)
{
	TAC *t=(TAC *)malloc(sizeof(TAC));
	t->next=NULL; /* Set these for safety */
	t->prev=NULL;
	t->op=op;
	t->a=a;
	t->b=b;
	t->c=c;
    t->m=num1;
    t->w=num2;
    t->pos1=pos1;
    t->pos2=pos2;
    t->pos3=pos3;
    t->pos4=pos4;

	return t;
}
/*创建一个表示标签label的符号*/
SYM *mk_label(char *name)
{
	SYM *t=mk_sym();

	t->type=SYM_LABEL;
	t->name=strdup(name);

	return t;
}  
/*生成函数的 TAC 代码*/
TAC *do_func(SYM *func, TAC *args, TAC *code)
{
	TAC *tlist; /* The backpatch list */

	TAC *tlab; /* Label at start of function */
	TAC *tbegin; /* BEGINFUNC marker */
	TAC *tend; /* ENDFUNC marker */

	tlab=mk_tac(TAC_LABEL, mk_label(func->name), NULL, NULL);
	tbegin=mk_tac(TAC_BEGINFUNC, NULL, NULL, NULL);
	tend=mk_tac(TAC_ENDFUNC,   NULL, NULL, NULL);

	tbegin->prev=tlab;
	code=join_tac(args, code);
	tend->prev=join_tac(tbegin, code);

	return tend;
}
/*创建临时变量*/
SYM *mk_tmp(void)
{
	SYM *sym;
	char *name;

	name=malloc(12);
	sprintf(name, "t%d", next_tmp++); /* Set up text */
	return mk_var(name);
}
/*声明函数的参数*/
TAC *declare_para(char *name)
{
	return mk_tac(TAC_FORMAL,mk_var(name),NULL,NULL);
}
/*声明函数*/
SYM *declare_func(char *name)
{
	SYM *sym=NULL;

	sym=lookup_sym(sym_tab_global,name);

	/* name used before declared */
	if(sym!=NULL)
	{
		if(sym->type==SYM_FUNC)
		{
			error("func already declared");
			return NULL;
		}

		if(sym->type !=SYM_UNDEF)
		{
			error("func name already used");
			return NULL;
		}

		return sym;
	}
	
	
	sym=mk_sym();
	sym->type=SYM_FUNC;
	sym->name=name;
	sym->address=NULL;

	insert_sym(&sym_tab_global,sym);
	return sym;
}
/*生成赋值语句的 TAC 代码*/
TAC *do_assign(SYM *var, EXP *exp) // p=&a;   p=w;
{
	TAC *code;

	if(var->type !=SYM_VAR && var->type !=SYM_PTR) error("assignment to non-variable or non-ptr");

    if(var->type==SYM_VAR){
        code=mk_tac_new(TAC_COPY, var, exp->ret, NULL,-1,0,exp->pos1,exp->pos2,exp->pos3,exp->pos4);
    }
    if(var->type==SYM_PTR){
        code=mk_tac_new(TAC_COPY, var, exp->ret, NULL,-1,0,exp->pos1,exp->pos2,exp->pos3,exp->pos4);
        var->ptr_upper=exp->ret->upper-1;
    }
	code->prev=exp->tac;

	return code;
}
/*生成数组赋值语句的 TAC 代码*/
TAC *do_assign_arr(SYM *var,char* num, EXP *exp) // w[1]=2
{
	TAC *code;
	if(var->type !=SYM_ARRAY) error("assignment to non-array");
    if (var->upper<=atoi(num))error("The array is out of bounds");
    code=mk_tac_new(TAC_COPY, var, exp->ret, NULL,atoi(num),0,exp->pos1,exp->pos2,exp->pos3,exp->pos4);
	code->prev=exp->tac;

	return code;
}
TAC *do_assign_ptr(SYM *var,EXP *exp) // *p=a
{
	TAC *code;
    code=mk_tac_new(TAC_COPY_PTR, var, exp->ret, NULL,-1,0,exp->pos1,exp->pos2,exp->pos3,exp->pos4);
	code->prev=exp->tac;
	return code;
}
TAC *do_assign_ptr_new(SYM *var,char* num,EXP *exp) // *(p+1)=a
{
	TAC *code;
    if (var->ptr_upper<atoi(num))error("The ptr is out of bounds");
    code=mk_tac_new(TAC_COPY_PTR_NEW, var, exp->ret, NULL,-1,atoi(num),exp->pos1,exp->pos2,exp->pos3,exp->pos4);
    
	code->prev=exp->tac;
	return code;
}
/*处理二元操作:接受两个表达式exp1 和 exp2以及一个二元操作码binop并生成对应的 TAC 代码*/
EXP *do_bin( int binop, EXP *exp1, EXP *exp2)
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

	if((exp1->ret->type==SYM_INT) && (exp2->ret->type==SYM_INT))
	{
		int newval; /* The result of constant folding */

		switch(binop) /* Chose the operator */
		{
			case TAC_ADD:
			newval=exp1->ret->value + exp2->ret->value;
			break;

			case TAC_SUB:
			newval=exp1->ret->value - exp2->ret->value;
			break;

			case TAC_MUL:
			newval=exp1->ret->value * exp2->ret->value;
			break;

			case TAC_DIV:
			newval=exp1->ret->value / exp2->ret->value;
			break;
		}

		exp1->ret=mk_const(newval); /* New space for result */

		return exp1; /* The new expression */
	}
    if ((exp1->ret->type==SYM_CHAR) && (exp2->ret->type==SYM_CHAR)||
    (exp1->ret->type==SYM_INT) && (exp2->ret->type==SYM_CHAR)||
    (exp1->ret->type==SYM_CHAR) && (exp2->ret->type==SYM_INT)){

        char newval; /* The result of char folding */

		switch(binop) /* Chose the operator */
		{
			case TAC_ADD:
			newval=exp1->ret->value + exp2->ret->value;
			break;

			case TAC_SUB:
			newval=exp1->ret->value - exp2->ret->value;
			break;

			case TAC_MUL:
			newval=exp1->ret->value * exp2->ret->value;
			break;

			case TAC_DIV:
			newval=exp1->ret->value / exp2->ret->value;
			break;
		}

		exp1->ret=mk_char(newval); /* New space for result */

		return exp1; /* The new expression */
    }

	temp=mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev=join_tac(exp1->tac, exp2->tac);
	ret=mk_tac(binop, temp->a, exp1->ret, exp2->ret);
	ret->prev=temp;
    ret->pos1=exp1->pos1;
    ret->pos2=exp2->pos1;
    ret->pos3=exp1->pos3;
    ret->pos4=exp2->pos3;

	exp1->ret=temp->a;
	exp1->tac=ret;
    // 这里一定要初始化
    exp1->pos1=-1;
    exp1->pos2=-1;
    exp1->pos3=0;
    exp1->pos4=0;

	return exp1;  
}   
/*处理比较操作 包括等于、不等于、小于、小于等于、大于和大于等于*/
EXP *do_cmp( int binop, EXP *exp1, EXP *exp2)
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

	if((exp1->ret->type==SYM_INT) && (exp2->ret->type==SYM_INT))
	{
		int newval; /* The result of constant folding */

		switch(binop) /* Chose the operator */
		{
			case TAC_EQ:
			newval=(exp1->ret->value==exp2->ret->value);
			break;
			
			case TAC_NE:
			newval=(exp1->ret->value !=exp2->ret->value);
			break;
			
			case TAC_LT:
			newval=(exp1->ret->value < exp2->ret->value);
			break;
			
			case TAC_LE:
			newval=(exp1->ret->value <=exp2->ret->value);
			break;
			
			case TAC_GT:
			newval=(exp1->ret->value > exp2->ret->value);
			break;
			
			case TAC_GE:
			newval=(exp1->ret->value >=exp2->ret->value);
			break;
		}

		exp1->ret=mk_const(newval); /* New space for result */
		return exp1; /* The new expression */
	}

    if((exp1->ret->type==SYM_CHAR) && (exp2->ret->type==SYM_CHAR))
	{
		int newval; /* The result of constant folding */

		switch(binop) /* Chose the operator */
		{
			case TAC_EQ:
			newval=((int)exp1->ret->value==(int)exp2->ret->value);
			break;
			
			case TAC_NE:
			newval=((int)exp1->ret->value !=(int)exp2->ret->value);
			break;
			
			case TAC_LT:
			newval=((int)exp1->ret->value < (int)exp2->ret->value);
			break;
			
			case TAC_LE:
			newval=((int)exp1->ret->value <=(int)exp2->ret->value);
			break;
			
			case TAC_GT:
			newval=((int)exp1->ret->value > (int)exp2->ret->value);
			break;
			
			case TAC_GE:
			newval=((int)exp1->ret->value >=(int)exp2->ret->value);
			break;
		}

		exp1->ret=mk_char(newval); /* New space for result */
		return exp1; /* The new expression */
	}

	temp=mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev=join_tac(exp1->tac, exp2->tac);
	ret=mk_tac(binop, temp->a, exp1->ret, exp2->ret);
	ret->prev=temp;
    ret->pos1=exp1->pos1;
    ret->pos2=exp2->pos1;
    ret->pos3=exp1->pos3;
    ret->pos4=exp2->pos3;

	exp1->ret=temp->a;
	exp1->tac=ret;

	return exp1;  
}   
EXP *do_and( int binop, EXP *exp1, EXP *exp2)
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

    if((exp1->ret->type==SYM_INT) && (exp2->ret->type==SYM_INT))
    {
        int newval; /* The result of constant folding */

        if((exp1->ret->value!=0) && (exp2->ret->value!=0)){
            newval=1;
        }
        else {newval=0;}

        exp1->ret=mk_const(newval); /* New space for result */
        return exp1; /* The new expression */
    }

	temp=mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev=join_tac(exp1->tac, exp2->tac);
	ret=mk_tac(binop, temp->a, exp1->ret, exp2->ret);
	ret->prev=temp;
    ret->pos1=exp1->pos1;
    ret->pos2=exp2->pos1;
    ret->pos3=exp1->pos3;
    ret->pos4=exp2->pos3;

	exp1->ret=temp->a;
	exp1->tac=ret;

	return exp1;  
} 
EXP *do_or(int binop,  EXP *exp1, EXP *exp2)
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

    if((exp1->ret->type==SYM_INT) && (exp2->ret->type==SYM_INT))
    {
        int newval; /* The result of constant folding */

        if((exp1->ret->value!=0) || (exp2->ret->value!=0)){
            newval=1;
        }
        else {newval=0;}

        exp1->ret=mk_const(newval); /* New space for result */
        return exp1; /* The new expression */
    }

	temp=mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev=join_tac(exp1->tac, exp2->tac);
	ret=mk_tac(binop, temp->a, exp1->ret, exp2->ret);
	ret->prev=temp;
    ret->pos1=exp1->pos1;
    ret->pos2=exp2->pos1;
    ret->pos3=exp1->pos3;
    ret->pos4=exp2->pos3;

	exp1->ret=temp->a;
	exp1->tac=ret;

	return exp1; 
}   
EXP *do_not( int binop, EXP *exp)
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

    if(exp->ret->type==SYM_INT)
    {
        int newval; /* The result of constant folding */

        if(exp->ret->value==0){
            newval=1;
        }
        else {newval=0;}

        exp->ret=mk_const(newval); /* New space for result */
        return exp; /* The new expression */
    }

	temp=mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev=exp->tac;
	ret=mk_tac(binop, temp->a, exp->ret, NULL);
	ret->prev=temp;
    ret->pos1=exp->pos1;
    ret->pos3=exp->pos3;

	exp->ret=temp->a;
	exp->tac=ret;

	return exp; 
}   
/*处理一元操作，例如取负数*/
EXP *do_un( int unop, EXP *exp) 
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

	/* Do constant folding if possible. Calculate the constant into exp */
	if(exp->ret->type==SYM_INT)
	{
		switch(unop) /* Chose the operator */
		{
			case TAC_NEG:
			exp->ret->value=- exp->ret->value;
			break;
		}

		return exp; /* The new expression */
	}

	temp=mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev=exp->tac;
	ret=mk_tac(unop, temp->a, exp->ret, NULL);
	ret->prev=temp;
    ret->pos1=exp->pos1;
    ret->pos3=exp->pos3;

	exp->ret=temp->a;
	exp->tac=ret;

	return exp;   
}
/*生成函数调用的 TAC 代码 最后生成 CALL 指令来调用函数*/
TAC *do_call(char *name, EXP *arglist)
{
	EXP  *alt; /* For counting args */
	TAC *code; /* Resulting code */
	TAC *temp; /* Temporary for building code */

	code=NULL;
	for(alt=arglist; alt !=NULL; alt=alt->next) code=join_tac(code, alt->tac);

	while(arglist !=NULL) /* Generate ARG instructions */
	{
		temp=mk_tac(TAC_ACTUAL, arglist->ret, NULL, NULL);
		temp->prev=code;
		code=temp;

		alt=arglist->next;
		arglist=alt;
	};

	temp=mk_tac(TAC_CALL, NULL, (SYM *)strdup(name), NULL);
	temp->prev=code;
	code=temp;

	return code;
}
/*处理有返回值的函数调用  返回一个表示函数调用的表达式*/
EXP *do_call_ret(char *name, EXP *arglist)
{
	EXP  *alt; /* For counting args */
	SYM *ret; /* Where function result will go */
	TAC *code; /* Resulting code */
	TAC *temp; /* Temporary for building code */

	ret=mk_tmp(); /* For the result */
	code=mk_tac(TAC_VAR, ret, NULL, NULL);

	for(alt=arglist; alt !=NULL; alt=alt->next) code=join_tac(code, alt->tac);

	while(arglist !=NULL) /* Generate ARG instructions */
	{
		temp=mk_tac(TAC_ACTUAL, arglist->ret, NULL, NULL);
		temp->prev=code;
		code=temp;

		alt=arglist->next;
		arglist=alt;
	};

	temp=mk_tac(TAC_CALL, ret, (SYM *)strdup(name), NULL);
	temp->prev=code;
	code=temp;

	return mk_exp(NULL, ret, code);
}
/*生成库函数调用的 TAC 代码*/
TAC *do_lib(char *name, SYM *arg)
{
        TAC *a=mk_tac(TAC_ACTUAL, arg, NULL, NULL);
        TAC *c=mk_tac(TAC_CALL, NULL, (SYM *)strdup(name), NULL);
        c->prev=a;
        return c;
}
/*生成唯一的标签字符串*/
char *mk_lstr(int i)
{
	char lstr[10]="L";
	sprintf(lstr,"L%d",i);
	return(strdup(lstr));	
}
/*生成条件语句的 TAC 代码*/
TAC *do_if(EXP *exp, TAC *stmt)
{
	TAC *label=mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL);
    /*这里创建了一个TAC语句  用于条件分支TAC_IFZ。它检查表达式exp的结果是否为零  如果是  则跳转到上面创建的标签*/
	TAC *code=mk_tac(TAC_IFZ, label->a, exp->ret, NULL);

    /*这行将先前生成的TAC语句 条件分支 链接到表达式exp的TAC代码 它使新创建的条件分支依赖于表达式的计算结果*/
	code->prev=exp->tac;
    /*这行将生成的条件分支的TAC代码 code 与语句块的TAC代码 stmt 连接起来 它有效地添加了在条件为真时执行的语句块的TAC语句*/
	code=join_tac(code, stmt);
    /*最后 这行将标签链接到在if条件之后生成的TAC代码。它实际上设置了标签作为条件为假时的跳转目标*/
	label->prev=code;

	return label;
}
/*生成条件测试语句的 TAC 代码*/
TAC *do_test(EXP *exp, TAC *stmt1, TAC *stmt2)
{
	TAC *label1=mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL);
	TAC *label2=mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL);
    /*创建了两个TAC语句 一个是用于条件分支 TAC_IFZ  另一个是无条件跳转 TAC_GOTO */
	TAC *code1=mk_tac(TAC_IFZ, label1->a, exp->ret, NULL);
	TAC *code2=mk_tac(TAC_GOTO, label2->a, NULL, NULL);

	code1->prev=exp->tac; /* Join the code */
	code1=join_tac(code1, stmt1);
	code2->prev=code1;
	label1->prev=code2;
	label1=join_tac(label1, stmt2);
	label2->prev=label1;
	
	return label2;
}
/*生成 while 循环的 TAC 代码*/
TAC *do_while(EXP *exp, TAC *stmt) 
{
	TAC *label=mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL);
	TAC *code=mk_tac(TAC_GOTO, label->a, NULL, NULL);

	code->prev=stmt; /* Bolt on the goto */

	return join_tac(label, do_if(exp, code));
}
/*生成 for 循环的 TAC 代码*/
TAC *do_for(TAC *stmt1, EXP *exp, TAC *stmt2,TAC *stmt3) 
{
	TAC *label=mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL);
    TAC *code=mk_tac(TAC_GOTO, label->a, NULL, NULL);

    label=join_tac(stmt1,label);
    stmt3=join_tac(stmt3,stmt2);
    code->prev=stmt3;

    return join_tac(label, do_if(exp, code));
}
/*获取变量的符号信息 返回该符号，否则报错*/
SYM *get_var(char *name)
{
	SYM *sym=NULL; /* Pointer to looked up symbol */
	if(scope_local) sym=lookup_sym(sym_tab_local,name);

	if(sym==NULL) sym=lookup_sym(sym_tab_global,name);

	if(sym==NULL)
	{
		error("name not declared as local/global variable");
		return NULL;
	}

	if(sym->type!=SYM_VAR && sym->type!=SYM_ARRAY && sym->type!=SYM_PTR)
	{
		error("not a variable or a array or a ptr");
		return NULL;
	}

	return sym;
} 


/*创建一个表达式 ret表达式的返回值 即表达式的计算结果对应的符号*/
EXP *mk_exp(EXP *next, SYM *ret, TAC *code)
{
	EXP *exp=(EXP *)malloc(sizeof(EXP));

	exp->next=next;
	exp->ret=ret;
	exp->tac=code;
    exp->pos1=-1;
    exp->pos2=-1;
    exp->pos3=0;
    exp->pos4=0;

	return exp;
}
EXP *mk_exp_ptr(EXP *next, SYM *ret, char *num, TAC *code)
{
    if(ret->ptr_upper<atoi(num))error("The ptr is out of bounds");
	EXP *exp=(EXP *)malloc(sizeof(EXP));
	exp->next=next;
	exp->ret=ret;
	exp->tac=code;
    exp->pos1=-1;
    exp->pos2=-1;
    exp->pos3=atoi(num);
    exp->pos4=0;

	return exp;
}
EXP *mk_exp_arr(EXP *next, SYM *ret, char *num, TAC *code)
{
    if(ret->upper<=atoi(num))error("The array is out of bounds");
	EXP *exp=(EXP *)malloc(sizeof(EXP));
	exp->next=next;
	exp->ret=ret;
	exp->tac=code;
    exp->pos1=atoi(num);
    exp->pos2=-1;
    exp->pos3=0;
    exp->pos4=0;

	return exp;
}

/*创建文本类型的符号*/
SYM *mk_text(char *text)
{
	SYM *sym=NULL; /* Pointer to looked up symbol */

	sym=lookup_sym(sym_tab_global,text);

	/* text already used */
	if(sym!=NULL)
	{
		return sym;
	}

	/* text unseen before, set up a new symbol table node, insert_sym it into the symbol table. */
	sym=mk_sym();
	sym->type=SYM_TEXT;
	sym->name=text; /* ysj */
	sym->label=next_label++; /* ysj */

	insert_sym(&sym_tab_global,sym);
	return sym;
}
/*创建整数常量类型的符号*/
SYM *mk_const(int n)
{
	SYM *c=mk_sym(); /* Create a new node */

	c->type=SYM_INT;
	c->value=n; /* ysj */
	return c;
}    
/*创建字符类型的符号*/ 
SYM *mk_char(char n)
{
    SYM *c=mk_sym();

	c->type=SYM_CHAR;
	c->value=n;
	return c;
}

/*将符号转换为字符串表示*/
char *to_str(SYM *s, char *str) 
{
	/* Check we haven't been given NULL */
	if(s==NULL)	return "NULL";

	/* Identify the type */
	switch(s->type)
	{
		case SYM_FUNC:
		case SYM_VAR:
        case SYM_ARRAY:
        case SYM_PTR:
		/* Just return the name */
		return s->name; /* ysj */

		case SYM_TEXT:
		/* Put the address of the text */
		sprintf(str, "L%d", s->label);
		return str;

		case SYM_INT:
		/* Convert the number to string */
		sprintf(str, "%d", s->value);
		return str;

        case SYM_CHAR:
		/* Convert the number to string */
		sprintf(str, "\'%c\'", s->value);
		return str;

		default:
		/* Unknown arg type */
		error("unknown TAC arg type");
		return "?";
	}
} 
/*打印单个 TAC 指令的字符串表示*/
void tac_print(TAC *i)
{
	char sa[12]; /* For text of TAC args */
	char sb[12];
	char sc[12];

	switch(i->op)
	{
		case TAC_UNDEF:
		printf("undef");
		break;

		case TAC_ADD:
        if(i->b->type==SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = %s[%d] + %s[%d]", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc),i->pos2);
        else if(i->b->type==SYM_ARRAY && i->c->type==SYM_VAR)printf("%s = %s[%d] + %s", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc));
		else if(i->b->type==SYM_VAR && i->c->type==SYM_ARRAY)printf("%s = %s + %s[%d]", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc),i->pos2);
        else if(i->b->type==SYM_VAR && i->c->type==SYM_VAR)printf("%s = %s + %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
        
        else if(i->b->type==SYM_ARRAY && i->c->type==SYM_PTR && i->pos4==0)printf("%s = %s[%d] + *%s", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc));
		else if(i->b->type==SYM_PTR && i->c->type==SYM_ARRAY && i->pos3==0)printf("%s = *%s + %s[%d]", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc),i->pos2);
        else if(i->b->type==SYM_ARRAY && i->c->type==SYM_PTR && i->pos4!=0)printf("%s = %s[%d] + *(%s + %d)", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc),i->pos4);
		else if(i->b->type==SYM_PTR && i->c->type==SYM_ARRAY && i->pos3!=0)printf("%s = *(%s + %d) + %s[%d]", to_str(i->a, sa), to_str(i->b, sb),i->pos3, to_str(i->c, sc),i->pos2);

        else if(i->b->type==SYM_VAR && i->c->type==SYM_PTR && i->pos4==0)printf("%s = %s + *%s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		else if(i->b->type==SYM_PTR && (i->c->type==SYM_VAR || i->c->type==SYM_INT) && i->pos3==0)printf("%s = *%s + %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
        else if(i->b->type==SYM_VAR && i->c->type==SYM_PTR && i->pos4!=0)printf("%s = %s + *(%s + %d)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc),i->pos4);
		else if(i->b->type==SYM_PTR && i->c->type==SYM_VAR && i->pos3!=0)printf("%s = *(%s + %d) + %s", to_str(i->a, sa), to_str(i->b, sb),i->pos3, to_str(i->c, sc));
        
        else if(i->b->type==SYM_PTR && i->c->type==SYM_PTR && i->pos3==0 && i->pos4==0)printf("%s = *%s + *%s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
        else if(i->b->type==SYM_PTR && i->c->type==SYM_PTR && i->pos3!=0 && i->pos4==0)printf("%s = *(%s + %d) + *%s", to_str(i->a, sa), to_str(i->b, sb),i->pos3, to_str(i->c, sc));
        else if(i->b->type==SYM_PTR && i->c->type==SYM_PTR && i->pos3==0 && i->pos4!=0)printf("%s = *%s + *(%s + %d)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc),i->pos4);
        else if(i->b->type==SYM_PTR && i->c->type==SYM_PTR && i->pos3!=0 && i->pos4!=0)printf("%s = *(%s + %d) + *(%s + %d)", to_str(i->a, sa), to_str(i->b, sb),i->pos3, to_str(i->c, sc),i->pos4);

        else printf("%s = %s + %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
        break;

		case TAC_SUB:
		if(i->b->type==SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = %s[%d] - %s[%d]", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc),i->pos2);
        if(i->b->type==SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = %s[%d] - %s", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc));
		if(i->b->type!=SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = %s - %s[%d]", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc),i->pos2);
        if(i->b->type!=SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = %s - %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_MUL:
		if(i->b->type==SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = %s[%d] * %s[%d]", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc),i->pos2);
        if(i->b->type==SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = %s[%d] * %s", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc));
		if(i->b->type!=SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = %s * %s[%d]", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc),i->pos2);
        if(i->b->type!=SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = %s * %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_DIV:
		if(i->b->type==SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = %s[%d] / %s[%d]", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc),i->pos2);
        if(i->b->type==SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = %s[%d] / %s", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc));
		if(i->b->type!=SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = %s / %s[%d]", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc),i->pos2);
        if(i->b->type!=SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = %s / %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_EQ:
        if(i->b->type==SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = (%s[%d] == %s[%d])", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc),i->pos2);
        if(i->b->type==SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = (%s[%d] == %s)", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc));
		if(i->b->type!=SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = (%s == %s[%d])", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc),i->pos2);
        if(i->b->type!=SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = (%s == %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_NE:
        if(i->b->type==SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = (%s[%d] != %s[%d])", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc),i->pos2);
        if(i->b->type==SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = (%s[%d] != %s)", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc));
		if(i->b->type!=SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = (%s != %s[%d])", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc),i->pos2);
        if(i->b->type!=SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = (%s != %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_LT:
        if(i->b->type==SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = (%s[%d] < %s[%d])", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc),i->pos2);
        if(i->b->type==SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = (%s[%d] < %s)", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc));
		if(i->b->type!=SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = (%s < %s[%d])", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc),i->pos2);
        if(i->b->type!=SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = (%s < %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_LE:
        if(i->b->type==SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = (%s[%d] <= %s[%d])", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc),i->pos2);
        if(i->b->type==SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = (%s[%d] <= %s)", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc));
		if(i->b->type!=SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = (%s <= %s[%d])", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc),i->pos2);
        if(i->b->type!=SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = (%s <= %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_GT:
        if(i->b->type==SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = (%s[%d] > %s[%d])", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc),i->pos2);
        if(i->b->type==SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = (%s[%d] > %s)", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc));
		if(i->b->type!=SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = (%s > %s[%d])", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc),i->pos2);
        if(i->b->type!=SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = (%s > %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_GE:
        if(i->b->type==SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = (%s[%d] >= %s[%d])", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc),i->pos2);
        if(i->b->type==SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = (%s[%d] >= %s)", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc));
		if(i->b->type!=SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = (%s >= %s[%d])", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc),i->pos2);
        if(i->b->type!=SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = (%s >= %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

        case TAC_AND:
        if(i->b->type==SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = (%s[%d] && %s[%d])", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc),i->pos2);
        if(i->b->type==SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = (%s[%d] && %s)", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc));
		if(i->b->type!=SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = (%s && %s[%d])", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc),i->pos2);
        if(i->b->type!=SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = (%s && %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

        case TAC_OR:
        if(i->b->type==SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = (%s[%d] || %s[%d])", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc),i->pos2);
        if(i->b->type==SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = (%s[%d] || %s)", to_str(i->a, sa), to_str(i->b, sb),i->pos1, to_str(i->c, sc));
		if(i->b->type!=SYM_ARRAY && i->c->type==SYM_ARRAY)printf("%s = (%s || %s[%d])", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc),i->pos2);
        if(i->b->type!=SYM_ARRAY && i->c->type!=SYM_ARRAY)printf("%s = (%s || %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

        case TAC_NOT:
        if(i->b->type==SYM_ARRAY)printf("%s = ! %s[%d]", to_str(i->a, sa), to_str(i->b, sb),i->pos1);
        if(i->b->type!=SYM_ARRAY)printf("%s = ! %s", to_str(i->a, sa), to_str(i->b, sb));
		break;

		case TAC_NEG:
        if(i->b->type==SYM_ARRAY)printf("%s = - %s[%d]", to_str(i->a, sa), to_str(i->b, sb),i->pos1);
        if(i->b->type!=SYM_ARRAY)printf("%s = - %s", to_str(i->a, sa), to_str(i->b, sb));
		break;

		case TAC_COPY:
        if(i->a->type==SYM_ARRAY && i->b->type==SYM_ARRAY)printf("%s[%d] = %s[%d]", to_str(i->a, sa), i->m,to_str(i->b, sb),i->pos1);
        else if(i->a->type==SYM_ARRAY && i->b->type==SYM_PTR  && i->pos3==0)printf("%s[%d] = *%s", to_str(i->a, sa), i->m,to_str(i->b, sb));
        else if(i->a->type==SYM_ARRAY && i->b->type==SYM_PTR  && i->pos3!=0)printf("%s[%d] = *(%s + %d)", to_str(i->a, sa), i->m,to_str(i->b, sb),i->pos3);
        else if(i->a->type==SYM_ARRAY)printf("%s[%d] = %s", to_str(i->a, sa), i->m,to_str(i->b, sb));

        else if(i->a->type==SYM_PTR && i->b->type==SYM_ARRAY)printf("%s = %s", to_str(i->a, sa), to_str(i->b, sb));
        else if(i->a->type==SYM_PTR && i->b->type==SYM_VAR)printf("%s = &%s", to_str(i->a, sa), to_str(i->b, sb));

        else if(i->a->type==SYM_VAR && i->b->type==SYM_ARRAY)printf("%s = %s[%d]", to_str(i->a, sa), to_str(i->b, sb),i->pos1);
        else if(i->a->type==SYM_VAR && i->b->type==SYM_PTR && i->pos3==0)printf("%s = *%s", to_str(i->a, sa), to_str(i->b, sb));
        else if(i->a->type==SYM_VAR && i->b->type==SYM_PTR && i->pos3!=0)printf("%s = *(%s + %d)", to_str(i->a, sa), to_str(i->b, sb),i->pos3);

        else printf("%s = %s", to_str(i->a, sa), to_str(i->b, sb));
        break;

        case TAC_COPY_PTR:
        if(i->b->type==SYM_ARRAY)printf("*%s = %s[%d]", to_str(i->a, sa),to_str(i->b, sb),i->pos1);
        else if(i->b->type==SYM_PTR && i->pos3==0)printf("*%s = *%s", to_str(i->a, sa),to_str(i->b, sb));
        else if(i->b->type==SYM_PTR && i->pos3!=0)printf("*%s = *(%s + %d)", to_str(i->a, sa),to_str(i->b, sb),i->pos3);
        else printf("*%s = %s", to_str(i->a, sa),to_str(i->b, sb));
		break;

        case TAC_COPY_PTR_NEW:
        if(i->b->type==SYM_ARRAY)printf("*(%s + %d) = %s[%d]", to_str(i->a, sa),i->w,to_str(i->b, sb),i->pos1);
        else if(i->b->type==SYM_PTR && i->pos3==0)printf("*(%s + %d) = *%s", to_str(i->a, sa),i->w,to_str(i->b, sb));
        else if(i->b->type==SYM_PTR && i->pos3!=0)printf("*(%s + %d) = *(%s + %d)", to_str(i->a, sa),i->w,to_str(i->b, sb),i->pos3);
        else printf("*(%s + %d) = %s", to_str(i->a, sa),i->w,to_str(i->b, sb));
		break;

		case TAC_GOTO:
		printf("goto %s", i->a->name);
		break;

		case TAC_IFZ:
		printf("ifz %s goto %s", to_str(i->b, sb), i->a->name);
		break;

		case TAC_ACTUAL:
		printf("actual %s", to_str(i->a, sa));
		break;

		case TAC_FORMAL:
		printf("formal %s", to_str(i->a, sa));
		break;

		case TAC_CALL:
		if(i->a==NULL) printf("call %s", (char *)i->b);
		else printf("%s = call %s", to_str(i->a, sa), (char *)i->b);
		break;

		case TAC_RETURN:
		printf("return %s", to_str(i->a, sa));
		break;

		case TAC_LABEL:
		printf("label %s", i->a->name);
		break;

		case TAC_VAR:
        if (i->a->type==SYM_ARRAY){
            printf("array %s[%d]", to_str(i->a, sa),i->a->upper);
        }
        else if(i->a->type==SYM_PTR){
            printf("ptr *%s", to_str(i->a, sa));
        }
        else{
            printf("var %s", to_str(i->a, sa));
        }
		break;
        

		case TAC_BEGINFUNC:
		printf("begin");
		break;

		case TAC_ENDFUNC:
		printf("end");
		break;

		default:
		error("unknown TAC opcode");
		break;
	}

	fflush(stdout);
}
/*遍历所有的 TAC 指令并打印出它们的字符串表示*/
void tac_dump()
{
	TAC * cur;
	for(cur = tac_first; cur !=NULL; cur=cur->next)
	{
		tac_print(cur);
		printf("\n");
	}
}
/*打印错误信息并退出程序*/
void error(char *str)
{
	fprintf(stderr, "error: %s\n", str);
	exit(0);
} 