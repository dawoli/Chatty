#include<iostream>
using namespace std;
int main(){
	int n,s[101]={};
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	int p=0,Min=1000;
	for(int i=1;i<=n;i++){
		if(s[i]<Min){
			Min=s[i];
			p=i;
		}
	}
	for(int i=p+1;i<=n;i++)
		s[i-1]=s[i];
	for(int i=1;i<=n-1;i++)
		cout<<s[i]<<' ';
	return 0;
}
