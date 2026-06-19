/*
  strcmp()
  strlen() 输入字符串的长度
  当输入字符有空格、tab时，默认输入结束
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	char s[101]={};
	//cin>>s;
	cin.getline(s,101);//读入空格
	cout<<s<<endl;
	return 0;
}
