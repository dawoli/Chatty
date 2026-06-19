#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	int a,b,c;
	int lamax,lbmax,lcmax;
}x[100005];
struct node2{
	int k;
	long long lmax;
}d[100005],e[100005],f[100005];
bool cmp(node2 x,node2 y){
	return x.lmax<y.lmax;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,tmpd=0,tmpe=0,tmpf=0;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].b-x[i].a>=x[i].c-x[i].a) x[i].lamax=x[i].b-x[i].a;
			else x[i].lamax=x[i].c-x[i].a;
			if(x[i].a-x[i].b>=x[i].c-x[i].b) x[i].lbmax=x[i].a-x[i].b;
			else x[i].lbmax=x[i].c-x[i].b;
			if(x[i].a-x[i].c>=x[i].b-x[i].c) x[i].lcmax=x[i].a-x[i].c;
			else x[i].lcmax=x[i].b-x[i].c;
			if(x[i].a>=x[i].b&&x[i].a>=x[i].c){
				d[++tmpd]={i,x[i].lamax};
				ans+=x[i].a;
			}
			else if(x[i].b>=x[i].a&&x[i].b>=x[i].c){
				e[++tmpe]={i,x[i].lbmax};
				ans+=x[i].b;
			}
			else if(x[i].c>=x[i].a&&x[i].c>=x[i].b){
				f[++tmpf]={i,x[i].lcmax};
				ans+=x[i].c;
			}
		}
		if(tmpd>n/2){
			sort(d+1,d+tmpd+1,cmp);
			while(tmpd>n/2){
				ans+=d[tmpd--].lmax;
			}
		}
		if(tmpe>n/2){
			sort(e+1,e+tmpe+1,cmp);
			while(tmpe>n/2){
				ans+=e[tmpe--].lmax;
			}
		}
		if(tmpf>n/2){
			sort(f+1,f+tmpf+1,cmp);
			while(tmpf>n/2){
				ans+=f[tmpf--].lmax;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
