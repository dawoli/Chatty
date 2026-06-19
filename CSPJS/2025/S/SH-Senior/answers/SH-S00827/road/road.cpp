#include<bits/stdc++.h>
using namespace std;
struct line{
	int st,ed,l;
};
vector<line> vec;
bool cmp(line a,line b){
	return a.l<b.l;
}
int fa[10050],a[15][10050];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=0;i<n;i++){
		fa[i]=i;
	}
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		line t;
		t.st=min(u,v);
		t.ed=max(u,v);
		t.l=w;
		vec.push_back(t);
	}
	int c;
	for(int i=0;i<k;i++){
		cin>>c;
		int re;
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			if(a[i][j]==0){
				re=j;
			}			
		}
		for(int j=0;j<n;j++){
			if(re==j){
				continue;
			}
			line t;
			t.st=min(re,j);
			t.ed=max(re,j);
			t.l=a[i][j];
			vec.push_back(t);	
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	long long ans=0,cnt=0;
	for(int i=0;i<m+k*n;i++){
		int a=find(vec[i].st),b=find(vec[i].ed);
		if(a!=b){
			ans+=vec[i].l;
			fa[max(a,b)]=min(a,b);
			cnt++;
		}
		if(cnt==n-1){
			break;
		}
	}
	cout<<ans;
	return 0;
} 
