#include "head.h"

int main(int C, char **V){
	if (C==1){
		printf("lab2 by Ghost\nver 0.01\nEnjoy!\n");
		return 0;
	}
	if (C==2){
		if ((!strcmp(V[1], "-start"))){
			workspace();
			return 0;
		}
		if(!strcmp(V[1],"-h")){
			helpMenu();
			return 0;
		}
	}
	printf("unknown parameters\n");
	return 1;
}