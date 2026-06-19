#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct road{
	int f,t,v;
}a[1000005];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].f>>a[i].t>>a[i].v;
	}
	int v[n+k+1]={};
	for(int i=1;i<=k;i++){
		cin>>v[n+i];
		for(int j=1;j<=n;j++){
			cin>>a[n+j].v;
			a[n+j].f=j;
			a[n+j].t=n+i;
		}
	}
	
	return 0;
}
