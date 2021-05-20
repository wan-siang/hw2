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
		int len = 0;
		while(len<8){
			num = rand();
			while(num > 0){
				if(len == 8) break;
				str[len] = 'A' + (num%26);
				num = num / 26;
 				len++;
			}
		}
		str[len] = '\0';	
		word[i] = (char *)malloc(sizeof(char) * 9);
		strcpy(word[i],str);
		i++;
	}
	
	for(i = 0; i < N; i++){
		printf("%s\n",word[i]);
		free(word[i]);
	}
	
}

