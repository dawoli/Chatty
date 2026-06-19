#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
struct node{
	int n;
	int x;
	int r;
}p[100005];
bool cmp(node a,node b){
	return a.n>b.n;
}
int ss[4],vis[4];
int ans=0;
int n;
void dfs(int step,int s1,int s2,int s3,int sum){
	if(step==n)
	{
		ans=max(ans,sum);
		return;
	}
	if(s1<n/2)dfs(step+1,s1+1,s2,s3,sum+a[step]);
	if(s2<n/2)dfs(step+1,s1,s2+1,s3,sum+b[step]);
	if(s3<n/2)dfs(step+1,s1,s2,s3+1,sum+c[step]); 
}
void solve(){
	vis[1]=1,vis[2]=1,vis[3]=1;
	ans=0;
	cin>>n;
	int flag=1;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(a[i]>=b[i]&&a[i]>=c[i])
			p[i]={a[i],1,i};
		else if(b[i]>=a[i]&&b[i]>=c[i])
			p[i]={b[i],2,i};
		else if(c[i]>=a[i]&&c[i]>=a[i])
			p[i]={c[i],3,i};
		if(c[i]!=0)flag=0;
	}
	if(n<=10){
		dfs(0,0,0,0,0);
		cout<<ans<<"\n";
		return;
	}
	if(flag){
		sort(p,p+n,cmp);
		for(int i=0;i<n;i++){
			ans+=p[i].n;
		}
	}
	sort(p,p+n,cmp);
	for(int i=0;i<n;i++){
		ans+=p[i].n;
		ss[p[i].x]++;
		if(ss[p[i].x]==n/2){
			vis[p[i].x]=0;
			for(int j=i+1;j<n;j++){
				if(p[j].x==p[i].x)
				{
					int ss1=(vis[1]==0?-1:a[p[j].r]);
					int ss2=(vis[2]==0?-1:b[p[j].r]);
					int ss3=(vis[3]==0?-1:c[p[j].r]);
					if(ss1>=ss2&&ss1>=ss3)
						p[j].n=ss1,p[j].x=1;
					else if(ss2>=ss1&&ss2>=ss3)
						p[j].n=ss2,p[j].x=2;
					else if(ss3>=ss1&&ss3>=ss1)
						p[j].n=ss3,p[j].x=3;
				}
				sort(p+i+2,p+n,cmp);
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0; 
}
