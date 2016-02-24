#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    wifstream ifs("../../../student_list-1.csv");
    wstring str;
    
    cout<<"load_data"<<endl;
    while(getline(ifs,str)){//csvで参加者データは1行にまとめられてる
        wstring *tmp_array;
        wstring tmp;
        wistringstream stream(str);
        wcout<< str << endl;
        while(getline(stream,tmp)){//一人の参加者データに対する処理
            wcout<< tmp << endl;
            *tmp_array = tmp;
            tmp_array++;
        }
    }
    return 0;
}