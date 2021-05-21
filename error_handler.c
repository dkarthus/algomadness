#include "push_swap.h"

/**
 * ---Func for handling ERRORS---
 * err = 1 - malloc error
 * err = 2 - invalid values
 */
void ft_error(int err, char *location, void *ptr_to_free)
{
	if (err == 1)
	{
		ft_putstr_fd(location, 1);
		ft_putstr_fd(" - malloc ERROR\n", 1);
	}
	if (err == 2)
		ft_putstr_fd("ERROR!\nInvalid values.\n", 1);
	if (ptr_to_free)
		free(ptr_to_free);
	exit (1);
}