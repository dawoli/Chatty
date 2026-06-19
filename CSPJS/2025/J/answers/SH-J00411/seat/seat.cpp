#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c[109],s,m[19][19];
	int x=0;
	cin>>a>>b;
	for(int i=0;i<a*b;i++)
		cin>>c[i];
	int d=c[0];
	for(int i=0;i<a*b;i++)
		for(int j=0;j<a*b;j++)
			if(c[j]<c[j+1]){
				s=c[j];
				c[j]=c[j+1];
				c[j+1]=s;
			}
	for(int i=0;i<a;i++)
		for(int j=0;j<a;j++){
			m[i][j]=c[x];
			x++; 
		}
	for(int i=0;i<a;i++)
		for(int j=0;j<a;j++)
			if(m[i][j]==d)
				cout<<i+1<<" "<<j+1;
	return 0;
}
