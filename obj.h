/* register 寄存器的标识符*/
#define R_UNDEF -1
#define R_FLAG 0 // 标志位
#define R_IP 1   // 指令指针 IP
#define R_BP 2   // 基址指针 BP
#define R_JP 3   // 跳转指针 JP
#define R_TP 4   // 临时结果 TP
#define R_GEN 5    /*R_GEN 表示通用寄存器的起始索引5~15*/
#define R_NUM 16  /*R_NUM 是寄存器总数*/

// 精简指令集，每条指令占8个字节，分为4个字段
/* frame */
#define FORMAL_OFF -4 	/* first formal parameter 第一个形式参数的偏移*/
#define OBP_OFF 0 		/* dynamic chain 动态链（帧指针）的偏移*/
#define RET_OFF 4 		/* ret address 返回地址的偏移*/
#define LOCAL_OFF 8 		/* local var 局部变量的偏移*/

/*表示寄存器中的变量是否已被修改*/
#define MODIFIED 1
#define UNMODIFIED 0

/*rdesc 结构体描述了每个寄存器的状态，包括寄存器中存储的变量及其修改状态*/
struct rdesc /* Reg descriptor */
{
	struct sym *var; /* 指向在寄存器中的变量 */
	int modified; /* If needs spilling 是否需要写回内存的标志*/
    int m; /*数组偏移量*/
    int w; /*指针偏移量*/
    int pos1; /*数组偏移量*/
    int pos2; /*数组偏移量*/
    int pos3; /*指针偏移量*/
    int pos4; /*指针偏移量*/
    int offset;
    struct sym *p;
};

extern int tos;  /* 静态数据段的顶端 */
extern int tof;  /* 当前帧的顶端 */
extern int oof;  /* 形式参数的偏移 */
extern int oon;  /* 下一个帧的偏移 */

void tac_obj();

