class TestComparisons
{
	public static boolean lcmpequal()
	{
		long l = 1;
		long m = 1;

		return l==m;
	}
	public static boolean lcmpless()
	{
		long l = 1;
		long m = 1;
		m += 1;

		return l < m;
	}
	public static boolean lcmpgreater()
	{
		long l = 1;
		l += 1;
		long m = 1;

		return l > m;
	}

	public static boolean ifeq()
	{
		int i = 0;

		return i!=0;
	}
	public static boolean ifne()
	{
		int i = 0;

		return i==0;
	}
	public static boolean iflt()
	{
		int i = 0;

		return i>=0;
	}
	public static boolean ifge()
	{
		int i = 0;

		return i<0;
	}
	public static boolean ifgt()
	{
		int i = 0;

		return i<=0;
	}
	public static boolean ifle()
	{
		int i = 0;

		return i>0;
	}

	public static boolean fcmpequal()
	{
		float f = 1;
		float g = 1;

		return f==g;
	}
	public static boolean fcmpless()
	{
		float f = 1;
		float g = 1;
		g += 1;

		return f<g;
	}
	public static boolean fcmpgreater()
	{
		float f = 1;
		f += 1;
		float g = 1;

		return f>g;
	}

	public static boolean dcmpequal()
	{
		double f = 1;
		double g = 1;

		return f==g;
	}
	public static boolean dcmpless()
	{
		double f = 1;
		double g = 1;
		g += 1;

		return f<g;
	}
	public static boolean dcmpgreater()
	{
		double f = 1;
		f += 1;
		double g = 1;

		return f>g;
	}

	public static boolean if_icmpeq()
	{
		int i = 23;
		int j = 42;
		
		return i!=j;
	}
	public static boolean if_icmpne()
	{
		int i = 23;
		int j = 23;
		
		return i==j;
	}
	public static boolean if_icmplt()
	{
		int i = 23;
		int j = 42;
		
		return j>=i;
	}
	public static boolean if_icmpge()
	{
		int i = 23;
		int j = 42;
		
		return i<j;
	}
	public static boolean if_icmpgt()
	{
		int i = 23;
		int j = 23;
		
		return i<=j;
	}
	public static boolean if_icmple()
	{
		int i = 42;
		int j = 23;
		
		return i>j;
	}

	public static boolean if_acmpeq()
	{
		Object a = null;
		Object b = null;

		return a!=b;
	}
	public static boolean if_acmpne()
	{
		Object a = null;
		Object b = null;

		return a==b;
	}
}
