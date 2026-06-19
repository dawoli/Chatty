#include<bits/stdc++.h>
using namespace std;


char mapp[1000][1000]; int xas,yas;
int x(int a,int b,int c,long long n,long long xa){
	if(n=0) return xa;
	if(c=0) {
		if(mapp[a][b+1]=='.'&&a>=1&&b+1>=1&&a<=xas&&b+1<=yas) return x(a,b,c+1,n-1,xa);
		else return x(a,b+1,c,n-1,xa+1);
	}
	if(c=1) {
		if(mapp[a+1][b]=='.'&&a+1>=1&&b>=1&&a+1<=xas&&b<=yas) return x(a,b,c+1,n-1,xa);
		else return x(a+1,b,c,n-1,xa+1);
	}
	if(c=2) {
		if(mapp[a][b-1]=='.'&&a>=1&&b-1>=1&&a<=xas&&b-1<=yas) return x(a,b,c+1,n-1,xa);
		else return x(a,b-1,c,n-1,xa+1);
	}
	if(c=3) {
		if(mapp[a-1][b]=='.'&&a-1>=1&&b>=1&&a-1<=xas&&b<=yas) return x(a,b,0,n-1,xa);
		else return x(a-1,b,c,n-1,xa+1);
	}
}
int main(){
	int na;
	for(int i=0;i<na;i++){
		int z,a,b,c;
		cin>>xas>>yas>>z;
		cin>>a>>b>>c;
		for(int j=1;j<xas;j++){
			for(int k=1;k<=yas;k++){
				cin>>mapp[j][k];
			}
		}
		cout<<x(a,b,c,z,1);
	}
}
