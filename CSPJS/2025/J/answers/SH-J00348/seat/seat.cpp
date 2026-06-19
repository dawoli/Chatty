#include<bits/stdc++.h>
using namespace std;
int n,m,a[205],t,c=1,r=1,flag=1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>a[i],t=a[1];
	sort(a+1,a+1+n*m);
	t=lower_bound(a+1,a+1+n*m,t)-a;
	t=n*m-t+1;
	for(int i=2;i<=t;++i){
		r+=flag;
		if(r>=n+1) c++,r=n,flag=-1;
		else if(r<=0) c++,r=1,flag=1;
	}
	cout<<c<<" "<<r<<"\n";
	return 0;
}
