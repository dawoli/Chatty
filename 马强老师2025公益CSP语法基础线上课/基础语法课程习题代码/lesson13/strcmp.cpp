/*
  strcmp函数知识
  作用：比较2个字符串是否相等、或者大小  如果s1>s2,返回大于0的值，s1<s2，返回小于0的值
  相等输出yes，不相等输出字符串大的字符串
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	char s1[101]={},s2[101]={};
	cin>>s1>>s2;
	int flag=strcmp(s1,s2);
	if(flag==0)
		cout<<"yes";
	else if(flag>0){
		cout<<s1;
	}
	else cout<<s2;
	return 0;
}
