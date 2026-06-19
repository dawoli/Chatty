#include<bits/stdc++.h>
using namespace std;
int a[500010],cnt=0;
struct node{
	int l,r;
}b[1000010];
bool cmp(node a,node b){return a.r<b.r;}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,r=0,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=i;j<=n;j++){
			s^=a[j];
			if(s==k)b[++cnt].l=i,b[cnt].r=j;
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(b[i].l>r)ans++,r=b[i].r;
	}
	cout<<ans;
	return 0;
}
