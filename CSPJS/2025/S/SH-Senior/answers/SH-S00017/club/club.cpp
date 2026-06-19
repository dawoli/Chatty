#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a,b,c;
};
node x[100005];
bool cmp(const node &x,const node &y){
	return x.a>y.a;
}
int t,n,ans=-1;
void dfs(int now,int cnta,int cntb,int cntc,int sum){
	if(now==n+1&&cnta<=n/2&&cntb<=n/2&&cntc<=n/2){
		ans=max(ans,sum);
		return ;
	}
	if(cnta+1<=n/2){
		dfs(now+1,cnta+1,cntb,cntc,sum+x[now].a);
	}
	if(cntb+1<=n/2){
		dfs(now+1,cnta,cntb+1,cntc,sum+x[now].b);
	}
	if(cntc+1<=n/2){
		dfs(now+1,cnta,cntb,cntc+1,sum+x[now].c);
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		bool flag=true;
		bool flag2=true;
		for(int i=1;i<=n;i++){
			cin >> x[i].a >> x[i].b >> x[i].c;
			if(x[i].c!=0){
				flag=false;
				flag2=false;
			}
			if(x[i].b!=0){
				flag=false;
			}
		}
		if(flag==true){
			sort(x+1,x+n+1,cmp);
			int sss=0;
			for(int i=1;i<=n/2;i++){
				sss+=x[i].a;
			}
			cout << sss << "\n";
		}
		else if(n<=10){
			ans=-1;
			dfs(1,0,0,0,0);
			cout << ans << "\n";
		}
		else{
			int xxx=0;
			for(int i=1;i<=n;i++){
				xxx+=max(max(x[i].a,x[i].b),x[i].c);
			}
			cout << xxx << "\n";
		}
	}
	
	
	return 0;
}
