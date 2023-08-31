/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaju <jaju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:17:44 by jaju              #+#    #+#             */
/*   Updated: 2023/08/31 11:27:23 by jaju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef unsigned int	t_uint;

typedef struct s_list
{
	void	**data;
	t_uint	capacity;
	t_uint	length;
}t_list;

void	list_init(t_list *list, t_uint capacity);
void	list_add(t_list *list, void *data);
void	*list_get(t_list *list, int idx);

#endif
