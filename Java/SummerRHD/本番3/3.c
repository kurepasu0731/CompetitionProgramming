#include<stdio.h>

typedef struct data{
  int num;
  int value;
}data;

int compare(const void* a,const void* b){
  return *(data*)a-*(data*)b;
}
int main(void){
  int count;
  FILE *fp;
  /*fp = fopen("data","r");
  if(fp==NULL){
    printf("Error opening file!\n");
    }*/
  fp = stdin;
  int e;
  e=fscanf(fp,"%d",&count);//fscanfはその代入した個数を返す
  if(e!=1){
    return 1;
  }
  int i;
  data r,g,b;
  data r1={0},r2={0},r3={0},g1={0},g2={0},g3={0},b1={0},b2={0},b3={0};
  for(i=0;i<count;i++){
    e=fscanf(fp,"%d %d %d",&(r.value),&(g.value),&(b.value));
    r.num=i;
    g.num=i;
    b.num=i;
    if(e!=3){
      return 1;
    }
    if(r.value>=r1.value){
      r3.value=r2.value;
      r3.num=r2.num;
      r2.value=r1.value;
      r2.num=r1.num;
      r1.value=r.value;
      r1.num=r.num;
    }else if(r.value>r2.value){
      r3.value=r2.value;
      r3.num=r2.num;
      r2.value=r.value;
      r2.num=r.num;
    }else if(r.value>r3.value){
      r3.value=r.value;
      r3.num=r.num;
    }

    if(g.value>=g1.value){
      g3.value=g2.value;
      g3.num=g2.num;
      g2.value=g1.value;
      g2.num=g1.num;
      g1.value=g.value;
      g1.num=g.num;
    }else if(g.value>g2.value){
      g3.value=g2.value;
      g3.num=g2.num;
      g2.value=g.value;
      g2.num=g.num;
    }else if(g.value>g3.value){
      g3.value=g.value;
      g3.num=g.num;
    }

    if(b.value>=b1.value){
      b3.value=b2.value;
      b3.num=b2.num;
      b2.value=b1.value;
      b2.num=b1.num;
      b1.value=b.value;
      b1.num=b.num;
    }else if(b.value>b2.value){
      b3.value=b2.value;
      b3.num=b2.num;
      b2.value=b.value;
      b2.num=b.num;
    }else if(r.value>b3.value){
      b3.value=b.value;
      b3.num=b.num;
    }
 
  }
  int max;
  if(r1.num==g1.num){
    if(r1.value-r2.value+g1.value-g2.value>b1.value-b2.value){
      max=r1.value-r2.value+g1.value-g2.value;
      if(b2.num==r1.num){
	b2.value=b3.value;
	b2.num=b3.num;
      }
      r2.value=r3.value;//
      r2.num=r3.num;
      r1.value=r2.value;//
      r1.num=r2.num;
      g2.value=g3.value;//
      g2.num=g3.num;
      g1.value=g2.value;//
      g1.num=g2.num;
    }
  }else if(r1.num==b1.num){
    if(r1.value-r2.value+b1.value-b2.value>g1.value-g2.value){
      max=r1.value-r2.value+b1.value-b2.value;
      if(g2.num==r1.num){
	g2.value=g3.value;//
	g2.num=g3.num;
      }
      r2.value=r3.value;//
      r2.num=r3.num;
      r1.value=r2.value;//
      r1.num=r2.num;
      b2.value=b3.value;//
      b2.num=b3.num;
      b1.value=b2.value;//
      b1.num=b2.num;
    }
  }else if(b1.num==g1.num){
    if(b1.value-b2.value+g1.value-g2.value>r1.value-r2.value){
      max=b1.value-b2.value+g1.value-g2.value;
      if(r2.num==r1.num){
	    r2.value=r3.value;//
	    r2.num=r3.num;
      }
      b2.value=b3.value;//
      b2.num=b3.num;
      b1.value=b2.value;//
      b1.num=b2.num;
      g2.value=g3.value;//
      g2.num=g3.num;
      g1.value=g2.value;//
      g1.num=g2.num;
    }
  }
  
  
  
  printf("%d\n",r1.value+g1.value+b1.value-max);

  /*
  int max;
  max = (r1-r2)>(g1-g2)? ((r1-r2)>(b1-b2)?(r1-r2):(b1-b2)) : ((g1-g2)>(b1-b2)?(g1-g2):(b1-b2));
  printf("%d\n",r1+g1+b1-max);

  return 0;*/
}
