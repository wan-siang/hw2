#include	"basic.h"
#include	"Array.h"

int	arr_find(char *line[], char *str, int cnt){
	for(int i = 0; i < cnt; i++){
		if(strcmp(line[i],str) == 0){
			return i;
		}
	}
	return -1;
}
