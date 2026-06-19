/*
  
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
//	string s1,s2,s3;
//	cin>>s1>>s2;
//	s3=s1+s2;//直接拼接
//	cout<<s3<<endl;
//	if(s1>s2) cout<<s1<<endl;
//	else	  cout<<s2<<endl;
//	//查找子串 find()   hello world world    "hello"
//	char s11[101]="hello world world",s12[101]="hello";
//	string s21="hello world world",s22="world1";
//	int pos= s21.find(s22);//找不到子串，返回-1
//	cout<<pos<<endl;
	//截取子串substr(起始位置，截取字符长度)
	string str1="abcdefghijk";
	string str2=str1.substr(4,5);
	cout<<str2<<endl;
	
	return 0;
}
