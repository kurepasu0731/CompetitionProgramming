#include <iostream> //入出力ライブラリ
#include <fstream> //iostreamのファイル入出力をサポート
#include <algorithm>
#include <cstdlib>
#include <dirent.h>

using namespace std;

int main(){
ofstream ofs("Test.csv"); //ファイル出力ストリーム
ofs<<"file,A,B,C"<<endl; //"<<"で流し込むだけ 

const char* path = "./";
DIR *dp;       // ディレクトリへのポインタ
dirent* entry; // readdir() で返されるエントリーポイント
  
dp = opendir(path);
if (dp==NULL) exit(1);
do {
  entry = readdir(dp);
  if (entry != NULL)
      if(isdigit(entry->d_name[0])){
          switch(entry->d_name[14]){
              case 'A':
                ofs<<"a/"<<entry->d_name<<",1,0,0"<<endl; //"<<"で流し込むだけ 
                break;
              case 'B':
                ofs<<"b/"<<entry->d_name<<",0,1,0"<<endl; //"<<"で流し込むだけ 
                break;
              case 'C':
                ofs<<"c/"<<entry->d_name<<",0,0,1"<<endl; //"<<"で流し込むだけ 
              break;
                default:
                break;
          }
      }
  } while (entry != NULL);
  return 0;
}