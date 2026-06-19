#include <bits/stdc++.h>
#define int long long
using namespace std;
struct p{
	bool f;
	int s;
};
bool cmp(p a,p b){
	return a.s>b.s;
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<p> a(n*m+1);
	cin>>a[1].s;
	a[1].f=1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i].s;
	}
	sort(a.begin()+1,a.end(),cmp);
	int x=-1,y=-1;
	for(int i=1;i<=n*m;i++){
		if(a[i].f){
			x=ceil(i*1.0/n);
			if(x&1) y=i%n;
			else y=(n+1-(i%n))%n;
			if(y==0) y=n;
			break;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
