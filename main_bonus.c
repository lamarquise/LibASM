
#include "libasm_bonus.h"

void	print_list(t_list *lst)
{
	printf("List Size: %d\n", ft_list_size(lst));
	while(lst)
	{
		printf("%s\n", (char*)lst->data);
		lst = lst->next;
	}
	write(1, "\n", 1);
}

int		main(void)
{
	t_list	*list;

		// may want to expand the types of things we try to put in the list
	list = NULL;
	print_list(list);
	ft_list_push_front(&list, ft_strdup("1st elem"));
	print_list(list);
	ft_list_push_front(&list, ft_strdup("2nd elem"));
	print_list(list);
	ft_list_push_front(&list, ft_strdup("3rd elem"));
	print_list(list);
	ft_list_push_front(&list, ft_strdup("4th elem"));
	print_list(list);
	ft_list_push_front(&list, ft_strdup("5th elem"));
	print_list(list);

	return (0);
}
