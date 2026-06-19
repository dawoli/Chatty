#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");
	string s;
	fin>>s;
	int number[1000005]={0};
	int num=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			number[num]=s[i]-48;
			num++;
		}
	}
	sort(number,number+num);
	for(int i=num-1;i>=0;i--){
		fout<<number[i];
	}
	return 0;
