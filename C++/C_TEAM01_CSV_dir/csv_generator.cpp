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
	if (file.is_open() == true){
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

string a_path = "a/";  
string b_path = "b/"; 
string c_path = "c/"; 
string a_vector = ",1,0,0";
string b_vector = ",0,1,0";
string c_vector = ",0,0,1";

dp = opendir(path);
if (dp==NULL) exit(1);
do {
	entry = readdir(dp);
	if (entry != NULL)
		if(isdigit(entry->d_name[0])){
			if(strstr(entry->d_name,"A")!=NULL){
				copyFile(entry->d_name,a_path+entry->d_name);
				lines.push_back(a_path+entry->d_name+a_vector);
			}else if (strstr(entry->d_name,"B")!=NULL){
				copyFile(entry->d_name,b_path+entry->d_name);
				lines.push_back(b_path+entry->d_name+b_vector);
			}else if (strstr(entry->d_name,"C")!=NULL){
				copyFile(entry->d_name,c_path+entry->d_name);
				lines.push_back(c_path+entry->d_name+c_vector);
			}
		}
	} while (entry != NULL);
	random_shuffle(lines.begin(), lines.end());
	for(int i = 0 ; i<lines.size();i++){
		ofs<<lines.at(i)<<endl;
	}
	return 0;
}
