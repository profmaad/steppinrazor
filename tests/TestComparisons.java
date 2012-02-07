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
}