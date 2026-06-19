#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}s[1000007];
bool cmp(node x,node y){
	return x.c<y.c;
}
int fa[1001];
int find(int x){
	if(fa[x]==x)return x;
	else return find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)fa[i]=i;
		int ans=0;
		for(int i=1;i<=m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			s[i].a=x,s[i].b=y,s[i].c=z;
		}
		if(k==0){
		sort(s+1,s+1+m,cmp);
		for(int i=1;i<=m+k;i++){
			int q=find(s[i].a),w=find(s[i].b);
			if(q==w)continue;
			else {
				fa[q]=w;
				ans+=s[i].c;
			}
		}
		cout<<ans<<endl;
		return 0;	
		}
		bool q=true;
		int d[k+1]={};
	for(int i=1;i<=k;i++){
		cin>>d[i];
		if(d[i]!=0)q=false;
		for(int j=1;j<=n;j++){
		cin>>s[m+j].c;
		s[m+j].a=m+i;
		s[m+j].b=j;
	}
	}
	if(q){
	sort(s+1,s+1+m+n*k,cmp);
	for(int i=1;i<=m+n*k;i++){
			int q=find(s[i].a),w=find(s[i].b);
			if(q==w)continue;
			else {
				fa[q]=w;
				ans+=s[i].c;
			}
		}
		cout<<ans<<endl;
	return 0;
}
	else{
		if(k==1){
			int ans1=d[1];
			sort(s+1,s+1+m,cmp);
		for(int i=1;i<=m;i++){
			int q=find(s[i].a),w=find(s[i].b);
			if(q==w)continue;
			else {
				fa[q]=w;
				ans+=s[i].c;
			}
		}
		sort(s+1,s+1+m+n*k,cmp);
	for(int i=1;i<=m+n*k;i++){
			int q=find(s[i].a),w=find(s[i].b);
			if(q==w)continue;
			else {
				fa[q]=w;
				ans1+=s[i].c;
			}
		}
		ans=max(ans,ans1);
		cout<<ans<<endl;
		return 0;
		}
		else {
		sort(s+1,s+1+m,cmp);
		for(int i=1;i<=m+k;i++){
			int q=find(s[i].a),w=find(s[i].b);
			if(q==w)continue;
			else {
				fa[q]=w;
				ans+=s[i].c;
			}
		}
		cout<<ans<<endl;
		return 0;
			
		}
	}
	return 0;
}
