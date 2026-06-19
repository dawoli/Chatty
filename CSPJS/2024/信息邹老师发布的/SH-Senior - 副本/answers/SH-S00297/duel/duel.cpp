#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll n,d[N],cnt,x,e;
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>d[i];
	}
	cnt=n;
	sort(d+1,d+n+1);
	for(ll i=1;i<=n;i++){
		if(i==1){
			e++;
			continue;
		}
		if(d[i]!=d[i-1]){
			x+=e;
			e=0;
		}
		if(x){
			x--;
			cnt--;
		}
		e++;
	}
	cout<<cnt;
	return 0;
}
