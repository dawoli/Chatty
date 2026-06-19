#include<bits/stdc++.h>
using namespace std;
int T,n,cnt[4],ans;
struct Node{
	int a,b,c;
}x[100005]; 
int MAX(Node g){
	return max(g.a,max(g.b,g.c));
}
int MAXNUM(Node g){
	if(g.a>g.b&&g.a>g.c)return 1;
	if(g.b>g.c&&g.b>g.a)return 2;
	return 3;
}
int MID(Node g){
	if(g.a>g.b&&g.a<g.c||g.a>g.c&&g.a<g.b)return g.a;
	if(g.b>g.a&&g.b<g.c||g.b<g.a&&g.b>g.c)return g.b;
	return g.c;
}
int MIDNUM(Node g){
	if(g.a>g.b&&g.a<g.c||g.a>g.c&&g.a<g.b)return 1;
	if(g.b>g.a&&g.b<g.c||g.b<g.a&&g.b>g.c)return 2;
	return 3;
}
bool cmp(Node p,Node q){
	return (MAX(p)-MID(p))>(MAX(q)-MID(q));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x[i].a,&x[i].b,&x[i].c);
		}
		sort(x+1,x+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[MAXNUM(x[i])]<n/2){
				cnt[MAXNUM(x[i])]++;
				ans+=MAX(x[i]);
			}
			else{
				cnt[MIDNUM(x[i])]++;
				ans+=MID(x[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
