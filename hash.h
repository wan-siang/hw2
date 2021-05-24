#define		MAXHASH	1000003

struct	dnode{
	char	*key;
	struct 	dnode	*next;
};

unsigned int hash65(char *key);
struct dnode *h_insert(struct dnode *list, char *key);
struct dnode *h_find(struct dnode *list, char *key);
