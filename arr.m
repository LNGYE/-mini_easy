main()
{
    char a,b,c,d;
    char w[2];
    w[0]='a';
    w[1]='b';
	b = 'b';
    c = 'c';
    a = 'a';
    d = 'd';
    if ( (a==w[0]) && (b==w[1]) ) { a = 'm' ; }
    if ( (b==w[0]) || (a==w[1]) ) { a = 'm' ; }
    if ( !d ) { a = 6 ; }
}