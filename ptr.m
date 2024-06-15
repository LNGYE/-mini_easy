main()
{
    # 声明
    int  a,b,c;
    int w[4];
    int *p,*q;

    # 变量赋值
    a=1;
    w[0]=1;
    b=a+1;
    c=2*b-1;
    a=b+c;

    # 指针赋值
    p=&a;  # ptr_upper=0
    q=w;   # ptr_upper=3

    *(q+1)=3;
    *(q+2)=*(q+1);
    # 数组测试
    w[0]=0;
    w[1]=a;
    w[2]=w[1];
    w[3]=*p;
    # w[3]=*(p+1); # The ptr is out of bounds
    w[3]=*(q+1)+*(q+2);
    # w[4]=2; # The array is out of bounds

    # 无偏移指针测试
    *p=2;
    *p=c;
    *p=w[1];
    # *p=w[4]; # The array is out of bounds
    *p=*(q+1);
    *p=*(q+1)+*(q+2);

    # 有偏移指针测试
    *(q+1)=2;
    *(q+1)=a;
    *(q+1)=w[0];
    *(q+1)=*(q+2);
    *(q+1)=*(q+2)+*(q+3);
    # *(q+4)=2; # The ptr is out of bounds

    # var测试
    b=a;
    b=w[1];
    b=*p;
    b=*(q+1);
    c=*(q+1)+w[1];
    c=*(q+1)+*(q+2);
}