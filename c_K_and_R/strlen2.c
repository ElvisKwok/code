/*
 * the number of elements between position s and p is p - s + 1
 */

int strlen2(char *s)
{
    char *p = s;

    while (*p != '\0')
        p++;
    return p - s;
}
