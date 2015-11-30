#include<iostream>
using namespace std;

int sum_array(int arg[]){
	int result = 0;
	for(int i = 0; i<3; i++){
		result += arg[i];
	}
	return result;
}

void opti_function(int price, int arg[]){
	int minimum = 1000;
	int result[3];
	if(price<=1000)return ;
	for(int i0 =0;i0 <=arg[0];i0++){
		for(int i1=0;i1<=arg[1];i1++){
			for(int i2=0;i2<=arg[2];i2++){
				int temp_min = price - 500*i0 -200*i1 -100*i2;
				if(temp_min >= 0){
					if(temp_min < minimum ){
						minimum = temp_min;
						result[0]=i0;
						result[1]=i1;
						result[2]=i2;
					}else if(temp_min == minimum){
						if(sum_array(result) > i0+i1+i2){
							result[0]=i0;
							result[1]=i1;
							result[2]=i2;
						}
					}
				}
			}
		}
	}
	cout<<"["<<result[0]<<","<<result[1]<<","<<result[2]<<"]"<<endl;
}


int main(){

	int price;
	cout<<"input price";
	cin>>price;

	int arg[3];
	for(int i=0;i<3;i++){
		cout<<"input ticket"<<i<<":";
		cin>>arg[i];
	}
	opti_function(price, arg);

}

