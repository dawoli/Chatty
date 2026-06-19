#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n,ans,id[N],ms[N];
int a[4],p[4],cnt[4];
bool cmp(int A,int B){
	return a[A]>a[B];
}
void solve(){
	for(int i=1;i<=3;i++)
		p[i]=i,cnt[i]=0;
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[1]>>a[2]>>a[3];
		sort(p+1,p+4,cmp);
		cnt[p[1]]++; ans+=a[p[1]];
		id[i]=p[1]; ms[i]=a[p[1]]-a[p[2]];
	}
	int tp=0;
	for(int i=1;i<=3;i++)
		if(cnt[i]>n/2) tp=i;
	if(tp){
		priority_queue<int> que;
		for(int i=1;i<=n;i++)
			if(id[i]==tp)
				que.push(-ms[i]);
		while(cnt[tp]>n/2){
			ans+=que.top();
			que.pop();
			cnt[tp]--;
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin>>T;
	while(T--) solve();
	return 0;
}