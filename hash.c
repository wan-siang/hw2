#include	"basic.h"
#define		MAXHASH	//find the smallest prime that is bigger than 100w
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

struct 	dnode	*l_insert(struct dnode *L, char *key){
	struct dnode	*p;
	
	p = (struct dnode *)malloc(sizeof(struct dnode ));
	p->key = strdup(key);
	p->cnt = 1;
	p->next = L;
    printf("p->key:%s\n",p->key);
	return p;
}

void	hash_insert(struct dnode **hTab, long long maxHash, char *key){
	int32	hv;
	struct	dnode	*L;

	hv = hash65(key) % maxHash;
	L = hTab[hv];
	hTab[hv] = l_insert(L, key);

}

struct dnode *l_find(struct dnode *L, char *key){
	struct dnode *p;
	if(L==NULL) return NULL;
	
	p = L;
	while(p){
		if(strcmp(p->key,key)==0){
			return p;
		}		
		p = p -> next;
	}
	return NULL;
}

struct dnode *hash_find(struct dnode **hTab, long long maxHash, char *key){
	int32	hv;
	struct	dnode	*dptr;
	
	hv = hash65(key) % maxHash;
	dptr = hTab[hv];
	return	l_find(dptr, key);
}

void rmNewLine(char *str){
    int len = strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]=='\n'){
            str[i] = '\0';
        }
    }
}

void traverse(struct dnode *Tab){
    printLinkedList(Tab);
}
int 	main(){
	struct	dnode	**hTab;
	long long	maxHash;
	char	line[MaxLen];
	struct 	dnode	*dptr;

	maxHash = DEFMAXHASH;
	hTab = (struct dnode **)malloc(sizeof(struct dnode *) * maxHash);

	for(int i=0;i<maxHash;i++){
		hTab[i] = NULL;
	}
	
	while(fgets(line, MaxLen, stdin)){
		rmNewLine(line);
		dptr = hash_find(hTab, maxHash, line);

		if(dptr!=NULL)	dptr->cnt++;
		else	hash_insert(hTab, maxHash, line);	
	}	
	
	for(int i=0;i<maxHash;i++){
		traverse(hTab[i]);
	}
}

