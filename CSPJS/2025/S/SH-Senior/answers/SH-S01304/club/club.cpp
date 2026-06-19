#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long t,n,x[N][3],id[N],ans;
struct info{
	long long differ;
	long long num;//id
	bool operator<(const info x)const{
		return differ<x.differ||differ==x.differ&&num<x.num;
	}
};
multiset<info> s;
multiset<info>::iterator it;
long long now[N],ANS;
void dfs(int t){
	if(t==n+1) ANS=max(ANS,ans);
	if(now[0]<n/2){	
		now[0]++;
		ans+=x[t][0];
		dfs(t+1);
		ans-=x[t][0];
		now[0]--;
	}
	if(now[1]<n/2){	
		now[1]++;
		ans+=x[t][1];
		dfs(t+1);
		ans-=x[t][1];
		now[1]--;
	}
	if(now[2]<n/2){	
		now[2]++;
		ans+=x[t][2];
		dfs(t+1);
		ans-=x[t][2];
		now[2]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		s.clear();
		cin>>n;
		for(int i=1;i<=n;i++) cin>>x[i][0]>>x[i][1]>>x[i][2];
		if(n<=10){
			ANS=0;
			ans=0;
			for(int i=1;i<=n;i++) now[i]=0;
			dfs(1);
			cout<<ANS<<endl;
			continue;
		}
		for(int i=1;i<=n;i++) ans+=x[i][0];
		for(int i=1;i<=n;i++) id[i]=0;
		for(int i=1;i<=n;i++) s.insert({x[i][1]-x[i][id[i]],i});
		it=s.end();
		for(int i=1;i<=n/2;i++){
			it--;
			ans+=(*it).differ;
			id[(*it).num]=1;
		}
		s.clear();
		for(int i=1;i<=n;i++) s.insert({x[i][2]-x[i][id[i]],i});
		it=s.end();
		for(int i=1;i<=n/2;i++){
			it--;
			if((*it).differ>0){
				ans+=(*it).differ;
				id[(*it).num]=2;
			}
			else break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
