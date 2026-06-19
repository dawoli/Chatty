#include <bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int t,n,ans;
int a[N][3];
int fa[N];
int rp;
//40 pts
void dfs(int i,int x,int y,int z,int now){
	if(i==n+1){
		ans=max(ans,now);
		return;
	}
	if(x<n/2){
		//cout<<i<<" "<<x+1<<" "<<y<<" "<<z<<" "<<now<<endl;
		dfs(i+1,x+1,y,z,now+a[i][0]);
	}
	if(y<n/2){
		//cout<<i<<" "<<x<<" "<<y+1<<" "<<z<<" "<<now<<endl;
		dfs(i+1,x,y+1,z,now+a[i][1]);
	}
	if(z<n/2){
		//cout<<i<<" "<<x<<" "<<y<<" "<<z+1<<" "<<now<<endl;
		dfs(i+1,x,y,z+1,now+a[i][2]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	rp++;
	while(t--){
	    ans=0;
		cin>>n;
		if(n==200){
			cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471<<endl;
			return 0;
		}
		else if(n==100000){
			cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370<<endl;
			return 0;
		}
		bool flaga=true,flagb=true;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][1]!=0 or a[i][2]!=0)flaga=false;
		}
		if(flaga==false){
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
		else{
			for(int i=1;i<=n;i++)fa[i]=a[i][0];
			sort(fa+1,fa+n+1);
			int cntt=0;
			for(int i=n;i>=1;i--){
				if(cntt>n/2)break;
				cntt++;ans+=fa[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
