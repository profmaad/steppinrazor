class TestLongs
{
	public static long consts()
	{
		long l;
		l = 0;
		l = 1;

		return l;
	}

	public static long add()
	{
		long l,m;
		l = 0;
		m = 1;

		return l+m+m+m;
	}

	public static long sub()
	{
		long l,m;
		l = 0;
		m = 1;

		return l-m-m-m;
	}
	public static long mul()
	{
		long l,m;

		l = 1;
		l += 1;
		m = 1;
		m += 1;
		m += 1;

		return l*m;
	}
	public static long mulneg()
	{
		long l,m;

		l = 0;
		l -= 1;
		m = 1;
		m += 1;
		m += 1;

		return l*m;
	}
	public static long div()
	{
		long l,m;
		
		l = 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		m = 1;
		m += 1;

		return l/m;
	}
	public static long divfrac()
	{
		long l,m;
		
		l = 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		m = 1;
		m += 1;

		return l/m;
	}
	public static long divfraczero()
	{
		long l,m;

		l = 1;
		l += 1;
		m = 1;
		m += 1;
		m += 1;

		return l/m;
	}
	public static long divneg()
	{
		long l,m;

		l = 1;
		l += 1;
		l += 1;
		m = 0;
		m -= 1;

		return l/m;
	}
	public static long rem()
	{
		long l,m;

		l = 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;

		m = 1;
		m += 1;
		m += 1;
		m += 1;

		return l%m;
	}
	public static long remzero()
	{
		long l,m;

		l = 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;

		m = 1;
		m += 1;
		m += 1;

		return l%m;
	}
	public static long remneg()
	{
		long l,m;

		l = 0;
		l -= 1;
		l -= 1;
		l -= 1;
		l -= 1;
		l -= 1;
		l -= 1;
		l -= 1;
		l -= 1;
		l -= 1;

		m = 1;
		m += 1;
		m += 1;
		m += 1;

		return l%m;
	}
	public static long remneg2()
	{
		long i,j;

		long l,m;

		l = 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;
		l += 1;

		m = 0;
		m -= 1;
		m -= 1;
		m -= 1;
		m -= 1;

		return l%m;
	}

	public static long neg()
	{
		long l;

		l = 1;
		l = -l;

		return l;
	}
	public static long negneg()
	{
		long l;

		l = 0;
		l -= 1;
		l = -l;

		return l;
	}
	public static long shl()
	{
		long l;

		l = 1;
		l = l << 32;

		return l;
	}
	public static long shlneg()
	{
		long l;

		l = 0;
		l -= 1;
		l = l << 32;

		return l;
	}
	public static long shr()
	{
		long l;

		l = 1;
		l = l << 33;
		l = l >> 32;

		return l;
	}
	public static long shrneg()
	{
		long l;

		l = 0;
		l -= 1;
		l = l << 33;
		l = l >> 32;

		return l;
	}
	public static long ushr()
	{
		long l;

		l = 1;
		l = l << 33;
		l = l >>> 32;

		return l;
	}
	public static long ushrneg()
	{
		long l;

		l = 0;
		l -= 1;
		l = l << 33;
		l = l >>> 32;

		return l;
	}

	public static long and()
	{
		long l,m;

		l = 1;
		l += 1;
		l += 1;
		l = l << 5;
		
		m = 1;
		m = m << 5;

		l = l & m;

		return l;
	}
	public static long andneg()
	{
		long l,m;

		l = 0;
		l -= 1;

		m = 1;
		m = m << 6;

		l = l & m;

		return l;
	}
}