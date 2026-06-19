#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int T;

int n;
pii s[100005][3];

priority_queue<pii,vector<pii>,greater<pii>> pq;

pii cnt[3];

int ans;

int main(){
	ios::sync_with_stdio(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	
	while(T--){
		cin>>n;
		
		for(int i=1;i<=n;++i){
			for(int j=0;j<3;++j){
				cin>>s[i][j].first;
				s[i][j].second=j;
			}
			sort(s[i],s[i]+3);
			reverse(s[i],s[i]+3);
		}
		
		for(int j=0;j<3;++j) cnt[j]={0,j};
		
		for(int i=1;i<=n;++i){
			++cnt[s[i][0].second].first;
			ans+=s[i][0].first;
			pq.push({s[i][0].first-s[i][1].first,s[i][0].second});
		}
		
		sort(cnt,cnt+3);
		reverse(cnt,cnt+3);
		
		while(cnt[0].first>n/2){
			pii v=pq.top();pq.pop();
			if(v.second!=cnt[0].second) continue;
			--cnt[0].first;
			ans-=v.first;
		}
		
		cout<<ans<<endl;
		
		while(pq.size()) pq.pop();
		
		ans=0;
	}
	
	return 0;
}
