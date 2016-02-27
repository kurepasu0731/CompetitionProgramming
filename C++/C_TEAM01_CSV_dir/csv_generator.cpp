/**
2016/02/27 Hiroki Naganuma Created
**/


#include <iostream> //入出力ライブラリ
#include <fstream> //iostreamのファイル入出力をサポート
#include <algorithm>
#include <cstdlib>
#include <dirent.h>
#include <vector>
#include <stdio.h>
#include <cassert>

using namespace std;

bool fileExists(const std::string& fileName){
     std::fstream file;
     file.open(fileName.c_str(), std::ios::in);
     if (file.is_open() == true)
     {
         file.close();
         return true;
     }
     file.close();
     return false;
}


static void copyFile(const std::string& fileNameFrom, const std::string& fileNameTo){
     assert(fileExists(fileNameFrom));
     std::ifstream in (fileNameFrom.c_str());
     std::ofstream out (fileNameTo.c_str());
     out << in.rdbuf();
     out.close();
     in.close();
}


int main(){
ofstream ofs("Test.csv"); //ファイル出力ストリーム
ofs<<"file,A,B,C"<<endl; //"<<"で流し込むだけ 

vector<string> lines;

const char* path = "./";
DIR *dp;       // ディレクトリへのポインタ
dirent* entry; // readdir() で返されるエントリーポイント

string a = "a/";  
string b = "b/"; 
string c = "c/"; 
string A = ",1,0,0";
string B = ",0,1,0";
string C = ",0,0,1";

char *src = new char[100];
char *dst = new char[100];

dp = opendir(path);
if (dp==NULL) exit(1);
do {
  entry = readdir(dp);
  if (entry != NULL)
      if(isdigit(entry->d_name[0])){
          switch(entry->d_name[14]){
              case 'A':
              copyFile(entry->d_name,a+entry->d_name);
              lines.push_back(a+entry->d_name+A);
                // ofs<<"a/"<<entry->d_name<<",1,0,0"<<endl; //"<<"で流し込むだけ 
                break;
              case 'B':
              copyFile(entry->d_name,b+entry->d_name);
              lines.push_back(b+entry->d_name+B);
                // ofs<<"b/"<<entry->d_name<<",0,1,0"<<endl; //"<<"で流し込むだけ 
                break;
              case 'C':
              copyFile(entry->d_name,c+entry->d_name);
              lines.push_back(c+entry->d_name+C);
                // ofs<<"c/"<<entry->d_name<<",0,0,1"<<endl; //"<<"で流し込むだけ 
              break;
                default:
                break;
          }
      }
  } while (entry != NULL);
  random_shuffle(lines.begin(), lines.end());
  for(int i = 0 ; i<lines.size();i++){
    ofs<<lines.at(i)<<endl;
  }
  return 0;
}
