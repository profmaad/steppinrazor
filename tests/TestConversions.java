class TestConversions
{
	public static long i2l()
	{
		int i = 23;
		long l = i;

		return l;
	}
	public static long i2lneg()
	{
		int i = -23;
		long l = i;

		return l;
	}
	public static float i2f()
	{
		int i = 23;
		float f = i;

		return f;
	}
	public static float i2fneg()
	{
		int i = -23;
		float f = i;

		return f;
	}
	public static double i2d()
	{
		int i = 23;
		double d = i;

		return d;
	}
	public static double i2dneg()
	{
		int i = -23;
		double d = i;

		return d;
	}

	public static int l2i()
	{
		int o = 23;
		long l = o;
		int i = (int)l;

		return i;
	}
	public static int l2ioverflow()
	{
		long l = 1;
		l = l << 32;
		int i = (int)l;

		return i;
	}
	public static int l2ineg()
	{
		int o = -23;
		long l = o;
		int i = (int)l;

		return i;
	}
	public static float l2f()
	{
		long l = 1;
		l = l << 32;
		float f = (float)l;

		return f;
	}
	public static float l2fneg()
	{
		long l = 0;
		l -= 1;
		float f = (float)l;

		return f;
	}
	public static double l2d()
	{
		long l = 1;
		l = l << 32;
		double d = (double)l;

		return d;
	}
	public static double l2dneg()
	{
		long l = 0;
		l -= 1;
		double d = (double)l;

		return d;
	}
}