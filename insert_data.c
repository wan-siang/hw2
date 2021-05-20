#include	"basic.h"
#define		Max	1000000

char *word[Max];

int main(){
	int	N;
	int	i = 0,j,k;
	char	str[10];
	int	num;
	
	srand(1);
	scanf("%d",&N);
	
	while(i < N){
		for(j = 0; j < 8; j++){
			num = rand() % 26;
			str[j] = 'A' + num;
		}
		str[j] = '\0';
		for(k = 0; k < i; k++){
			if(strcmp(str,word[k])==0)	break;
		}	
		if(k == i){
			word[i] = (char *)malloc(sizeof(char) * 9);
			strcpy(word[i],str);
			i++;
		}
	}
	
	for(i = 0; i < N; i++){
		printf("%s\n",word[i]);
		free(word[i]);
	}
	
}

