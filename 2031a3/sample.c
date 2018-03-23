#include <stdio.h>

char *strcat(char *s1, const char *s2);

int main(void) 
{
	char s1[] = "hello world ";
	char s2[] = "good bye";
	//printf("%s", s1);
	//printf("%s", s2);
	char* output = strcat(s1, s2);
	printf("The output of %s and %s is %s.\n", s1, s2, output);
}

char *strcat(char *s1, const char *s2)
{
	char *p = s1;

	while (*p != '\0')
		p++;
	while (*s2 != '\0')
	{
		*p = *s2;
		p++;
		s2++;
	}
	*p = '\0';
	return s1;
}
