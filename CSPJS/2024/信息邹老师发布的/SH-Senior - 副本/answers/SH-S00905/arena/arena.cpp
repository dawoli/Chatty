#include<bits/stdc++.h>
using namespace std;
int ass,b;
inline int read(){
	char ch=getchar();
	int asss=1;
	long long ans=0;
	if(ch=='-'){
	asss=-1;
	ch=getchar();}
	while(0<=ch-'0'&&9>=ch-'0'){
		ans=ans*10+(ch-'0');
		ch=getchar();
	}
	return ans*asss;
}
int main(){
	ass=read();
	cout<<ass;
	cout<<"a"<<endl;
	cout<<"b"<<endl;
}
