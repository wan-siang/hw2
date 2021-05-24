struct tnode{
	char *key;
	struct tnode *LChild;
	struct tnode *RChild;
};

struct tnode *BST_find(struct tnode *T, char *str);
struct tnode *BST_insert(struct tnode *T, char *str);
