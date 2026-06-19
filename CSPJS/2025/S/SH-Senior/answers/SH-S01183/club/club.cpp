#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,n1;
struct node{
	int a,b,c;
}s[N];
bool cmp(node x,node y){
	return x.a>y.a;
}
int ans=0;
void dfs(int u,int a,int b,int c,int sum){
	if(u==n+1){
		ans=max(ans,sum);
		return ;
	}
	int fr,tf,se,ts;
	if(s[u].a>=s[u].b){
		fr=s[u].a;
		tf=1;
		se=s[u].b;
		ts=2;
	}else{
		fr=s[u].b;
		tf=2;
		se=s[u].a;
		ts=1;
	}
	if(s[u].c>=fr){
		se=fr;
		ts=tf;
		fr=s[u].c;
		tf=3;
	}else{
		if(s[u].c>=se){
			se=s[u].c;
			ts=3;
		}
	}
	if(tf==1&&a+1<=n1)dfs(u+1,a+1,b,c,sum+fr);
	else if(tf==2&&b+1<=n1)dfs(u+1,a,b+1,c,sum+fr);
	else if(tf==3&&c+1<=n1)dfs(u+1,a,b,c+1,sum+fr);
	if(ts==1&&a+1<=n1)dfs(u+1,a+1,b,c,sum+se);
	else if(ts==2&&b+1<=n1)dfs(u+1,a,b+1,c,sum+se);
	else if(ts==3&&c+1<=n1)dfs(u+1,a,b,c+1,sum+se);
	return ;
}
void dfs1(int u,int a,int b,int sum){
	if(u==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(a+1<=n1)dfs1(u+1,a+1,b,sum+s[u].a);
	if(b+1<=n1)dfs1(u+1,a,b+1,sum+s[u].b);
}
void solve(){
	bool A=1,B=1;
	ans=0;
	cin>>n;
	n1=n/2;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
		if(s[i].b!=0)B=0;
		if(s[i].b!=0||s[i].c!=0)A=0;
	}
	if(A){
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n1;i++){
			ans+=s[i].a;
		}
		cout<<ans<<"\n";
	}else if(B){
		dfs1(1,0,0,0);
		cout<<ans<<"\n";
	}else{
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
