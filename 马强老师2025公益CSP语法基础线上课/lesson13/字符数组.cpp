/*
  转义字符\0
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[101]={0};
	char s[101]={};
	char s1[101]={'a','b','c','\0'};
	char s2[101]="hello";
	int n;
	cin>>n;
	for(int i=0;i<n;i++)//字符数组通常从0开始
		cin>>s[i];
	cin>>s1;//等同于13/14行代码
	for(int i=0;i<n;i++)
		cout<<s[i];
	cout<<endl;
	cout<<s1;//等同于16/17行代码
	
	return 0;
}
