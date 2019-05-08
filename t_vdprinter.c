#include "ft_printf.h"
#include "libft/libft.h"
#include "t_vdprinter.h"
#include <stdlib.h>
#include <unistd.h>

static int		ft_vdprinter_flush(void *raw_this)
{
	t_vdprinter *const	this = (t_vdprinter *const)raw_this;
	int					size;

	size = this->index;
	this->index = 0;
	return (write(this->fd, this->mem, size));
}

int				ft_vdprinter_write(void *raw_this, const char *s, size_t size)
{
	t_vdprinter *const	this = (t_vdprinter *const)raw_this;
	size_t				to_write;
	size_t				capacity;
	int					flush_ret;

	if (size >= BUFF_SIZE)
	{
		if ((flush_ret = this->super.flush(this)) < 0)
			return (EWRITE);
		return (write(this->fd, s, size));
	}
	to_write = size;
	if (to_write > (capacity = BUFF_SIZE - this->index))
	{
		ft_memcpy(this->mem + this->index, s, capacity);
		this->index = BUFF_SIZE;
		to_write -= capacity;
		if ((flush_ret = this->super.flush(this)) < 0)
			return (EWRITE);
	}
	ft_memcpy(this->mem + this->index, s, to_write);
	this->index += to_write;
	return (size);
}

static int		ft_vdprinter_repeat(void *raw_this, char c, size_t count)
{
	t_vdprinter *const	this = (t_vdprinter *const)raw_this;
	size_t				to_write;
	size_t				capacity;
	int					flush_ret;

	to_write = count;
	while (to_write > (capacity = BUFF_SIZE - this->index))
	{
		ft_memset(this->mem + this->index, c, capacity);
		this->index = BUFF_SIZE;
		to_write -= capacity;
		if ((flush_ret = this->super.flush(this)) < 0)
			return (flush_ret);
	}
	ft_memset(this->mem + this->index, c, to_write);
	this->index += to_write;
	return (count);
}

static char*	ft_vdprinter_alloc(void *raw_this, size_t size)
{
	t_vdprinter *const	this = (t_vdprinter *const)raw_this;
	char				*dst;

	if (size > BUFF_SIZE)
		return (ft_printer_alloc(raw_this, size));
	if (size > BUFF_SIZE - this->index)
		this->super.flush(this);
	dst = this->mem + this->index;
	this->index += size;
	this->super.alloc_size = size;
	return (dst);
}

int				ft_vdprinter_init(t_vdprinter *printer, int fd, va_list *args)
{
	if (printer == NULL || (printer->mem = (char*)malloc(BUFF_SIZE)) == NULL)
		return (0);
	ft_printer_init(&(printer->super), args);
	printer->super.write = ft_vdprinter_write;
	printer->super.repeat = ft_vdprinter_repeat;
	printer->super.alloc = ft_vdprinter_alloc;
	printer->super.flush = ft_vdprinter_flush;
	printer->fd = fd;
	printer->index = 0;
	printer->del = ft_vdprinter_del;
	return (1);
}
