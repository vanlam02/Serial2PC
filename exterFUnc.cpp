#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int numberAppearInString(string s,string delimiter);
void splitString(string result[],string s,string delimiter);

int main(){

	string s = "0x009bc140 \"16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050\n16050";	
	//string s = "##pham-nguyen-minh-thuan##";
	int SIZE_OF_ARRAY = 100;
	string delimiter = "\n";
	string * result = new string[SIZE_OF_ARRAY];
	splitString(result,s,delimiter);
	
	for(int i = 0;i < numberAppearInString(s,delimiter)+1;i++){
		cout << result[i] << endl;
	}
	
	return 0;
}

int numberAppearInString(string s,string delimiter){
	int count =  0;
	
	for(int i = 0;i < (s.length() - delimiter.length()+1);i++){
		if(s.substr(i,delimiter.length()) == delimiter){
			count++;
		}
	}
	return count;
}

void splitString(string result[],string s,string delimiter){
	int index = 0;
	//remove delimiter in head and end
	if(s.substr(0,delimiter.length()) == delimiter){
		s = s.substr(delimiter.length(),s.length()-delimiter.length());
	}
	
	if(s.substr(s.length() -delimiter.length()) == delimiter){
		s = s.substr(0,s.length() - delimiter.length());
	}
	
	while(numberAppearInString(s,delimiter) > 0){
		int i = 0;
		for(i = 0;i < (s.length() - delimiter.length()+1);i++){
			if(s.substr(i,delimiter.length()) == delimiter){
				break;
			}
		}
		
		if(i == (s.length() - delimiter.length()+1)){
			result[index] = s;
			return;
		}
		
		result[index++] = s.substr(0,i);
		
		s = s.substr(i+delimiter.length(),s.length() - i - delimiter.length());
	}
	
	result[index] = s;
}


