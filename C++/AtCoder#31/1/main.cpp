#include<iostream>
using namespace std;

//ゲームのやつ
int main()
{
	// 整数の入力
	int a;
	cin >> a;

	int b;
	cin >> b;

	int attack_expect = (a+1)*b;
	int defence_expect = (a)*(b+1);
	if(attack_expect>defence_expect){
		cout<<attack_expect<<endl;
	}else{
		cout<<defence_expect<<endl;
	}
	return 0;
}