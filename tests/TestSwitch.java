class TestSwitch
{
	public static int tableswitch1()
	{
		int s, result;

		s = 0;

		switch(s)
		{
		case 0:
			result = 23;
			break;
		case 1:
			result = 42;
			break;
		case 2:
			result = 7;
			break;
		case 3:
			result = 666;
			break;
		default:
			result = -23;
			break;
		}

		return result;
	}
	public static int tableswitch2()
	{
		int s, result;

		s = 3;

		switch(s)
		{
		case 0:
			result = 23;
			break;
		case 1:
			result = 42;
			break;
		case 2:
			result = 7;
			break;
		case 3:
			result = 666;
			break;
		default:
			result = -23;
			break;
		}

		return result;
	}
	public static int tableswitch3()
	{
		int s, result;

		s = 1;

		switch(s)
		{
		case 0:
			result = 23;
			break;
		case 1:
			result = 42;
			break;
		case 2:
			result = 7;
			break;
		case 3:
			result = 666;
			break;
		default:
			result = -23;
			break;
		}

		return result;
	}
	public static int tableswitchdefault()
	{
		int s, result;

		s = 99;

		switch(s)
		{
		case 0:
			result = 23;
			break;
		case 1:
			result = 42;
			break;
		case 2:
			result = 7;
			break;
		case 3:
			result = 666;
			break;
		default:
			result = -23;
			break;
		}

		return result;
	}

	public static int lookupswitch1()
	{
		int s, result;

		s = 22;

		switch(s)
		{
		case 22:
			result = 23;
			break;
		case -5:
			result = 42;
			break;
		case 666:
			result = 7;
			break;
		case 0:
			result = 555;
			break;
		case -24:
			result = -42;
			break;
		default:
			result = -23;
			break;
		}

		return result;
	}
	public static int lookupswitch2()
	{
		int s, result;

		s = -5;

		switch(s)
		{
		case 22:
			result = 23;
			break;
		case -5:
			result = 42;
			break;
		case 666:
			result = 7;
			break;
		case 0:
			result = 555;
			break;
		case -24:
			result = -42;
			break;
		default:
			result = -23;
			break;
		}

		return result;
	}
	public static int lookupswitch3()
	{
		int s, result;

		s = 666;

		switch(s)
		{
		case 22:
			result = 23;
			break;
		case -5:
			result = 42;
			break;
		case 666:
			result = 7;
			break;
		case 0:
			result = 555;
			break;
		case -24:
			result = -42;
			break;
		default:
			result = -23;
			break;
		}

		return result;
	}
	public static int lookupswitch4()
	{
		int s, result;

		s = 0;

		switch(s)
		{
		case 22:
			result = 23;
			break;
		case -5:
			result = 42;
			break;
		case 666:
			result = 7;
			break;
		case 0:
			result = 555;
			break;
		case -24:
			result = -42;
			break;
		default:
			result = -23;
			break;
		}

		return result;
	}
	public static int lookupswitch5()
	{
		int s, result;

		s = -24;

		switch(s)
		{
		case 22:
			result = 23;
			break;
		case -5:
			result = 42;
			break;
		case 666:
			result = 7;
			break;
		case 0:
			result = 555;
			break;
		case -24:
			result = -42;
			break;
		default:
			result = -23;
			break;
		}

		return result;
	}
	public static int lookupswitchdefault()
	{
		int s, result;

		s = 65;

		switch(s)
		{
		case 22:
			result = 23;
			break;
		case -5:
			result = 42;
			break;
		case 666:
			result = 7;
			break;
		case 0:
			result = 555;
			break;
		case -24:
			result = -42;
			break;
		default:
			result = -23;
			break;
		}

		return result;
	}
}