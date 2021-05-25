#define		MAXHASH	1000003

unsigned int hash65(char *key);
struct dnode *h_insert(struct dnode *list, char *key);
struct dnode *h_find(struct dnode *list, char *key);

#include	"hash.c"
