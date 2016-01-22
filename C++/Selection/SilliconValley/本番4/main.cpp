#include<iostream>
#include <vector>  
#include <string>  
using namespace std;


int main(void){
    int N, K;//カードの枚数と、作りたい単語の最小の長さ
    cin >> N >>K; 

    vector<string> w;

    string inner_temp;
    for(int i =0;i<N;i++){
        cin >> inner_temp;
        w.push_back(inner_temp);
    }

    int char_number;
    char result = 'z';
    string temp_result;
    for(int i =0;i<N;i++){
        for(int j =0;j<N;j++){
            temp_result += w.at((i+j)%N);
            if(temp_result.length()>K){
                char_number = (int)temp_result[K-1];
                if(char_number <(int)result){
                     result = temp_result[K-1];
                }
            }
        }
        temp_result.clear();
    }
    cout<< result <<endl;
    return 0;
}