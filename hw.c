#include	"basic.h"
#include	"BST.h"
#include	"Array.h"
#include	"Array_Binary_Search.h"
#include	"Linked_list.h"
#include	"hash.h"

char	*word[1000000];

int	main(int argc, char *argv[])
{
	int	M,N;	//N:insert M:query
	int	BST = 0;
	int	ABS = 0;
	int	ARR = 0;
	int	L_list = 0;
	int 	HASH = 0;
	char	str[10];
	int	i;

	struct timeval start;
	struct	timeval end;
	unsigned long diff;

	for(i = 0; i < argc; i++){	
		if(strcmp(argv[i],"-d")==0){
			if(strcmp(argv[i+1],"1e6")==0)	N = 1000000;
			else if(strcmp(argv[i+1],"1e5")==0)	N = 100000;
			else if(strcmp(argv[i+1],"1e4")==0)	N = 10000;		
		}
		else if(strcmp(argv[i],"-q")==0){
			if(strcmp(argv[i+1],"1e5")==0)	M = 100000;
			else if(strcmp(argv[i+1],"1e4")==0)	M = 10000;
			else if(strcmp(argv[i+1],"1e3")==0)	M = 1000;		
		}
		else if(strcmp(argv[i],"-bst")==0)	BST = 1;
		else if(strcmp(argv[i],"-bs")==0)	ABS = 1;
		else if(strcmp(argv[i],"-arr")==0)	ARR = 1;
		else if(strcmp(argv[i],"-ll")==0)	L_list = 1;
		else if(strcmp(argv[i],"-hash")==0)	HASH = 1;
	}

	if(BST)
	{
		struct 	tnode	*tree = NULL;

		printf("bst:\n");
		gettimeofday(&start,NULL);
		for(i = 0; i < N; i++)
		{	
			scanf("%s",str);
			tree = BST_insert(tree,str);
		}
		gettimeofday(&end,NULL);
		diff = 	1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
		printf("building time: %f sec\n", diff/1000000.0);
		
		gettimeofday(&start,NULL);		
		for(i = 0; i < M; i++)
		{			
			scanf("%s",str);							
			tree = BST_find(tree,str);
		}		
		gettimeofday(&end,NULL);
		diff = 	1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
		printf("query time: %f sec\n", diff/1000000.0);
	}

	if(ABS)
	{	
		printf("abs:\n");
		gettimeofday(&start,NULL);
		for(i = 0; i < N; i++)
		{	
			scanf("%s",str);
			word[i] = (char *)malloc(sizeof(char) * 10);
			strcpy(word[i],str);
		}
		sort_array(word,0,N-1);
		gettimeofday(&end,NULL);
		diff = 	1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
		printf("building time: %f sec\n", diff/1000000.0);

		gettimeofday(&start,NULL);
		char *location = NULL;		
		for(i = 0; i < M; i++)
		{	
			scanf("%s",str);
			location = binary_search(word, N, str);
		}		
		gettimeofday(&end,NULL);
		for(i = 0; i < N; i++){
			free(word[i]);
		}
		diff = 	1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
		printf("query time: %f sec\n", diff/1000000.0);
	}
	if(ARR)
	{
		int	index;
		
		printf("arr:\n");
		gettimeofday(&start,NULL);
		for(i = 0; i < N; i++)
		{	
			scanf("%s",str);
			word[i] = (char *)malloc(sizeof(char) * 10);
			strcpy(word[i],str);
		}
		gettimeofday(&end,NULL);
		diff = 	1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
		printf("building time: %f sec\n", diff/1000000.0);

		gettimeofday(&start,NULL);		
		for(i = 0; i < M; i++)
		{	
			scanf("%s",str);
			index = -1;
			index = arr_find(word,str,N);
		}		
		gettimeofday(&end,NULL);
		for(i = 0; i < N; i++){
			free(word[i]);
		}
		diff = 	1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
		printf("query time: %f sec\n", diff/1000000.0);	
	}
	if(L_list)
	{
		struct 	lnode	*keylist = NULL;
		
		printf("L_list:\n");
		gettimeofday(&start,NULL);
		for(i = 0; i < N; i++)
		{	
			scanf("%s",str);
			keylist = Linsert(keylist,str);
		}
		gettimeofday(&end,NULL);
		diff = 	1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
		printf("building time: %f sec\n", diff/1000000.0);

		gettimeofday(&start,NULL);		
		for(i = 0; i < M; i++)
		{	
			scanf("%s",str);
			keylist = Lfind(keylist,str);
		}		
		gettimeofday(&end,NULL);
		diff = 	1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
		printf("query time: %f sec\n", diff/1000000.0);		
	}
	if(HASH)
	{
		struct dnode	**hashTab;
		struct dnode *dptr;		
		long long maxHash = MAXHASH;
		unsigned int	c;
		
		hashTab = (struct dnode **)malloc(sizeof(struct dnode *) * maxHash);
		
		for(int i = 0; i < maxHash; i++){
			hashTab[i] = NULL;
		}
	
		printf("hash:\n");
		gettimeofday(&start,NULL);
		for(long long i = 0; i < N; i++){
			scanf("%s",str);
			c = hash65(str) % maxHash;				
			hashTab[c] = h_insert(hashTab[c], str);
		}
		gettimeofday(&end,NULL);
		diff = 	1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
		printf("building time: %f sec\n", diff/1000000.0);

		gettimeofday(&start,NULL);
		for(long long i = 0; i < M; i++){
			scanf("%s",str);			
			c = hash65(str) % maxHash;
			if(hashTab[c]){
				dptr = h_find(hashTab[c],str);
			}
		}
		gettimeofday(&end,NULL);
		diff = 	1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
		printf("query time: %f sec\n", diff/1000000.0);

	}

}

