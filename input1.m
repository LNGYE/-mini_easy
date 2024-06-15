main()
{
    char a, b, c, d;
    int  e, f, g, h;
    a = 'a';
    b = 'B';
    e = 1;
    f = 2;
    g = e + f;
    h = f * g;

    c = 'C' + e;
    d = a - f;

    c = (c + d) + (g - h);
    e = (a > b);
    f = (e != f);
    g = (c == d);

    if(a < b)
	{ 
		print(a,"<",b); 
	}
    if(c != d)
	{ 
		print(c,"!=",d); 
	}
}