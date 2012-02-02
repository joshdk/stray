#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char stray(unsigned char c,double chance){
	unsigned char mask=0;
	for(int n=0;n<8;++n){
		mask<<=1;
		if((double)rand() < (chance/100)*2147483647){
			//flip bit
			mask|=!(c&(128>>n));
		}else{
			//keep bit
			mask|=!!(c&(128>>n));
		}
	}
	return mask;
}


int main(int argc,char **argv){

	if(argc>=2){
		if(!strcmp(argv[1],"--help")){//help
			printf("Usage: stray [PERCENT]\n");
			printf("Introduce error to standard out based on input on standard in.\n");
			printf("\n");
			printf("Examples:\n");
			printf("  Introduce 10%% error to the data \"helloworld\"\n");
			printf("  $ echo 'helloworld' | stray 10\n");
			return 0;
		}else if(!strcmp(argv[1],"--version")){//version
			printf("stray version 1.0\n");
			return 0;
		}
	}

	double percent=0.0;
	if(argc>=2){
		percent=atof(argv[1]);
	}
	if(percent<0){
		percent=0.0;
	}else if(percent>=100){
		percent=100.0;
	}

	srand(time(NULL));
	while(1){
		int c=fgetc(stdin);
		if(c==EOF){
			break;
		}
		//printf("[%c]\n",stray(c,percent));
		putchar(stray(c,percent));
	}

	return 0;
}
