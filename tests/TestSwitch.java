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
}