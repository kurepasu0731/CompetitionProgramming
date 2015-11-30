#include<stdio.h>
int main(void){
  int a,b;
  scanf("%d %d",&a,&b);
  int carry=0,res=0;
  int i;
  int bin=1;
  int tmpa,tmpb,tmpc;
  for(i=0;i<32;i++){
    tmpa = bin & a;
    tmpb = bin & b;
    tmpc = bin & carry;
    res = (tmpa^tmpb^tmpc) | res;
    carry = (tmpa&tmpb)|(tmpa&tmpc)|(tmpb&tmpc);
    carry = carry << 1;
    bin = bin << 1;
  }
  printf("%d",res);
}