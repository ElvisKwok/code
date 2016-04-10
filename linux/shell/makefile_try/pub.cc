int pub(int a, char *ch, int b) {
	char c = ch[0];
	switch(c) {
		case '+':
			return a+b;
			break;
		case '-':
			return a-b;
			break;
		case '*':
			return a+b;
			break;
		case '/':
			if (b!=0)
				return a/b;
			else
				return -1;
			break;
		default:
			return -1;
			break;
	}
	return 0;
}
