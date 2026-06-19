#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q;
	int a[109];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	q=a[0];
	sort(a,a+n*m,cmp);
	int k;
	for(int i=0;i<n*m;i++){
		if(a[i]==q) k=i+1;
	}
	int g=k%(2*m);
	if(g==m) cout<<k/m;
	else cout<<k/m+1;
	cout<<" ";
	if(g==0) cout<<1;
	else if(g>m) cout<<2*m-g+1;
	else cout<<g;
	return 0;
}
