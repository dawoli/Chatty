#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n;
struct node{
	int a,b,c;
}w[N];
bool cmd(node a,node b){
	return a.a>b.a;
}
void solve(){
	int amx=0,bmx=0,cmx=0,ans=0;
	bool sp1=1,sp2=1;
	cin>>n;
	int mid=n/2;
	for(int i=1;i<=n;i++){
		cin>>w[i].a>>w[i].b>>w[i].c;
		if(w[i].b!=0)sp1=0;
		if(w[i].c!=0)sp2=0;
	}
	if(n==2){
		ans=max({w[1].a+w[2].b,w[1].b+w[2].c,w[1].c+w[2].a,w[1].a+w[2].c,w[1].b+w[2].a,w[1].c+w[2].b});
		cout<<ans<<endl;
		return ;
	}
	else if(sp1&&sp2){
		sort(w+1,w+n+1,cmd);
		for(int i=1;i<=mid;i++){
			ans+=w[i].a;
		}
		cout<<ans<<endl;
		return ;
	}
	else if(sp2){
		int los[N];
		for(int i=1;i<=n;i++){
			los[i]=abs(w[i].a-w[i].b);
		}
	}else{
		for(int i=1;i<=n;i++)ans+=max({w[i].a,w[i].b,w[i].c});
		cout<<ans<<endl;
		return ;
	}
	/*for(int i=1;i<=n;i++){
		int mx=max({w[i].a,w[i].b,w[i].c});
		if(w[i].a==mx){
			w[i].wh=1;
			amx++;
			ans+=mx;
			if(w[i].b>=w[i].c)se=2;
			else se=3;
		}
		else if(w[i].b==mx){
			w[i].wh=2,bmx++,ans+=mx;
			if(w[i].a>=w[i].c)se=1;
			else se=3;
		}
		else{
			w[i].wh=3,cmx++,ans+=mx;
			if(w[i].a>=w[i].b)se=1;
			else se=2;
		} 
	}
	while(amx>mid){
		
	}*/ 
} 
 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	cin>>_;
	while(_--){
		solve();
	}
} 
