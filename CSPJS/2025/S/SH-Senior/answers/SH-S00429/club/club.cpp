#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,idx,c,y,x,p[5];
ll ans;
bool vis[100005];
struct node{
	int v,q,id;
}a[300005];
bool cmp(node a,node b){
	return a.q>b.q;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0; 
		p[1]=n;
		p[2]=0;
		p[3]=0;
		for(int i=1;i<=n;++i){
			vis[i]=0;
			a[2*i-1].v=0;
			a[2*i-1].id=0;
			a[2*i-1].q=0;
			a[2*i].v=0;
			a[2*i].id=0;
			a[2*i].q=0;
		}
		for(int i=1;i<=n;++i){
			cin>>c>>y>>x;
			a[2*i-1].v=2;
			a[2*i-1].q=y-c;
			a[2*i-1].id=i;
			a[2*i].v=3;
			a[2*i].q=x-c;
			a[2*i].id=i;
			ans+=c;
		}
		sort(a+1,a+1+2*n,cmp);
		int i;
		for(i=1;p[1]>n/2&&i<=2*n;++i){
			if(vis[a[i].id]==1||p[a[i].v]>=n/2)	continue;
			vis[a[i].id]=1;
			p[1]--;
			p[a[i].v]++;
			ans+=a[i].q;
		}
		for(;a[i].q>=0&&i<=2*n;++i){
			if(vis[a[i].id]==1||p[a[i].v]>=n/2||p[1]<=0)	continue;
			vis[a[i].id]=1;
			p[1]--;
			p[a[i].v]++;
			ans+=a[i].q;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
