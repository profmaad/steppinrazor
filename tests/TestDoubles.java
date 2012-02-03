class TestDoubles
{
	public static double consts()
	{
		double d;
		d = 0;
		d = 1;

		return d;
	}

	public static double add()
	{
		double d,e,f;

		d = 0;
		e = 1;
		f = 1;

		return e+e+e+e+e+e+e+e+e+e+e+e+e+e+e+e+e+e+e+e+e+e+f;
	}
	public static double sub()
	{
		double d,e;

		d = 0;
		e = 1;

		return d-e-e-e;
	}
	public static double mul()
	{
		double f,g;

		f = 1;
		f += 1;
		g = 1;
		g += 1;
		g += 1;

		return f*g;
	}
	public static double mulneg()
	{
		double f,g;

		f = 1;
		f += 1;
		f += 1;
		g = 0;
		g -= 1;

		return f*g;
	}
	public static double div()
	{
		double f,g;

		f = 1;
		f += 1;
		f += 1;
		g = 1;
		g += 1;

		return f/g;
	}
	public static double divneg()
	{
		double f,g;

		f = 1;
		f += 1;
		f += 1;
		g = 0;
		g -= 1;
		g -= 1;

		return f/g;
	}
}