class TestFloats
{
	public static float consts()
	{
		float f;
		f = 0;
		f = 1;
		f = 2;

		return f;
	}

	public static float add()
	{
		float f,g,h;

		f = 0;
		g = 1;
		h = 2;

		return f+g+h;
	}
	public static float sub()
	{
		float f,g,h;
		f = 0;
		g = 1;
		h = 2;

		return f-g-h;
	}
	public static float mul()
	{
		float f,g;

		f = 2;
		g = 2;
		g += 1;

		return f*g;
	}
	public static float mulneg()
	{
		float f,g;

		f = 2;
		f += 1;
		g = 0;
		g -= 1;

		return f*g;
	}
	public static float div()
	{
		float f,g;

		f = 2;
		f += 1;
		g = 2;

		return f/g;
	}
	public static float divneg()
	{
		float f,g;

		f = 2;
		f += 1;
		g = 0;
		g -= 1;
		g -= 1;

		return f/g;
	}
}