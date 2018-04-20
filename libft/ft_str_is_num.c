int		ft_str_is_num(char *str)
{
	while (str[0] != '\0')
	{
		if (!(str[0] >= '0' && str[0] <= '9'))
			return (0);
		str++;
	}
	return (1);
}
