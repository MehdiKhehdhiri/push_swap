/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekhedhi <mekhedhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:10:07 by mekhedhi          #+#    #+#             */
/*   Updated: 2024/10/19 23:10:12 by mekhedhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "stack.h"

// MAIN CHECKER
int			main(int argc, char *argv[]);
void		read_op(t_ps *data);
bool		test_sort(t_ps *data);

// CHECK SORT
void		error_read_op(t_ps *data, char *line);
int			get_next_line_ps(int fd, char *line);
enum e_op	string_to_op(const char *str);
void		call_op(t_ps *data, enum e_op op);

#endif