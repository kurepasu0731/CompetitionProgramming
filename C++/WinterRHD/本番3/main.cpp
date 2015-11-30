#include<iostream>
#include <vector>  
#include <string>  
using namespace std;

vector<char> element;

unsigned int fac(unsigned int n) {
    if (n > 1){
        return n * fac(n-1);
    }else{
        return 1;
    }
}

unsigned int combinations(unsigned int n, unsigned int k) {
    return fac(n) / (fac(k) * fac(n-k));
}
// programmign
int check_dup(string s,int size){
    int tempIndex=0;
    int dupresult=0;
    for(int i =0;i<size;i++){
        bool isdo =true;
        int tempIndex=0;
        
        char temp = s.at(i);
        element.push_back(temp);

        for(int j =0;j<element.size();j++){
            if(element.at(j)==temp && j!=i) {
                isdo=false;
            }
        }

        if((s.find(temp)!= s.rfind(temp)) && isdo){
            while(s.find(temp,tempIndex)!= string::npos){
                dupresult++;
                int sub = s.find(temp,tempIndex);
                if(sub == tempIndex){
                    break;
                }else{
                    tempIndex = sub;
                }
            }
            dupresult--;
        }
    }
    return dupresult;
}


int main()
{
    // 整数の入力
    string s;
    cin >> s; 

    int length = s.size();
    int result = combinations(length,2)+1;
    int offset = check_dup(s,length);
    cout << result-offset <<endl;
    return 0;
}