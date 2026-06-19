#include"bits/stdc++.h"
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		int ans1=0;
		vector<pair<int,int> >prevv,v;
		vector<int>pos(m,0);
		for(int i=0;i<n;i++){
			int d0,v0,a0;
			cin>>d0>>v0>>a0;
			if(a0<0){
				if(V<v0){
					prevv.push_back(make_pair(d0,min(L,d0+(      (V*V-v0*v0)%(2*a0)==0?(V*V-v0*v0)/(2*a0)-1:(V*V-v0*v0)/(2*a0)     ))));
					//cout<<prevv.rbegin()->first<<' '<<prevv.rbegin()->second<<endl;
				}
			}
			else if(a0==0){
				if(V<v0){
					prevv.push_back(make_pair(d0,L));
					//cout<<prevv.rbegin()->first<<' '<<prevv.rbegin()->second<<endl;
				}
			}
			else{
				int p=V*V-v0*v0;
				int q=2*a0;
				int l=p/q+1;
				if(l+d0<=L){
					prevv.push_back(make_pair(l+d0,L));
					//cout<<prevv.rbegin()->first<<' '<<prevv.rbegin()->second<<endl;
				}
			}
		}
		for(int i=0;i<m;i++){
			cin>>pos[i];
		}
		int sze=prevv.size();
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
		for(int i=0;i<sze;i++){
			int l=lower_bound(pos.begin(),pos.end(),prevv[i].first)-pos.begin();
			int r=upper_bound(pos.begin(),pos.end(),prevv[i].second)-pos.begin();
			//cout<<l<<' '<<r<<endl;
			//[l,r);
			if(l<r){
				v.push_back(make_pair(l,r-1));
				//cout<<l<<' '<<r-1<<endl;
				q.push(make_pair(r-1,l));
			}
		}
		sze=v.size();
		cout<<sze<<' ';
		int ans=0;
		while(!q.empty()){
			pair<int,int>tmp=q.top();
			//get tmp.second one;
			while(q.top().second<=tmp.first){
				//printf("get %d %d by %d %d\n",q.top().second,q.top().first,tmp.second,tmp.first);
				q.pop();
				if(q.empty()){
					break;
				}
			}
			ans++;
		} 
		cout<<m-ans<<endl;
	}
}
