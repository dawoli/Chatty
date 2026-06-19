#include<bits/stdc++.h>
using namespace std;
int n,q,x,y;
string s,t,a[200010],b[200010];
struct node{
    int p,q,r,o;
}c[200010];
vector<node> d[400020];

//17:58 maybe 5tps
//18:00 maybe 0tps
//18:12 25tps I think(maybe not)

bool cmp(node a,node b){
	int x=min(a.p,a.q);
	int y=min(b.p,b.q);
	return x<y;
}
/*
int find(int x,int y){
	int l=0,r=d[x].size()-1;
	if(r<l)return 0;
	while(l<r){
		int mid=(l+r)/2;
		int k=min(d[x][mid].p,d[x][mid].q);
		if(k<p)return;
	}
}*/

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i].size();j++){
			if(a[i][j]=='b')c[i].p=j,c[i].r=a[i].size()-j-1;
			if(b[i][j]=='b')c[i].q=j,c[i].o=a[i].size()-j-1;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s>>t;
		for(int j=0;j<s.size();j++){
			if(s[j]=='b')x=j;
			if(t[j]=='b')y=j;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(x-y!=c[i].p-c[i].q)continue;
			if(x>=c[i].p && s.size()-x-1>=c[i].r)ans++;
		}
		cout<<ans<<endl;
	}
}
