/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:18:06 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/14 09:18:14 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* #include "/home/sss/UTIL/leakdetect.h"
* #define malloc(s) leak_detect_malloc(s, __FILE__, __LINE__)
* #define free leak_detect_free
*/
size_t	etoa4(size_t idx, double value, t_format *fmt, t_etoa *etoa)
{
	size_t	start_idx;

	start_idx = idx;
	fmt->flags &= ~FLAGS_ADAPT_EXP;
	if (etoa->negative)
		idx = ftoa(idx, -value, fmt);
	else
		idx = ftoa(idx, value, fmt);
	if (etoa->minwidth)
	{
		if (fmt->flags & FLAGS_UPPERCASE)
			out_char('E', idx++);
		else
			out_char('e', idx++);
		fmt->negative = etoa->expval < 0;
		fmt->base = 10;
		fmt->precision = 0;
		fmt->width = etoa->minwidth - 1;
		fmt->flags = FLAGS_ZEROPAD | FLAGS_PLUS;
		idx = ntoa_long(idx, etoa->expval, fmt);
		if (fmt->flags & FLAGS_LEFT)
			while (idx - start_idx < fmt->width)
				out_char(' ', idx++);
	}
	return (idx);
}

double	etoa3(double value, t_format *fmt, t_conv *conv, t_etoa *etoa)
{
	if (fmt->flags & FLAGS_ADAPT_EXP)
	{
		if ((value >= 1e-4) && (value < 1e6))
		{
			if ((int)fmt->precision > etoa->expval)
				fmt->precision = (unsigned)(fmt->precision - etoa->expval - 1);
			else
				fmt->precision = 0;
			fmt->flags |= FLAGS_PRECISION;
			etoa->minwidth = 0;
			etoa->expval = 0;
		}
		else
			if ((fmt->precision > 0) && (fmt->flags & FLAGS_PRECISION))
				--fmt->precision;
	}
	if (fmt->width > etoa->minwidth)
		fmt->width -= etoa->minwidth;
	else
		fmt->width = 0;
	if ((fmt->flags & FLAGS_LEFT) && etoa->minwidth)
		fmt->width = 0;
	if (etoa->expval)
		value /= conv->f;
	return (value);
}

void	etoa2(double value, t_conv *conv, t_etoa *etoa)
{
	double	z;
	double	z2;

	conv->f = value;
	if (value)
	{
		etoa->exp2 = (int)((conv->u >> 52u) & 0x07ffu) - 1023;
		conv->u = (conv->u & ((1ull << 52u) - 1u)) | (1023ull << 52u);
		etoa->expval = (int)(0.1760912590558 + etoa->exp2 * 0.301029995663981
				+ (conv->f - 1.5) * 0.289529654602168);
		etoa->exp2 = (int)(etoa->expval * 3.321928094887362 + 0.5);
		z = etoa->expval * 2.302585092994046 - etoa->exp2 * 0.6931471805599453;
		z2 = z * z;
		conv->u = (int64_t)(etoa->exp2 + 1023) << 52u;
		conv->f *= 1 + 2 * z / (2 - z + (z2 / (6 + (z2 / (10 + z2 / 14)))));
	}
	if (value < conv->f)
	{
		etoa->expval--;
		conv->f /= 10;
	}
}

size_t	etoa(size_t idx, double value, t_format *fmt)
{
	t_conv	*conv;
	t_etoa	*etoa;

	if ((value != value) || (value > DBL_MAX) || (value < -DBL_MAX))
		return (ftoa(idx, value, fmt));
	conv = (t_conv *)malloc(sizeof(t_conv));
	etoa = (t_etoa *)malloc(sizeof(t_etoa));
	etoa->negative = value < 0;
	if (etoa->negative)
		value = -value;
	if (!(fmt->flags & FLAGS_PRECISION))
		fmt->precision = PRINTF_DEFAULT_FLOAT_PRECISION;
	etoa2(value, conv, etoa);
	if ((etoa->expval < 100) && (etoa->expval > -100))
		etoa->minwidth = 4;
	else
		etoa->minwidth = 5;
	value = etoa3(value, fmt, conv, etoa);
	idx = etoa4(idx, value, fmt, etoa);
	free(conv);
	free(etoa);
	return (idx);
}
