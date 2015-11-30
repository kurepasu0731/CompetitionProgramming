#include <stdio.h>
 
int main(void){
    int n,k,a;
    scanf("%d %d",&n,&k);
    int i;
    int position = 0;
    
    for(i=0;i<k;i++){
        scanf("%d",&a);
        position += a;
        
        if(position == n-1){
            printf("YES\n%d\n",i+1);
            return 0;
        }
        if(position>n-1){
            position = 2*n-2-position;
        }
    }
 
   
    printf("NO\n%d\n",position+1);
    
    
}