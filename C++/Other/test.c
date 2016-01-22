#include <stdio.h>

void print_oniku(int f,int s){
    if(f == 2 && s ==9){
        char oniku[] = "おにく";
        char tabetai[] = "たべたい";
        printf("%s%s\n",oniku,tabetai);
    }else if (f == 2){
    	printf("%s\n",oniku);
    }else if (f == 9){
    	printf("%s\n",tabetai);
    }else{
    	printf("Please input 2 or 9\n");
    }
}
 
int main(void){
    int f,s;
    scanf("%d %d",&f,&s);
    print_oniku(f,s);
    return 0;
}