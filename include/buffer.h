/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaju <jaju@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:19:40 by jaju              #+#    #+#             */
/*   Updated: 2023/08/29 20:52:36 by jaju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

typedef unsigned int	t_uint;
typedef unsigned char	t_byte;

typedef struct s_buffer
{
	t_byte	*data;
	t_uint	type_size;
	t_uint	capacity;
	t_uint	length;
}t_buffer;

void	buffer_init(t_buffer *this, t_uint type_size, t_uint capacity);
void	buffer_push(t_buffer *this, void *data);
void	*buffer_collect(t_buffer *this, t_uint *length);

#endif
