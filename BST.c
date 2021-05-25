#include	"basic.h"

struct tnode{
	char *key;
	struct tnode *LChild;
	struct tnode *RChild;
};

struct tnode *BST_find(struct tnode *T, char *str){
	if(T==NULL) return NULL;
	if(strcmp(str,T->key)==0){
		return T;
	}else if(strcmp(str,T->key)<0){
		return BST_find(T->LChild,str);
	}else{
		return BST_find(T->RChild,str);
	}
}

struct tnode *BST_insert(struct tnode *T, char *str){
	if(T==NULL){
		struct tnode *p = (struct tnode *)malloc(sizeof(struct tnode));
		p->key = strdup(str);
		p->LChild = NULL;
		p->RChild = NULL;
		return p;
	}
	if(strcmp(str,T->key)<0){
		T->LChild = BST_insert(T->LChild,str);	
	}else{
		T->RChild = BST_insert(T->RChild,str);
	}
	return T;
}
