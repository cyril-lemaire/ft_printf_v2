#include "t_printer.h"
#include "libft/libft.h"
#include "stdlib.h"

static char*	ft_printer_alloc(void *raw_this, size_t size)
{
	t_printer *const	this = (t_printer *const)raw_this;
	char				*alloc_ret;

	this->alloc_size = size;
	if ((alloc_ret = this->private_alloc(this, size)) != NULL)
		return (alloc_ret);
	return (this->alloc_mem = (char*)malloc(size));
}

static int		ft_printer_endalloc(void *raw_this)
{
	t_printer *const	this = (t_printer *const)raw_this;
	int		f_ret;
	
	if (this->alloc_mem == NULL)
		return (this->alloc_size);
	f_ret = this->write(this, this->alloc_mem, this->alloc_size);
	ft_memdel((void**)&this->alloc_mem);
	this->alloc_size = 0;
	return (f_ret);
}


static void		ft_printer_del(void *raw_this)
{
	t_printer *const	this = (t_printer *const)raw_this;

	if (this != NULL)
		free(this->alloc_mem);
}

int				ft_printer_init(t_printer *printer, va_list *args)
{
	if (printer == NULL)
		return (0);
	ft_memset(&printer->flags, 0, sizeof(t_flags));
	printer->written = 0;
	printer->alloc_size = 0;
	printer->alloc_mem = NULL;
	printer->args = args;
	printer->alloc = ft_printer_alloc;
	printer->endalloc = ft_printer_endalloc;
	printer->alloc_size = 0;
	printer->private_del = ft_printer_del;
	return (1);
}