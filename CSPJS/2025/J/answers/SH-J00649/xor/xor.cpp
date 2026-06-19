#include<bits/stdc++.h>
using namespace std;
int n,k,a[500003],sum[500003];
struct node{int l,r;}q[5000010];
int cnt;
bool cmp(node x,node y){
	if(x.r==y.r)return x.l<y.l;
	else return x.r<y.r;
}
int f(int l,int r){return sum[r]^sum[l-1];}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;	
	for(int i=1;i<=n;i++)cin>>a[i];
	

	for(int i=1;i<=n;i++)sum[i]=sum[i-1]^a[i];
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f(i,j)==k){
				node u;u.l=i,u.r=j;q[++cnt]=u;
				break; 
			}
		}
	}
	if(cnt==0){cout<<0;return 0;}

	sort(q+1,q+cnt+1,cmp);
		
	int ans=1,last=q[1].r;
	for(int i=2;i<=cnt;i++){
		if(last<q[i].l)ans++,last=q[i].r;
	}
	cout<<ans;	
}
