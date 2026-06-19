#include<bits/stdc++.h>
using namespace std;
const int N=100001;

int n, r[N], ans, now, vis[N], cnt1, cnt2, cnt[N];
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		if(r[i]==1)cnt1++;
		if(r[i]==2)cnt2++;
	}
	if(cnt1+cnt2==n){
		if(cnt2>cnt1){
			cout<<cnt2<<endl;
		}
		else cout<<cnt2+(cnt1-cnt2)<<endl;
		return 0;
	}
	sort(r+1, r+n+1);
	int e=1;
	for(int i=2;i<=n;i++){
		if(r[i]>r[i-1])cnt[i]=cnt[i-1]+e, e=1;
		else cnt[i]=cnt[i-1], e++;
	}
	int deadm=0;
	for(int i=1;i<=n;i++){
		if(cnt[i]-deadm>0)deadm++;
	}
	cout<<n-deadm<<endl;
	return 0;
}
