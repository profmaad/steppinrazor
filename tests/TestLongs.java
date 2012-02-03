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

}