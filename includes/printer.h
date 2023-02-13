/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:23:55 by vlepille          #+#    #+#             */
/*   Updated: 2023/01/18 18:23:56 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

typedef struct s_printer
{
	char	**printer;
	int		len;
	int		msize;
}	t_printer;

int		ft_upscale_printer(t_printer *printer, int size)
		__attribute__ ((warn_unused_result));

void	init_printer(t_printer *printer);
void	delete(t_printer *printer);
int		add(t_printer *printer, char *str) __attribute__ ((warn_unused_result));
int		print(t_printer *printer);

#endif
