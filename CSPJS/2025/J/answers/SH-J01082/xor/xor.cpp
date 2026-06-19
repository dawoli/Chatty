#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n,k,a[N],cnt;
struct node{
	int l,r;
}p[N];
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int sum=0,x=-1;
		for(int j=i;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				x=j;break;
			}
		}
		if(x!=-1){
			p[++cnt].l=i;
			p[cnt].r=x;
		}
	}
	sort(p+1,p+cnt+1,cmp);
	int r=0,ans=0;
	for(int i=1;i<=cnt;i++){
		if(p[i].l<=r) continue;
		ans++;r=p[i].r;
	}
	cout<<ans<<"\n";
	return 0;
}

