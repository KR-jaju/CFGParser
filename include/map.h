/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaju <jaju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:05:20 by jaju              #+#    #+#             */
/*   Updated: 2023/08/31 12:34:20 by jaju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_entry
{
	char	*key;
	void	*value;
	t_entry	*next;
}t_entry;

typedef struct s_map
{
	t_entry	*entries;
}t_map;

void	map_init(t_map *this);
void	*map_get(t_map *this, const char *key);
void	map_put(t_map *this, const char *key, void *value);

#endif
