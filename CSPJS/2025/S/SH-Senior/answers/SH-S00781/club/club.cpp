#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
const int mod=1e9+7;
int t,n,cnt[5],ans;
struct node{
	int w,delta;
};
bool operator<(node a,node b){
	return a.delta<b.delta; 
}
priority_queue<node> q[5];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				cnt[1]++;
				int delta=a-max(b,c);
				q[1].push({a,delta});
			}
			else if(b>=a&&b>=c){
				cnt[2]++;
				int delta=b-max(a,c);
				q[2].push({b,delta});
			}
			else if(c>=a&&c>=b){
				cnt[3]++;
				int delta=c-max(a,b);
				q[3].push({c,delta});
			}
		}
		if(cnt[1]>n/2){
			for(int i=1;i<=n/2;i++){
				ans+=q[1].top().w;
				q[1].pop();
			}
			while(!q[1].empty()){
				ans+=q[1].top().w-q[1].top().delta;
				q[1].pop();
			}
		}
		if(cnt[2]>n/2){
			for(int i=1;i<=n/2;i++){
				ans+=q[2].top().w;
				q[2].pop();
			}
			while(!q[2].empty()){
				ans+=q[2].top().w-q[2].top().delta;
				q[2].pop();
			}
		}
		if(cnt[3]>n/2){
			for(int i=1;i<=n/2;i++){
				ans+=q[3].top().w;
				q[3].pop();
			}
			while(!q[3].empty()){
				ans+=q[3].top().w-q[3].top().delta;
				q[3].pop();
			}
		}
		while(!q[1].empty()){
			ans+=q[1].top().w;
			q[1].pop();
		}
		while(!q[2].empty()){
			ans+=q[2].top().w;
			q[2].pop();
		}
		while(!q[3].empty()){
			ans+=q[3].top().w;
			q[3].pop();
		}
		cout<<ans<<endl;
		ans=cnt[1]=cnt[2]=cnt[3]=0;
	}
	return 0;
}

