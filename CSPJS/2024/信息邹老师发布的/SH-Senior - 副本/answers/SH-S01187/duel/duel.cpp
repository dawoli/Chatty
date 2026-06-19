#include<bits/stdc++.h>
#define int long long
#define maxn 123456
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,a[maxn],NxtLvl[maxn],cnt,ans,sum;
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		if(a[i]!=a[i-1])NxtLvl[++cnt]=i-1;
	ans=n;
	for(int i=1;i<=cnt;i++){
		int tmp=NxtLvl[i]-NxtLvl[i-1];
		if(tmp<=n-sum-tmp){
			sum+=tmp;
			ans-=tmp;
		}
		else{
			ans-=(n-sum-tmp);
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}

// code written by luogu user #951212
