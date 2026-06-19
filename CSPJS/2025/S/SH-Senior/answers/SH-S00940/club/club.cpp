#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef pair<int,int> PII;
int book[N],person[3],a[N][4];
vector<PII> e[N]; 
vector<int> q[4];
bool check(int x,int t){
	int u,v,cnt=-3e5;
	for(int i=0;i<q[x].size();i++){
		int it=q[x][i];
		int k=a[t][x]-a[it][x];
		for(auto it1:e[it]){
			if(a[t][x]-(a[it][x]-it1.first)>cnt&&it1.second!=x){//
				cnt=a[t][x]-(a[it][x]-it1.first);
				u=i;v=it1.second;
				//cout<<cnt<<" ";
			}
		}
	}
	if(cnt>0){
		q[v].push_back(q[x][u]);
		q[x][u]=t;
		return 1;
	}
	else return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				e[i].push_back({a[i][j],j});
			}
			sort(e[i].begin(),e[i].end());
		}
		for(int i=1;i<=n;i++){
			auto it=e[i][2];
			if(q[it.second].size()<n/2) q[it.second].push_back(i);
			else if(!check(it.second,i)){
				it=e[i][1];
				q[e[i][1].second].push_back(i);
//				else if(!check(it.second,i)){
//					it=e[i][0];
//					q[it.second].push_back(i);
//				}
			}
		}
		int sum=0;
		for(int i=1;i<=3;i++){//cout<<i<<":";
			for(auto it:q[i]){
				sum+=a[it][i];//cout<<a[it][i]<<" ";
			}
		}
		cout<<sum<<"\n";
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		for(int i=1;i<=3;i++) q[i].clear();
	}
	return 0;
}

