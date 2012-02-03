class TestInts
{
	public static int consts()
	{
		int i;
		i = -1;
		i = 0;
		i = 1;
		i = 2;
		i = 3;
		i = 4;
		i = 5;

		return i;
	}

	public static int add()
	{
		int i,j;
		
		i = 23;
		j = 42;
		
		int x = i+j;

		return x;
	}
	public static int sub()
	{
		int i,j,k;
		
		i = 23;
		j = 42;
		k = -4;

		return i-j-k;
	}
	public static int mul()
	{
		int i,j;

		i = 23;
		j = 3;
		
		return i*j;
	}
	public static int mulneg()
	{
		int i,j;

		i = 23;
		j = -1;

		return i*j;
	}

	public static int negative()
	{
		int i,j;

		i = 23;
		j = -42;

		return i+j;
	}

	public static int locals()
	{
		int a,b,c,d,e,f,g,h,i,j,k;

		i = 23;
		j = 42;
		k = -24;

		return i+j+k;
	}
}