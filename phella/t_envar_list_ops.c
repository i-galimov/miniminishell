#include "buildin.h"

t_envar	*ft_lstnew2(void *key, void *value)
{
	t_envar	*lst;

	lst = (t_envar *)malloc(sizeof(*lst));
	if (lst == NULL)
		return (NULL);
	lst->next = NULL;
	lst->key = key;
	lst->value = value;
	return (lst);
}

void	ft_lstadd_back2(t_envar **lst, t_envar *new)
{
	t_envar	*list;

	if (*lst == NULL)
		*lst = new;
	else
	{
		list = *lst;
		while (list->next != NULL)
			list = list->next;
		list->next = new;
	}
}

int	ft_lstsize2(t_envar *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_envar	*ft_lstlast2(t_envar *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}