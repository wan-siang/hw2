#include	"basic.h"

struct	dnode{
	char	*key;
	struct 	dnode	*next;
};

unsigned int hash65(char *key){
	unsigned int	hv = 0;
	char 	*ptr = key;

	while(*ptr){
		hv = hv * 65 + *ptr;
		ptr++;
	}
	return	hv;	 
}

struct dnode *h_insert(struct dnode *list, char *key){
	struct dnode *p;
	p = (struct dnode *)malloc(sizeof(struct dnode));
	p->key = strdup(key);
	if(list == NULL){
		p->next = NULL;
		return p;
	}
	p->next = list;
	return p;
}

struct dnode *h_find(struct dnode *list, char *key){
	struct dnode *p = list;

	while(p){
		if(strcmp(p->key,key)==0){
			return p;
		}		
		p = p -> next;
	}
	return NULL;
}
