
#include <libasm.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int		ft_strlen(char const *str);
char	*ft_strcpy(char *dst, char const *src);
int		ft_strcmp(char const *s1, char const *s2);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
ssize_t	ft_read(int fd, void *buf, size_t nbyte);
char	*ft_strdup(char const *s1);
int		hello_world();


// kinda useless in the long run
char	*ft_bmalloc(char *str)
{
	int		i;
	int		l;
	char	*ret;

	i = 0;
	l = strlen(str);
	if (!(ret = malloc(sizeof(char) * (l + 1))))
		return (NULL);
	while (i < l)
	{
		ret[i] = '\0';
		++i;
	}
	return (ret);
}


	// will need to change for submit so that all run at the same time, and always
	// compare to OG function

int		main(int ac, char **av)
{
	char	*s1;
	char	*s2;
	char	*dst;

	if (ac == 4)
	{
		s2 = av[3];
		s1 = av[2];
	}
	else
		s2 = strdup("b test");
	

	if (ac == 3)
		s1 = av[2];
	else if (ac < 3)
		s1 = strdup("a test");
//	if (!(s2 = ft_bmalloc(s1)))
//		return (0);

	if (ac >= 2)
	{
		if (atoi(av[1]) == 1)	// strlen
		{
			printf("Ft_strlen, String: |%s|, og len: %ld, my len: %d\n", \
				s1, strlen(s1), ft_strlen(s1));
		}
		else if (atoi(av[1]) == 2)	// strcpy
		{
			if (!(dst = ft_bmalloc(s1)))
				return (0);
			printf("Ft_strcpy\nBefore src: |%s|, dst: |%s|\n", s1, dst);
			dst = ft_strcpy(dst, (const char*)s1);
			printf("After src: |%s|, dst: |%s|\n", s1, dst);
		}
		else if (atoi(av[1]) == 3)	// strcmp
		{
			printf("Comparing s1: |%s| and s2: |%s|\n", s1, s2);
			printf("Ft_strcmp, og dif: %d, my dif: %d\n", strcmp(s1, s2), ft_strcmp(s1, s2));
		}
		else if (atoi(av[1]) == 4)	// write
		{
			printf("Ft_write\n");
			if (ac == 2)
			{
				printf("---------------WRITE--------------\n");
				printf("%ld\n", ft_write(11, "Hello, world\n", 4));
				printf("%s %d\n", strerror(errno), errno);
				printf("%ld\n", write(11, "Hello, world\n", 4));
				printf("%s %d\n", strerror(errno), errno);

				//printf("|[%li]****\n", ft_write(1, "Mine aight", -10));
				//printf("|[%li]****\n", write(1, "OG one ok.", -10));
				//write(1, "OG here i am\n", -5);
				//ft_write(1, "ME here i am\n", -5);
			}
			else if (ac == 3)
			{
				write(1, "OG:|", 4);
				write(1, av[2], strlen(av[2]));
				write(1, "|\nMine:|", 8);
				ft_write(1, av[2], strlen(av[2]));
				write(1, "|\n", 2);
			}
		}
		else if (atoi(av[1]) == 5)	// read
		{
			printf("Ft_read\n");

		}
		else if (atoi(av[1]) == 6)	// strdup
		{
		// This is not at all secure...
			printf("Ft_strdup, s1: |%s|\n", s1);
			printf("OG ret: |%s|\n", strdup(s1));
			printf("My ret: |%s|\n", ft_strdup(s1));

		}
//		else if (atoi(av[1]) == 7)	// atoi_base
//		{
//			printf("Ft_atoi_base\n");
//
//
//		}
		else if (atoi(av[1]) == 8)	// list_push_front
		{
			printf("Ft_list_push_front\n");


		}
		else if (atoi(av[1]) == 9)	// list_size
		{
			printf("Ft_list_size\n");


		}
		else if (atoi(av[1]) == 10)	// list_sort
		{
			printf("Ft_list_sort\n");


		}
//		else if (atoi(av[1]) == 11)	// list_remove_if
//		{
//			printf("Ft_list_remove_if\n");
//
//
//		}
		else if (atoi(av[1]) == 12)	// hello world
		{
			printf("Now calling hello_world:\n");
			printf("ret: %d\n", hello_world());

		}
		else
			printf("Usage: ./test <function #> <function inputs>\n");
	}
	else
		printf("Usage: ./test <function #> <function inputs>\n");

	if (ac < 2)
		free(s1);
	if (ac < 3)
		free(s2);
	return (1);
}


