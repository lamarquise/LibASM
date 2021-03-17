/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 03:54:33 by ericlazo          #+#    #+#             */
/*   Updated: 2021/03/17 19:01:06 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	test_strlen(char *s1)
{
	printf("String: |%s|\nOG strlen: |%ld|\nMY strlen: |%ld|\n\n", s1, \
			strlen(s1), ft_strlen(s1));
}

void	test_strcpy(char *src)
{
	char	dst1[100];
	char	dst2[100];

	bzero(dst1, 100);
	bzero(dst2, 100);

	printf("Pre Strcpy\nOG copy str: |%s|\nMY copy str: |%s|\n", dst1, dst2);
	printf("Post Strcpy\nOG copy str: |%s|\nMY copy str: |%s|\n\n", \
			strcpy(dst1, src), ft_strcpy(dst2, src));
}

void	test_strcmp(char *s1, char *s2)
{
	printf("String: |%s|, S2: |%s|\nOG cmp: |%d|\nMY cmp: |%d|\n\n", s1, s2, \
			strcmp(s1, s2), ft_strcmp(s1, s2));
}

void	test_write(int fd, char *str, int len)
{
	printf("String: |%s|\n", str);
	printf("\nOG write return: |%ld|\nError str: |%s|\nErrno: |%d|\n", \
			write(fd, str, len), strerror(errno), errno);
	printf("\nMY ft_write return: |%ld|\nError str: |%s|\nErrno: |%d|\n------\n\n", \
			ft_write(fd, str, len), strerror(errno), errno);
}

void	test_read(int fd1, int fd2, int len)
{
	char	buf1[100];
	char	buf2[100];

	bzero(buf1, 100);
	bzero(buf2, 100);
	if (fd1 == 1 || fd2 == 1)
		printf("---STDIN---\n");
	printf("OG read return: |%ld|\nError str: |%s|\nErrno: |%d|\n\e[1;32mBuf:\e[0m |%s|\
			\n", \
			read(fd1, buf1, len), strerror(errno), errno, buf1);
	printf("MY read return: |%ld|\nError str: |%s|\nErrno: |%d|\n\e[1;32mBuf:\e[0m |%s|\
			\n------\n\n", \
			ft_read(fd2, buf2, len), strerror(errno), errno, buf2);
}

void	test_strdup(char *s1)
{
	char	*copy1;
	char	*copy2;

	copy1 = NULL;
	copy2 = NULL;
	copy1 = strdup(s1);
	copy2 = ft_strdup(s1);
	printf("String: |%s|\nOG copy: |%s|\nMY copy: |%s|\n\n", s1, copy1, copy2);
	free(copy1);
	free(copy2);
}

int		main(void)
{
	int		fd1;
	int		fd2;
	char	*long_str = "this is an incredibly long string full of nonsense \
			asdfaskdjghasjdhf aiwuehfiuahwe fiuahwe fauhlwksefnvalu efn ailuweng\
			iuabelwrif laiuwnevailwuergnvilauernviluabhliuwe ilufvnaelisrnbgvlia\
			uebriluvbnaliwuenbvliau nlwiurnfv aliuw enlivubalwieubviluabweliu vn\
			bal;iweunrgvliuabewlirvubnaliweruhbflkjahsbdlkjfvbawliu ebvilaubwenr\
			ilufhaliuwehfliahwlei uhailuwhefri		h	 iuhfiu	h i3uh	iuh3 riu\
				h3n fi uhn3p;	unh iuhf	iugh ";
	char	*medium_str = "This is a medium String\n";
	char	*short_str = "String";
	char	*empty_str = "";
	char	*weird_str = "boo\n";

	char	*s1 = "Hello";
	char	*s2 = "word";
	char	*s3 = "hi";

	printf("\e[0;31m---------------STRLEN-------------\e[0m\n");
	test_strlen(long_str);
	test_strlen(medium_str);
	test_strlen(short_str);
	test_strlen(empty_str);
	test_strlen("abcdef\0---34567");
	test_strlen("	");
	test_strlen("      ");
	test_strlen("\ttesting ft_strlen");

	printf("\e[0;31m---------------STRCPY-------------\e[0m\n");
	test_strcpy(medium_str);
	test_strcpy(short_str);
	test_strcpy(empty_str);
	test_strcpy("abcdef\0---34567");
	test_strcpy("\0");
	test_strcpy("asdfasd\t1234123");
	test_strcpy("");

	printf("\e[0;31m---------------STRCMP-------------\e[0m\n");
	test_strcmp("","");
	test_strcmp(s1,s1);
	test_strcmp(s1,s2);
	test_strcmp(s2,s1);
	test_strcmp(s1,"");
	test_strcmp("",s1);
	test_strcmp("test\ting","");
	test_strcmp("test\ting","test\ving");
	test_strcmp("1234\0p1234","");
	test_strcmp("1234\0abcdef","");
	test_strcmp("1234\0p1234","1234\0abcdef");

	printf("\e[0;31m---------------WRITE--------------\e[0m\n");
	test_write(1, s1, strlen(s1));
	test_write(1, s1, 17);
	test_write(1, s1, 2);
	test_write(1, s1, 0);
	test_write(1, s1, -7);
	test_write(0, s1, strlen(s1));
	test_write(-1, s1, strlen(s1));
	test_write(-5, s1, strlen(s1));
	test_write(17, s1, strlen(s1));

	printf("\e[0;31m---------------READ---------------\e[0m\n");
	fd1 = open("main.c", O_RDONLY);
	fd2 = open("main.c", O_RDONLY);
	test_read(fd1, fd2, 5);
	test_read(fd1, fd2, 17);
	test_read(fd1, fd2, 1);
	test_read(fd1, fd2, 0);
	test_read(fd1, fd2, -5);
	test_read(-1, -1, -5);
	test_read(42, 42, -5);
	test_read(0, 0, -5);
	test_read(1, 1, 5);
	test_read(fd1 + 5, fd2 + 5, 5);
	test_read(STDIN_FILENO, STDIN_FILENO, -5); // not clear if this actually works...
	close(fd1);
	close(fd2);

	printf("\e[0;31m---------------STRDUP-------------\e[0m\n");
	test_strdup(s1);
	test_strdup(medium_str);
	test_strdup("");
//	test_strdup(NULL);	// expected to cause a segfault
	test_strdup("	");
	test_strdup("\t");
	test_strdup("\0");
	test_strdup("1234\0asdfasdf");


	return (0);
}


