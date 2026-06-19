#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=505;
const ll mod=998244353;
int n,m;
string s;
int c[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	scanf("%d%d",&n,&m);
	cin>>s;
	int maxm=0;
	for(int i=0;i<n;i++)
	  if(s[i]=='1')maxm++;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]==0)maxm--;
	}
	if(m>maxm){
		printf("0\n");
		return 0;
	}
	ll ans=1ll;
	for(int i=1;i<=maxm;i++){
		ans=(ans*i)%mod;
	}
	printf("%lld",ans);
	return 0;
}
