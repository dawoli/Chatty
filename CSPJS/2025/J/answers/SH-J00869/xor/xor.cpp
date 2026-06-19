#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],sum[500005];
struct node{
	int l,r;
}s[500005];
int cnt=0;
bool cmp(node a,node b){
	if(a.r==b.r)return a.l>b.l;
	return a.r>b.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
   		cin>>a[i];
		sum[i+1]=sum[i]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k)
			{
				s[cnt++]={i,j};
			}	
		}
	}
	sort(s,s+cnt,cmp);
	int ans=0,ll=0x7ffffff;
	for(int i=0;i<cnt;i++){
		if(s[i].r<ll){
			ans++;
			ll=s[i].l;
		}
		else if(s[i].l>ll){
			ll=s[i].l;
		}
	}
	cout<<ans;
	return 0;
}
