#include<iostream>
using namespace std;


int nibai(int argument){
	int temp;
	temp = argument *2;
	return temp;
}

void nibai_pointer(int *arg_p){
	*arg_p *= 2;
	return;
}

void nibaidekinai(int arg){
	arg = arg *2;
	return;
}

int main()
{
	// 整数の入力
	int a;
	cin >> a;

	nibaidekinai(a);
	cout <<"入力した値は" << a <<"です"<< endl;
	return 0;
}

