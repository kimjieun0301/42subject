#include "libft.h"

t_list	*ft_lstnew(void *content)
{
    t_list	*ctt;

    ctt = (t_list *)malloc(sizeof(t_list));
	if (!ctt)
		return (0);
	ctt->next = NULL;
	ctt->content = content;
	return (ctt);
}
