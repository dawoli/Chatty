#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt,f1[500005],ans;
struct node{
	int l,r;
}alr[1000005];
bool cmp(node x,node y){
	if(x.l!=y.l)return x.l<y.l;
	return x.r<y.r;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((a[r]^a[l-1])==k){
				alr[++cnt].l=l;
				alr[cnt].r=r;
			}
		}
	}
	sort(alr+1,alr+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int l=alr[i].l;
		int r=alr[i].r;
		bool f=0;
		for(int j=l;j<=r;j++){
			if(f1[j])f=1;
		}
		if(f==0){
			for(int j=l;j<=r;j++){
				f1[j]=1;
			}
			ans++;
		}
	}
	cout<<ans;
}
