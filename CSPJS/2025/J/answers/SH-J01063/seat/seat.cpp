#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool jishu[110];
int xr;
int xrq=0;
bool qh=0;
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	memset(jishu,0,sizeof(jishu));
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		jishu[a[i]]=1;
	}
	xr=a[1];
	for(int i=xr;i<=100;i++){
		if(jishu[i]){
			xrq++;
		}
	}
	c=(xrq+n-1)/n;
	r=(xrq+n-1)%n+1;
	if(c%2==0){
		r=m-r+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
