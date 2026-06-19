#include <bits/stdc++.h>
using namespace std;

struct lin{
	int a,b,m;
};
lin l[2000000];
int fa[200000];

int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

bool merge(int i,int j){
	i=find(i);j=find(j);
	if(i==j) return false;
	fa[i]=j;
	return true;
}

bool cmp(lin a,lin b){
	return a.m<b.m;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=0;i<m;i++){
		cin>>l[i].a>>l[i].b>>l[i].m;
	}
	sort(l,l+m,cmp); int ans=0;
	int cnt=0;int p=0;
	while(cnt<n-1){
		if(merge(l[p].a,l[p].b)){
			cnt++;
			ans+=l[p].m;
		}
		p++;
	}
	cout<<ans;
	return 0;
} 
