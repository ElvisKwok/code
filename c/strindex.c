/*
 * The function strindex(s,t) return a index of string t in string s
 * if not found, return -1
 */

int strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++){
		for (j = i, k=0; (s[j] == t[k]) && (t[k] != '\0'); j++, k++)
			;
		if (t[k] == '\0')
			return i;
	}
	return -1;
}
