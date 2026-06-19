#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=110;
int n,m,a[N],cnt,x,y,tmp;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	cnt=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==cnt) tmp=n*m-i+1;
	}
	x=(tmp+n-1)/n;
	if(tmp%n) y=tmp%n;
	else y=n; 
	if(x%2==1) cout<<x<<" "<<y;
	else cout<<x<<" "<<n-y+1;
	return 0;
}
