/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaju <jaju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:25:34 by jaju              #+#    #+#             */
/*   Updated: 2023/08/31 11:24:35 by jaju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <buffer.h>
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

void	buffer_init(t_buffer *this, t_uint type_size, t_uint capacity)
{
	this->data = allocate(capacity * type_size);
	this->type_size = type_size;
	this->capacity = capacity;
	this->length = 0;
}

static
void	buffer_resize(t_buffer *this, t_uint new_capacity)
{
	t_byte*const	new = allocate(new_capacity * this->type_size);
	t_uint			i;

	i = 0;
	while (i < this->length * this->type_size
		&& i < new_capacity * this->type_size)
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

void	buffer_push(t_buffer *this, void *data)
{
	t_uint	i;

	i = 0;
	if (this->length == this->capacity)
		buffer_resize(this, this->capacity * 2);
	while (i < this->type_size)
	{
		this->data[this->length * this->type_size + i] = ((t_byte *)data)[i];
		i++;
	}
	this->length++;
}

void	*buffer_collect(t_buffer *this, t_uint *length)
{
	t_byte*const	data = allocate(this->length * this->type_size);
	t_uint			i;

	i = 0;
	while (i < this->length * this->type_size)
	{
		data[i] = this->data[i];
		i++;
	}
	if (length != (void *)0)
		*length = this->length;
	free(this->data);
	this->data = (void *)0;
	this->capacity = 0;
	this->length = 0;
	this->type_size = 0;
	return (data);
}
