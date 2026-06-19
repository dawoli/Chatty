#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define ll long long
int n;
int a[N];
int pre,cnt,maxcnt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	pre=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]==pre)cnt++;
		else pre=a[i],cnt=0;;
		maxcnt=max(maxcnt,cnt);
	}
	ll ans=maxcnt+1;
	printf("%d",ans);
	return 0;
}
