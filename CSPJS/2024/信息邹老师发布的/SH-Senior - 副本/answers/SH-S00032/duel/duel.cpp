#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m=0;
int ans=-1;
int a[N],b[N],c[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n); 
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i==1||a[i]!=a[i-1]){
			c[++m]++;
		}else c[m]++;
	}
	for(int i=1;i<=m;i++){
		int t=c[i];
		ans=max(ans,c[i]);
	}
	printf("%d",ans);
	return 0;
}
