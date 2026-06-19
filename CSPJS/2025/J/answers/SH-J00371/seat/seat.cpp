#include <bits/stdc++.h>
using namespace std;

int n,m,a[105],s[15][15];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int ar=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	if(n==1 && m==1){
		cout<<1<<1;
		return 0;
	}
	if(m==1){
		cout<<1<<" ";
		for(int i=1;i<=n*m;i++)
			if(a[i]==ar){
				cout<<i;
				return 0;
			}
	}
	if(n==1){
		for(int i=1;i<=n*m;i++)
			if(a[i]==ar)
				cout<<i<<" ";
		cout<<1;
		return 0;
	}
	
	int x=0;
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			s[j][i]=a[x*n+j];
		}
		x+=2;
	}
	int y=1;
	for(int i=2;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			s[j][i]=a[y*n+n-j+1];
		}
		y+=2;
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]==ar)
				cout<<j<<" "<<i;
	return 0;
}
