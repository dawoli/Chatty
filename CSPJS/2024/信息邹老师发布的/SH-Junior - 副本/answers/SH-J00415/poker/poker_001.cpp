#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const char wp[20]="#A23456789TJQK";
const char wq[10]="#DCHS";
ll n,ans;
bitset<17000>a;
int main(){
	char rx[5];
	//*/
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	//*/
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%s",rx);
		a[rx[0]*128+rx[1]]=1;
	}
	for(ll i=1;i<=13;i++)
		for(ll j=1;j<=4;j++)
			ans+=a[wq[j]*128+wp[i]];
	printf("%lld",52-ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}