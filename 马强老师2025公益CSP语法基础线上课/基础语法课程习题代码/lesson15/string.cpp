/*
 string 
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	s="hello";
	string s1("hello");
	cin>>s1;
	cout<<s1.size()<<' '<<s1.length()<<endl;
	//getline(cin,s);//读入有空格的字符串 
	cout<<s<<endl;
	for(int i=0;i<s.size();i++)
		cout<<s[i];
	cout<<endl;
	
	return 0;
}
