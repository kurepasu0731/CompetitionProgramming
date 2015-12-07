#include<iostream>
#include <vector>  
#include <numeric>
using namespace std;

int main()
{
    // 整数の入力
    int N;
    cin >> N; 

    long long int inner_temp;
    vector<long long int> length;

    for(int i =0;i<N;i++){
        cin >> inner_temp;
        length.push_back(inner_temp);
    }
    long long int sum = accumulate(length.begin(), length.end(), 0 );


    long long int temp_sum = 0;
    long long int temp_diff;
    long long int pre_diff;
    long long int result_diff = sum;
    for(int i =0;i<N;i++){
        pre_diff = sum;
        for(int j =0;j<N;j++){
            temp_sum += length.at((i+j)%N);
            temp_diff = abs((sum - temp_sum)-temp_sum);
            if(result_diff > temp_diff){
                result_diff = temp_diff;
            }
            if(pre_diff < temp_diff){
                break;
            }
            pre_diff = temp_diff;
        }
        temp_sum=0;
    }

    cout << result_diff <<endl;

    return 0;
}