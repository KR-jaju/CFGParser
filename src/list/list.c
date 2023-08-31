/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaju <jaju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:19:18 by jaju              #+#    #+#             */
/*   Updated: 2023/08/31 11:27:11 by jaju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>
#include <stdlib.h>

typedef unsigned char	t_byte;

static
void	*allocate(t_uint size)
{
	t_byte*const	ptr = malloc(size);
	t_uint			i;

	i = 0;
	if (ptr == (void *)0)
		exit(1);
	while (i < size)
	{
		ptr[i] = (t_byte)0;
		i++;
	}
	return (ptr);
}

static
void	list_resize(t_list *this, t_uint new_capacity)
{
	t_byte*const	new = allocate(new_capacity * sizeof(void *));
	t_uint			i;

	i = 0;
	while (i < this->length && i < new_capacity)
	{
		new[i] = this->data[i];
		i++;
	}
	free(this->data);
	this->data = new;
	if (this->length < new_capacity)
		this->length = new_capacity;
	this->capacity = new_capacity;
}

void	list_init(t_list *this, t_uint capacity)
{
	this->data = allocate(capacity * sizeof(void *));
	this->capacity = capacity;
	this->length = 0;
}

void	list_add(t_list *this, void *data)
{
	t_uint	i;

	i = 0;
	if (this->length == this->capacity)
		list_resize(this, this->capacity * 2);
	this->data[this->length] = data;
	this->length++;
}

void	*list_get(t_list *list, int idx)
{
	return (list->data[idx]);
}
