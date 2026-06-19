#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define Rep(i,l,r) for(int i=(l);i>=(r);--i)
#define int long long
#define INF 1e18
#define gc getchar()
using namespace std;
namespace fastIO{
	int read(){
		int x=0,f=1;
		char ch=gc;
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=-1;
			ch=gc;
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+(ch-'0');
			ch=gc;
		}
		return x*f;
	}
}
using namespace fastIO;
int n;
int a[100009][4];
int ans;
priority_queue<int> q[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--){
		n=read();
		rep(i,1,3){
			while(!q[i].empty()) q[i].pop();
		} 
		ans=0;
		rep(i,1,n){
			rep(j,1,3){
				a[i][j]=read();
			}
			int ch,val;
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				ch=1,val=max(a[i][2],a[i][3])-a[i][1];
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				ch=2,val=max(a[i][1],a[i][3])-a[i][2];
			}
			else{
				ch=3,val=max(a[i][1],a[i][2])-a[i][3];
			}
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
			q[ch].push(val); 
		}
		int mx=0;
		rep(i,1,3){
			if(q[i].size()>(n/2)){
				mx=i;
			}
		}
		if(mx==0){
			cout<<ans<<endl;
			continue;
		}
		while(q[mx].size()>(n/2)){
			ans+=q[mx].top();
			q[mx].pop();
		}
		cout<<ans<<endl; 
	} 
	return 0;
}

