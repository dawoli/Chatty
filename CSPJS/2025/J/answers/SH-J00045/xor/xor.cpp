#include<bits/stdc++.h>
using namespace std;
struct t{
	int x,y,l;
};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,m=0,r=0;
	cin>>n>>k;
	int a[n];
	t g[(n*n+n)/2]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			g[i].x=i;
			g[i].y=i;
			g[i].l=1;
		}
	}
	while(r<=n){
		for(int i=0;i<n-r;i++){
			for(int j=i;j<=i+r;j++){
				
			}
		}
	}
	return 0;
}
