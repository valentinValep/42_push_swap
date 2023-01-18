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

int		ft_upscale_printer(t_printer *printer, int size);
void	delete(t_printer *printer);

void	init_printer(t_printer *printer);
int		add(t_printer *printer, char *str);
int		print(t_printer *printer);

#endif
