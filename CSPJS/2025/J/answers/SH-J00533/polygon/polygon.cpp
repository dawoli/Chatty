#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a,b,c;
	cin>>n;
	cin>>a>>b>>c;
	int maxn=max(max(a,b),c);
	if((a+b+c)>maxn*2){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0; 
} 
