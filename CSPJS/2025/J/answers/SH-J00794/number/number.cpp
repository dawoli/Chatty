#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+9;
char s[N];
ll cntnum[20];
//FC 5.71s ??????
//bad computer!
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	ll n=strlen(s+1);
	for(ll i=1;i<=n;i++)
		if('0'<=s[i]&&s[i]<='9') cntnum[s[i]-'0']++;
	ll sum=0;
	for(ll i=1;i<=9;i++) sum+=cntnum[i];
	if(sum==0){
		puts("0");
		return 0;
	}
	for(ll i=9;i>=0;i--){
		for(ll j=1;j<=cntnum[i];j++) printf("%lld",i);
	}
	return 0;
}
