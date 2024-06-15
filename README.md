词法分析器：mini.l->lec.yy.c           # lex mini.l
语法分析器：mini.y->y.tab.c、y.tab.h   # yacc -d mini.y
三地址码生成：tac.c、tac.h             
汇编代码生成：obj.c、obj.h             # gcc *.c -o test.exe
测试：xx.m                            # ./test.exe xx.m
结果：xx.m.s
