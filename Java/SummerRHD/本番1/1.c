#include<stdio.h>
int main(void){
  int a,b,x;
  int max,min;
  if(scanf("%d\n%d\n%d",&a,&b,&x)!=3){//scanfの戻り値は値を代入したデータ引数の数、失敗した場合はEOF
    return 1;
  }
  min = a*3+3;
  max = b*3-3;
  if(x>=min&&x<=max){

    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}
