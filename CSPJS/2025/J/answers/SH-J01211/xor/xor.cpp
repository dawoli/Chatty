#include<bits/stdc++.h>
using namespace std;
int a[500001];
int pre[500001];
int n,k;
struct node{
	int l,r;
}c[500002];
bool cmp(node &a,node &b){
	return a.r==b.r?a.l<b.l:a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]^a[i];
	}
	int poi=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int f=pre[j]^pre[i-1];
			if(f==k){
				c[poi].l=i;
				c[poi].r=j;
				poi++;
			}
		}
	}sort(c,c+poi,cmp);
	int maxr=c[0].r;
	int ans=1;
	for(int i=1;i<poi;i++){
//		cout<<c[i].l<<' '<<c[i].r<<endl;
		if(c[i].l<=maxr||c[i].r<=maxr){
			continue;
		}ans++;
		maxr=max(maxr,c[i].r);
	}cout<<ans<<endl;
	return 0;
}
