#include<iostream>
using namespace std;
const int N=1e5+7;
int n,a[N],ct[N],mx,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),mx=max(mx,a[i]),ct[a[i]]++;
	for(int i=1;i<=mx;i++)
		ans=max(ans,ct[i]);
	printf("%d\n",ans);
}
//
