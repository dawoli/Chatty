#include<stdio.h>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

int n,m,k;
int v[10005];
struct pts{
	int to;
	int cost;
};
vector<pts> map[10005];
ll ans;

void dfs(int dep,int pos,ll cnt){
	if(cnt>ans) return;
	if(dep=n){
		ans=cnt;
		return;	
	}
	v[pos]=1;
	for(int i=1;i<=n;i++){
		if(map[pos].to==i&&v[i]==0){
			dfs(dep+1,i,cnt+map[pos].cost);
		}
	}
}

vector<int> m[100];
m.

int main(){
	ans=1<<31;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		map[x].push_back((pts){y,min(map[x].cost,c)});
		map[y].push_back((pts){x,min(map[y].cost,c)});
	}
	
	for(int i=1)
}
