#include<bits/stdc++.h>
using namespace std;
int T,n,a[100009][5],choice[100009],ans,cnt[5],loss[100009];
priority_queue<int> pq;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(cnt,0,sizeof(cnt));
		while(!pq.empty()) pq.pop(); 
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int mx=1;
			if(a[i][2]>a[i][mx]) mx=2;
			if(a[i][3]>a[i][mx]) mx=3;
			ans+=a[i][mx];
			cnt[mx]++;
			choice[i]=mx;
			int mmx=(mx==1?2:1);
			if(a[i][2]>a[i][mmx]&&mx!=2) mmx=2;
			if(a[i][3]>a[i][mx]&&mx!=3) mmx=3;
			loss[i]=a[i][mmx]-a[i][mx];
		}
		int tgt=1;
		if(cnt[2]>cnt[tgt]) tgt=2;
		if(cnt[3]>cnt[tgt]) tgt=3;
		if(cnt[tgt]<=n/2){
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			if(choice[i]==tgt) pq.push(loss[i]);
		}
		for(int i=1;i<=cnt[tgt]-n/2;i++){
			ans+=pq.top();
			pq.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}
