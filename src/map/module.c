/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaju <jaju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:20:48 by jaju              #+#    #+#             */
/*   Updated: 2023/08/31 12:34:09 by jaju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>
#include <str.h>

void	map_init(t_map *this)
{
	this->entries = (void *)0;
}

void	*map_get(t_map *this, const char *key)
{
	t_entry	*entry;

	entry = this->entries;
	while (entry != (void *)0)
	{
		if (str_equals(entry->key, key))
			break ;
		entry = entry->next;
	}
	if (entry == (void *)0)
		return ((void *)0);
	return (entry->value);
}

void	map_put(t_map *this, const char *key, void *value)
{
	t_entry	**entry;

	entry = &this->entries;
	while (*entry != (void *)0)
	{
		if (str_equals((*entry)->key, key))
			break ;
		entry = &(*entry)->next;
	}
	if (*entry != (void *)0)
		return ((*entry)->value = value, (void)0);
	*entry = allocate(sizeof(t_entry));
	entry_init(*entry);
	(*entry)->key = str_clone(key);
	(*entry)->value = value;
}
