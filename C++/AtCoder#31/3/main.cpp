#include<iostream>
#include <vector>  
using namespace std;


// vectorからindex番目の要素を削除する
template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

//数列ゲーム
int main()
{

	vector<int> v;
	vector<int> score;
	vector<int>::iterator it;

	it = v.begin();         // 先頭のイテレータを取得
	

	int n;
	cin >> n;

	for(int i =0;i<n;i++){//数列の初期化
		int arg;
		cin >> arg;
		v.push_back(arg);
	}

	int temp;
	int innnertemp;
	int outertemp;

	int AokiScore;
	int BestAokiScore;
	int BestAokiIndex;

	int TakaScore;
	int BestTakaScore;
	int BestTakaIndex;
	
	
	for(int i =0;i<n;i++){//スコアの計算
		BestAokiScore =0;
		BestTakaScore =0;
		temp = v.at(i);
		remove(v,i);//(高橋が消す(適当に))
		it = v.begin(); 

		for(int j =0;j<n-1;j++){//青木が消す(適当に)
			AokiScore =0;
			TakaScore =0;
			innnertemp = v.at(j);
			remove(v,j);
			it = v.begin(); 
			for(int k = 1;k<n-3;k+=2){//青木のスコア計算(偶数番目)
				AokiScore += v.at(k);
			}
			if(BestAokiScore<AokiScore){//青木の消す場所とスコア
				BestAokiIndex = j;
				BestAokiScore = AokiScore;//次回の更新用
			}
			it = v.begin();
			v.insert(it,j,innnertemp);
		}
		//ここまででiを高橋が消した時の青木の消す場所jは分かっている
		outertemp = v.at(BestAokiIndex);
		remove(v,BestAokiIndex);
		it = v.begin(); 
		TakaScore =0;
		for(int m = 0;m < n-2;m+=2){//高橋のスコア計算(偶数番目)
			TakaScore += v.at(m);
		}
		if(BestTakaScore<TakaScore){
			BestTakaScore = TakaScore;
		}
		it = v.begin();
		v.insert(it,BestAokiIndex,outertemp);
		it = v.begin();
		v.insert(it,i,temp);
	}

	cout << BestTakaScore<<endl;

	// for(int i =1;i<=n;i++){
	// 	cout<<v.at(i)<<endl;
	// }

	return 0;
}

