#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

void ReverseStr(char *str,int n){
	stack<char> sta;
	for(int i=0;i<n;i++){
		sta.push(str[i]);
	}
	for(int i=0;i<n;i++){
		str[i]=sta.top();
		sta.pop();
	}
}


int main(){

	char str[100];

	cout << "Enter the string to reverse : ";
	cin >> str;
	ReverseStr(str,strlen(str));
	cout << "Reversed string : " << str;

	return 0;
}
