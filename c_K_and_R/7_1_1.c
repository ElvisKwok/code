#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int c;

    while ((c = getchar()) != EOF) {
        if (strcmp(argv[0], "./lower") == 0) 
            putchar(tolower(c));
        else if (strcmp(argv[0], "./upper") == 0)
            putchar(toupper(c));
        else {
            printf("wrong name of the executing file");
            break;
        }
    }
    return 0;
}
