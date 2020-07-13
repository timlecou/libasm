#include "libasm.h"
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE	 "\033[36m"
# define YELLOW  "\033[33m"
# define BUFFER_SIZE 512

int		strlen_test(char *str)
{
	int 	ret1;
	int 	ret2;

	ret1 = ft_strlen(str);
	ret2 = strlen(str);
	printf("\nTEST : " BLUE "[%s]" RESET "\n", str);
	printf("strlen : " YELLOW "[%d]" RESET "\nft_strlen : " YELLOW "[%d]" RESET "\n", ret1, ret2);
	if (ret1 == ret2)
		printf("" GREEN "	==>[OK] \n" RESET "");
	else
		printf("" RED "	==>[KO] \n" RESET "");
	return (1);
}

int		strcpy_test(char *src)
{
	char	dest1[BUFFER_SIZE];
	char	dest2[BUFFER_SIZE];

	bzero(dest1, BUFFER_SIZE);
	bzero(dest2, BUFFER_SIZE);
	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	printf("\nTEST : " BLUE "[%s]" RESET "\n", src);
	printf("strcpy : " YELLOW "[%s]" RESET "\nft_strcpy : " YELLOW "[%s]" RESET "\n", dest1, dest2);
	if (!strcmp(dest1, dest2))
		printf("" GREEN "	==>[OK] \n" RESET "");
	else
		printf("" RED "	==>[KO] \n" RESET "");
	return (1);
}

int		strcmp_test(char *s1, char *s2)
{
	int 	ret1;
	int 	ret2;

	ret1 = ft_strcmp(s1, s2);
	ret2 = strcmp(s1, s2);
	printf("\nTEST : " BLUE "[%s]" RESET " && " BLUE "[%s]" RESET "\n", s1, s2);
	printf("strcmp : " YELLOW "[%d]" RESET "\nft_strcmp : " YELLOW "[%d]" RESET "\n", ret1, ret2);
	if ((ret1 > 0 && ret2 > 0) || (ret1 < 0 && ret2 < 0) || (ret1 == 0 && ret2 == 0))
		printf("" GREEN "	==>[OK] " RESET "\n");
	else
		printf("" RED "	==>[KO] " RESET "\n");
	return (1);
}

int		write_test(char *str)
{
	int		ft_write_pipe[2];
	char	buf[BUFFER_SIZE];
	int		ret;

	bzero(buf, BUFFER_SIZE);
	if (pipe(ft_write_pipe) < 0)
		exit(EXIT_FAILURE);
	fcntl(ft_write_pipe[0], F_SETFL, O_NONBLOCK);
	ft_write(ft_write_pipe[1], str, strlen(str));
	ret = read(ft_write_pipe[0], buf, BUFFER_SIZE);
	buf[ret] = '\0';

	printf("\nTEST : " BLUE "[%s]" RESET "\n", str);
	if (!strcmp(buf, str))
		printf("" GREEN "	==>[OK] " RESET "");
	else
		printf("" RED "	==>[KO] " RESET "");
	close(ft_write_pipe[1]);
	close(ft_write_pipe[0]);
	return (1);
}

int		read_test(char *str)
{
	int		ft_read_pipe[2];
	char	buf[BUFFER_SIZE];
	int		ret;

	bzero(buf, BUFFER_SIZE);
	if (pipe(ft_read_pipe) < 0)
		exit(EXIT_FAILURE);
	fcntl(ft_read_pipe[0], F_SETFL, O_NONBLOCK);
	write(ft_read_pipe[1], str, strlen(str));
	ret = ft_read(ft_read_pipe[0], buf, BUFFER_SIZE);
	buf[ret] = '\0';

	printf("\nTEST : " BLUE "[%s]" RESET "\n", str);
	if (!strcmp(buf, str))
		printf("" GREEN "	==>[OK] " RESET "");
	else
		printf("" RED "	==>[KO] " RESET "");
	close(ft_read_pipe[1]);
	close(ft_read_pipe[0]);
	return (1);
}

int		strdup_test(char *str)
{
	char	*str1;
	char	*str2;

	str1 = ft_strdup(str);
	str2 = strdup(str);
	printf("\nTEST : " BLUE "[%s]" RESET "\n", str);
	printf("strdup : " YELLOW "[%s]" RESET "\nft_strdup : " YELLOW "[%s]" RESET "\n", str1, str2);
	if (!strcmp(str1, str2))
		printf("" GREEN "	==>[OK] " RESET "");
	else
		printf("" RED "	==>[KO] " RESET "");
	free(str1);
	free(str2);
	return (1);
}

int		main(void)
{
	/*
	** FT_STRLEN
	*/
	printf("" BLUE "---{FT_STRLEN}---" RESET "\n");
	strlen_test("allo");
	strlen_test("");
	strlen_test("on test tout ce qu'on peut mon gars");
	strlen_test("allo \0 mon gars");
	strlen_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	strlen_test("        ");
	printf("\n\n");

	/*
	** FT_STRCPY
	*/
	printf("" BLUE "---{FT_STRCPY}---" RESET "\n");
	strcpy_test("abc");
	strcpy_test("");
	strcpy_test("allo mon gars");
	strcpy_test("allo \0 mon gars");
	strcpy_test("ca fou koi allo");
	strcpy_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	strcpy_test("        ");
	printf("\n\n");

	/*
	** FT_STRCMP
	*/
	printf("" BLUE "---{FT_STRCMP}---" RESET "\n");
	strcmp_test("allo", "allo");
	strcmp_test("abcdef", "zcdef");
	strcmp_test("", "wtf");
	strcmp_test("on test tout ce qu'on peut mon gars", "   ");
	strcmp_test("", "");
	strcmp_test("beta", "");
	strcmp_test("te\0", "\0");
	strcmp_test("\xff\xff", "\xff\xff");
	strcmp_test("\xff\x80", "\xff\x00");
	strcmp_test("\xff\xfe", "\xff");
	strcmp_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, ed pulvinar nullam.", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	printf("\n\n");

	/*
	** FT_WRITE
	*/
	printf("" BLUE "---{FT_WRITE}---" RESET "\n");
	write_test("");
	write_test("test");
	write_test("test allo");
	write_test("test allo \0 what");
	printf("\n\n");

	/*
	** FT_READ
	*/

	printf("" BLUE "---{FT_READ}---" RESET "\n");
	read_test("allo");
	read_test("allo mon gars");
	read_test("allo \0 mon bars");
	read_test("");
	read_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	printf("\n\n");

	/*
	** FT_STRDUP
	*/
	printf("" BLUE "---{FT_STRDUP}---" RESET "\n");
	strdup_test("allo");
	strdup_test("allo wtf");
	strdup_test("");
	strdup_test("allo \0 mon bars");
	strdup_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	printf("\n");

}
