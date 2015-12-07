#include<iostream>
#include <math.h>
using namespace std;

int main(void){
    int x,k;
    cin >> x;
    cin >> k;


    int temp;//解答候補
    int keta = (int)log10((double)x) + 1;
    int result = temp = pow(10,keta)*9+x;//初期は考えられる最大の数

    //最上位のくらいを忘れていた場合
    for(int i=1;i<=9;i++){
    	temp = pow(10,keta)*i+x;//OK
    	if(temp%k==0){
    		if(result>temp){
    			result=temp;
    		}
    	}
    }

    //最下位のくらいを忘れていた場合
    for(int i=0;i<=9;i++){
    	temp = i+10*x;//OK
    	if(temp%k==0){
    		if(result>temp){
    			result=temp;
    		}
    	}
    }

    cout<<result<<endl;
    return 0;
}