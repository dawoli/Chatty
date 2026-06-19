#include<bits/stdc++.h>
using namespace std;
int n,k,sum[500005],a[500005],ans=0,cnt;
struct node{
	int l,r;
}b[500005];
bool cmp(node a,node b){
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
		return 0;
	} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[i-1]^sum[j])==k){
				++cnt;
				b[cnt].l=i;
				b[cnt].r=j;
				break;
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	int mr=-1;
	for(int i=1;i<=n;i++){
		if(mr<b[i].l){
			mr=b[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
