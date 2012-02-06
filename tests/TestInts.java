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
	public static int div()
	{
		int i,j;

		i = 9;
		j = 3;

		return i/j;
	}
	public static int divneg()
	{
		int i,j;

		i = 23;
		j = -1;
		
		return i/j;
	}
	public static int divneg2()
	{
		int i,j;

		i = 9;
		j = -4;
		
		return i/j;
	}	
	public static int divfrac()
	{
		int i,j;

		i = 23;
		j = 2;

		return i/j;
	}
	public static int divfraczero()
	{
		int i,j;

		i = 2;
		j = 3;

		return i/j;
	}
	public static int rem()
	{
		int i,j;

		i = 9;
		j = 4;
		
		return i%j;
	}
	public static int remzero()
	{
		int i,j;

		i = 9;
		j = 3;

		return i%j;
	}
	public static int remneg()
	{
		int i,j;

		i = -9;
		j = 4;

		return i%j;
	}
	public static int remneg2()
	{
		int i,j;

		i = 9;
		j = -4;

		return i%j;
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

	public static int neg()
	{
		int i;

		i = 23;
		i = -i;

		return i;
	}
	public static int negneg()
	{
		int i;

		i = -23;
		i = -i;

		return i;
	}

	public static int shl()
	{
		int i;

		i = 1;
		i = i << 30;

		return i;
	}
	public static int shlneg()
	{
		int i;

		i = -1;
		i = i << 30;

		return i;
	}
	public static int shr()
	{
		int i;

		i = 1;
		i = i << 30;
		i = i >> 29;

		return i;
	}
	public static int shrneg()
	{
		int i;

		i = -1;
		i = i << 30;
		i = i >> 29;

		return i;
	}
	public static int ushr()
	{
		int i;

		i = 1;
		i = i << 30;
		i = i >>> 29;

		return i;
	}
	public static int ushrneg()
	{
		int i;

		i = -1;
		i = i << 30;
		i = i >>> 29;

		return i;
	}

	public static int and()
	{
		int i;

		i = 64+32+16+8+4+2+1;
		i = i & 0x40;

		return i;
	}
	public static int andneg()
	{
		int i;

		i = -64-32-16-8-4-2-1;
		i = i & 0xf0;

		return i;
	}
}