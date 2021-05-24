#include	"basic.h"
#include	"Linked_list.h"

struct	lnode	*Linsert(struct lnode *L, char *str)
{
	struct lnode *p = (struct lnode *)malloc(sizeof(struct lnode));
	p->key = strdup(str);
	p->next = L;
	return p;  
}

struct lnode	*Lfind(struct lnode *L, char *str)
{
	struct lnode *p = L;

	while(p)
	{
		if(strcmp(p->key,str)==0)
		{
			return p;
		}
		p=p->next;
	}
	return NULL;
}
