#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
	
	srand(time(NULL));
	
	double percent=0.0;
	if(argc>=2){
		percent=atof(argv[1]);
	}
	if(percent<0){
		percent=0.0;
	}else if(percent>=100){
		percent=100.0;
	}

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
