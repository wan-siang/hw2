struct lnode {
	char	*key;
	struct lnode	*next;
};

struct	lnode	*Linsert(struct lnode *L, char *str);
struct lnode	*Lfind(struct lnode *L, char *str);
