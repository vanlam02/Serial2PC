#include <iostream>
#include <string>
using namespace std;

int numberAppearInString(string s,string delimiter);
void splitString(string result[],string s,string delimiter);
string formatString(string s);

int main(){
	string str = formatString("23\n123456\n123456\n123456\n123456\n123456\n1234");
	int LENGTH = numberAppearInString(str,"\n");
	string* list = new string[LENGTH];
	splitString(list,str,"\n");
	
	for(int i = 0;i < LENGTH;i++){

		cout << list[i] << endl;

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


string formatString(string s){
	if(s.length() == 0){
		return "";
	}
	//Cut head string
	int i = 0;
	while(i < s.length() && s[i] != '\n'){
		i++;
	}
	if(i >= s.length()-1){
		return "";
	}
	s = s.substr(i+1);
	//cut tail string
	i = s.length()-1;
	
	while(i >= 0 && s[i] != '\n'){
		i--;
	}
	if(i <= 0){
		return "";
	}
	s = s.substr(0,i+1);
	cout << "=================================================" << endl;
	return s;
}
