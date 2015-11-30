#include<iostream>
#include <vector>  
using namespace std;

//ゲームのやつ
int main()
{

	vector<int> v;

	// 整数の入力
	int l,h;
	cin >> l >> h;

	int n;
	cin >> n;

	v.push_back(0);
	for(int i =1;i<=n;i++){
		int arg;
		cin >> arg;
		v.push_back(arg);
	}

	// cout << "l:"<< l <<endl;
	// cout << "h:"<< h <<endl;

	for(int i =1;i<=n;i++){
		if((v.at(i) >= l ) && (v.at(i) <= h)){
			v.at(i) = 0;
		}else if(v.at(i) < l){
			v.at(i)= l - v.at(i);
		}else{
			v.at(i) = -1;
		}
		cout<<v.at(i)<<endl;
	}

	return 0;
}