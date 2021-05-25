#include	"basic.h"

struct lnode {
	char	*key;
	struct lnode	*next;
};

struct	lnode	*Linsert(struct lnode *L, char *str)
{
	struct lnode *p = (struct lnode *)malloc(sizeof(struct lnode));
	p->key = strdup(str);
	p->next = L;

	if(L==NULL){
		p->next = NULL;
		return p;
	}	
	
	struct lnode *q = L;
	while(q->next){
		q = q->next;
	}
	q->next = p;
	p->next = NULL;
	return L;

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
