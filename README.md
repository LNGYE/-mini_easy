#### 1. 词法分析器：mini.l->lec.yy.c           
lex mini.l

#### 2. 语法分析器：mini.y->y.tab.c、y.tab.h   
yacc -d mini.y

#### 3. 三地址码生成：tac.c、tac.h     

#### 4. 汇编代码生成：obj.c、obj.h             
gcc *.c -o test.exe

#### 5. 测试：xx.m                           
./test.exe xx.m

#### 6. 结果：xx.m.s
