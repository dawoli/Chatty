/*
  输入一个字符串
 */
#include<bits/stdc++.h>
using namespace std;
int main(){ 
	char s[101]={};
	cin>>s;//s[0],s[1],s[2]......
	int len=strlen(s);
	cout<<s<<endl;
	for(int i=0;i<len;i++)
		cout<<s[i];
	
	return 0;
}
