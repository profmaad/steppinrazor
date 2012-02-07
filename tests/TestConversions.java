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
	
	public static int f2i()
	{
		float f = 2;
		int i = (int)f;

		return i;
	}
	public static int f2ineg()
	{
		float f = 0;
		f -= 2;
		int i = (int)f;

		return i;
	}
	public static int f2itruncate()
	{
		float f = 2;
		f += 1;
		float g = 2;
		f = f/g;
		int i = (int)f;

		return i;
	}
	public static long f2l()
	{
		float f = 2;
		long l = (long)f;

		return l;
	}
	public static long f2lneg()
	{
		float f = 0;
		f -= 2;
		long l = (long)f;

		return l;
	}
	public static long f2ltruncate()
	{
		float f = 2;
		f += 1;
		float g = 2;
		f = f/g;
		long l = (long)f;

		return l;
	}
	public static double f2d()
	{
		float f = 2;
		double d = (double)f;

		return d;
	}
	public static double f2dneg()
	{
		float f = 0;
		f -= 2;
		double d = (double)f;

		return d;
	}
	public static double f2dfrac()
	{
		float f = 2;
		f += 1;
		float g = 2;
		f = f/g;

		double d = (double)f;

		return d;
	}

	public static int d2i()
	{
		double d = 1;
		int i = (int)d;

		return i;
	}
	public static int d2ineg()
	{
		double d = 0;
		d -= 1;
		int i = (int)d;

		return i;
	}
	public static int d2itruncate()
	{
		double d = 1;
		d += 1;
		d += 1;
		double e = 1;
		e += 1;
		d = d/e;
		int i = (int)d;

		return i;
	}
	public static long d2l()
	{
		double d = 1;
		long l = (long)d;

		return l;
	}
	public static long d2lneg()
	{
		double d = 0;
		d -= 1;
		long l = (long)d;

		return l;
	}
	public static long d2ltruncate()
	{
		double d = 1;
		d += 1;
		d += 1;
		double e = 1;
		e += 1;
		d = d/e;
		long l = (long)d;

		return l;
	}
	public static double d2f()
	{
		double d = 1;
		float f = (float)d;

		return f;
	}
	public static double d2fneg()
	{
		double d = 0;
		d -= 1;
		float f = (float)d;

		return f;
	}
	public static double d2ffrac()
	{
		double d = 1;
		d += 1;
		d += 1;
		double e = 1;
		e += 1;
		d = d/e;

		float f = (float)d;

		return f;
	}
}
