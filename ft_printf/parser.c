#include "ft_printf.h"

int		ft_flags_parser(const char **format, t_spec **spec)
{
	int len;
	len = 0;
	while ((ft_strchr("-0 ", **format)))
	{
		if ((**format == '-') && ((*spec)->flag != '-'))
			(*spec)->flag = **format;
		else if ((**format == '0') && ((*spec)->flag != '-'))
			(*spec)->flag = **format;
		else if ((**format == ' ') && ((*spec)->space != 1))
			(*spec)->space = 1;
		len++;
		(*format)++;
	}
	return (len);
}

int		ft_width_parser(va_list ap, const char **format, t_spec **spec)
{
	int len;
	int num;

	len = 0;
	num = 0;
	if (**format == '*')
		(*spec)->width = va_arg(ap, int);
	else if ((num = ft_atoi(*format)) != 0) // Можно в width просто класть результат атои сразу
		(*spec)->width = num;
	else
		return (0);
	if ((*spec)->width < 0)
	{
		(*spec)->flag = '-';
		(*spec)->width *= -1;
	}
	len += ft_get_nbr_len(num, 10);
	(*format) += len;
	return (len);
}

int		ft_accuracy_parser(va_list ap, const char **format, t_spec **spec)
{
	int len;
	int num;

	len = 0;
	if (**format == '.')
		if (*(++(*format)) == '*')
		{
			(*spec)->accuracy = va_arg(ap, int);
			len += 2;
			(*format)--;
		}
		else
		{
			if ((num = ft_atoi(*format)) != 0)
				len++;
			(*spec)->accuracy = num;
			if (num < 0)
				return (-1);
			len += ft_get_nbr_len(num, 10) + ft_zero_len(*format); // + 1 тк еще надо пропустить .
			(*format)--;
		}
	(*format) += len;
	return(len);
}

int		ft_parser(va_list ap, const char *format, t_spec *spec)
{
	int len;
	int a_len;
	
	ft_init_spec(&spec);
	len = ft_flags_parser(&format, &spec);
	len += ft_width_parser(ap, &format, &spec);
	a_len = ft_accuracy_parser(ap, &format, &spec);

	if (*format == '\0')
		return (0);
	else if (a_len < 0)
		return (len + 1);
	len += a_len;
	if (ft_strchr("diucspxX%", *format))
		spec->type = *format;
	else if ((*(format + 1)) == '\0')
		return (0);
	return ((spec->type == '_') ? (len + 1) : ((len + 1) * -1));
}
