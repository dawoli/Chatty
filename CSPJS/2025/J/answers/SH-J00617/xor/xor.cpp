#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int sum[500010];
long long ans=0;
struct NODE{
	int l,r;
};
vector<NODE>b;
bool cmp(NODE a,NODE b){
	if(a.l!=b.l)return a.l<b.l;
	else return a.r<b.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=a[i]^sum[i-1];
	}
//	for(int i=1;i<=n;i++){
//		printf("%d ",sum[i]);
//	}
	//puts("");
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((sum[r]^sum[l-1])==k){
				b.push_back({l,r});
				//printf("%d %d\n",l,r);
			}
		}
	}
	sort(b.begin(),b.end(),cmp);
	int r=0;
	for(auto v:b){
		if(v.l>r){
			ans++;
			r=v.r;
		}
		else{
			if(v.r<r){
				r=v.r;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
	
}
