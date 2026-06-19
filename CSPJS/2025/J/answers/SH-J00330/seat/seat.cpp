#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define endl "\n"
int a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int xr;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xr=a[1];
	sort(a+1,a+n*m+1);
	int x=1,y=1;
	int f[2]={1,-1};
	int z=0;
	for(int i=n*m;i>=1;i--){
		if(a[i]==xr){
			cout<<y<<' '<<x;
			return 0;
		}
		int x1=x+f[z];
		if(x1>n||x1==0){
			z=(z+1)%2;
			x1=x;
			y++;
		}
		x=x1;
	}
	return 0;
} 
