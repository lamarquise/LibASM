/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:00:37 by ericlazo          #+#    #+#             */
/*   Updated: 2021/03/17 19:00:39 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	clear_list(t_list **list)
{
	t_list	*tmp;

	tmp = NULL;
	if (!list)
		return;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->data);
		free(*list);
		*list = tmp;
	}
}

int		main(void)
{
	t_list	*list;
	char	*bad;

	bad = ft_strdup("bad_elem");

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
	ft_list_push_front(&list, ft_strdup(""));
	print_list(list);
	ft_list_push_front(&list, NULL);
	print_list(list);
	ft_list_push_front(&list, ft_strdup("5th elem"));
	print_list(list);
	ft_list_push_front(NULL, bad);
	print_list(list);

	clear_list(&list);
	print_list(list);
	free(bad);
	return (0);
}
