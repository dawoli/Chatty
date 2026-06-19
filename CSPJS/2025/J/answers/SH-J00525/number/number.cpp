#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	string digits;
	for(char c:s){
		if(isdigit(c)){
			digits.push_back(c);
		}
	}
	sort(digits.begin(),digits.end(),greater<char>());
	cout<<digits<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;//完结撒花，你好呀2025csp-j,易如反掌牢弟 ,下一题见 
} 
