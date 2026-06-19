#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7,md=9982344353;
int n,m,a[N],rnk;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	for(int i=1;i<=n*m;i++)
		rnk+=(a[1]<=a[i]);
	for(int i=1;i<=m;i++){
		if(n*i>=rnk){
			if(i&1)
				cout<<i<<" "<<(rnk-n*(i-1));
			else
				cout<<i<<" "<<n-(rnk-n*(i-1))+1;
			return 0;
		}
	}
} 
