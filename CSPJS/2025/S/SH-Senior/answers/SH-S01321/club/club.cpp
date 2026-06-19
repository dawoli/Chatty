#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int T,C[N],n;
struct node{
	int c,v;
	bool operator <(node x)const{
		return v>x.v;
	}
};
priority_queue<node>q[3];
vector<node>v[N];
long long ans;
void psh(int pos){
	bool flag=false;
	while(!flag){
		int c=v[pos][C[pos]].c,val=v[pos][C[pos]].v;
		if(q[c].size()+1<=n/2){
			ans+=val; 
			q[c].push({pos,val-v[pos][C[pos]+1].v});
			flag=true;
		}else{
			node head=q[c].top();
			if(head.v<val-v[pos][C[pos]+1].v){
				ans-=v[head.c][C[head.c]].v;
				ans+=val;
				q[c].pop();
				q[c].push({pos,val-v[pos][C[pos]+1].v});
				C[head.c]++;
				psh(head.c);
				flag=true;
			}else C[pos]++;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T-->0){
		ans=0;
		cin>>n;
		memset(C,0,sizeof(C));
		int a[n+1][3];
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++){
				int x;cin>>x;
				v[i].push_back({j,x});
			}
		for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end(),[](node x,node y){return x.v>y.v;});
		for(int i=1;i<=n;i++)	psh(i);
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=0;i<3;i++)
			while(!q[i].empty()) q[i].pop();
	}
}
