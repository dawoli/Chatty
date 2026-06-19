#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n;
bool cmp(pair<int,int> x,pair<int,int> y){
	return x>y;
}
priority_queue<pair<pair<int,int>,pair<int,int> > > q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		while(!q[0].empty()) q[0].pop();
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			int a1,a2,a3;
			scanf("%d%d%d",&a1,&a2,&a3);
			pair<int,int> buf[3]={
				make_pair(a1,0),
				make_pair(a2,1),
				make_pair(a3,2)
			};
			sort(buf,buf+3,cmp);
			ans+=buf[0].first;
			q[buf[0].second].push(make_pair(
				make_pair(buf[1].first-buf[0].first,buf[2].first-buf[1].first),
				make_pair(buf[1].second,buf[2].second)
			));
		}
		while(q[0].size()>n/2){
			pair<pair<int,int>,pair<int,int> > top=q[0].top();
			q[0].pop();
			ans+=top.first.first;
			q[top.second.first].push(make_pair(
				make_pair(top.first.second,-0x3f3f3f3f),
				make_pair(top.second.second,0)
			));
		}
		while(q[1].size()>n/2){
			pair<pair<int,int>,pair<int,int> > top=q[1].top();
			q[1].pop();
			ans+=top.first.first;
			q[top.second.first].push(make_pair(
				make_pair(top.first.second,-0x3f3f3f3f),
				make_pair(top.second.second,0)
			));
		}
		while(q[2].size()>n/2){
			pair<pair<int,int>,pair<int,int> > top=q[2].top();
			q[2].pop();
			ans+=top.first.first;
			q[top.second.first].push(make_pair(
				make_pair(top.first.second,-0x3f3f3f3f),
				make_pair(top.second.second,0)
			));
		}
		while(q[0].size()>n/2){
			pair<pair<int,int>,pair<int,int> > top=q[0].top();
			q[0].pop();
			ans+=top.first.first;
			q[top.second.first].push(make_pair(
				make_pair(top.first.second,-0x3f3f3f3f),
				make_pair(top.second.second,0)
			));
		}
		while(q[1].size()>n/2){
			pair<pair<int,int>,pair<int,int> > top=q[1].top();
			q[1].pop();
			ans+=top.first.first;
			q[top.second.first].push(make_pair(
				make_pair(top.first.second,-0x3f3f3f3f),
				make_pair(top.second.second,0)
			));
		}
		while(q[2].size()>n/2){
			pair<pair<int,int>,pair<int,int> > top=q[2].top();
			q[2].pop();
			ans+=top.first.first;
			q[top.second.first].push(make_pair(
				make_pair(top.first.second,-0x3f3f3f3f),
				make_pair(top.second.second,0)
			));
		}
		cout<<ans<<endl;
	}
	return 0;
}
