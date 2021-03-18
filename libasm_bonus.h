/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:00:26 by ericlazo          #+#    #+#             */
/*   Updated: 2021/03/17 19:00:30 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

# include "libasm.h"

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

void				ft_list_push_front(t_list **begin_list, void *data);
int					ft_list_size(t_list *begin_list);

#endif
