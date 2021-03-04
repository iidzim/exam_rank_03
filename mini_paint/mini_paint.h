/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:28:00 by iidzim            #+#    #+#             */
/*   Updated: 2021/02/03 15:49:48 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
#define MINI_PAINT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct	s_circle{
	int			w;
	int			h;
	char		b;
	char		c;
	float		x;
	float		y;
	float		r;
	char		d;
	float		dist;
}				t_circle;

#endif
