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
}