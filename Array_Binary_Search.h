#include	"basic.h"


void	swap(char *word[], int a, int b){
	char *tmp = word[a];
	word[a] = word[b];
	word[b] = tmp;
}

int 	partition(char *word[], int front, int end){
	int left = front+1;
	int right = end;
	char *pivot = word[front];
	
	while(1){
		while(right>left && strcmp(word[right],pivot)>0)	right--;
		while(left<right && strcmp(word[left],pivot)<0)		left++;
		if(left==right)	break;
		swap(word,left,right);
	}
	if(strcmp(word[front],word[left])>0){
		swap(word,front,left);
		return left;
	}
	return front;

}

void	sort_array(char *word[], int front, int end){
	if(front<end){
		int key = partition(word,front,end);
		sort_array(word,front,key-1);
		sort_array(word,key+1,end);
	}
	
}

char	*binary_search(char *word[], int cnt, char *str){
	int low = 0, high = cnt, mid;

	while(low < high) { 
        	mid = (low+high) / 2; 
		if(strcmp(str,word[mid])==0)	return word[mid];
		else if(strcmp(word[mid],str)<0)	low = mid+1; 
		else	high = mid; 
		
    	} 
	
	return NULL;
}
