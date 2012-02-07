class TestSwitch
{
	public static int tableswitch()
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
			result = -1;
			break;
		}

		return result;
	}
}