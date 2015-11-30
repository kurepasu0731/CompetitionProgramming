#include<iostream>
using namespace std;

int main()
{


	// 整数の入力
	int a,b;
	cin >> a >> b;

	int c,d;
	cin >> c >> d;

	int kayaku = c/a;
	int metal = d/b;

	int result = (kayaku<metal)? kayaku : metal ;
	cout << result <<endl;

	return 0;
}