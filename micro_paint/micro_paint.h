/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:39:19 by iidzim            #+#    #+#             */
/*   Updated: 2021/02/03 21:41:54 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
#define MICRO_PAINT_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct	s_rectangle{
	int			w;
	int			h;
	char		b;
	char		c;
	float		x;
	float		y;
	float		r_width;
	float		r_height;
	char		d;
}				t_rectangle;

#endif
