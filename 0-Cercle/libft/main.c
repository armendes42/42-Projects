#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set);

int main(void)
{
	char *str = " aaaa  aaa bonjour  aa aaaa ccccccc  ";
	char *str2 = ft_strtrim(str, " ac");
	printf("str is %s\nstr2 is %s", str, str2);
}