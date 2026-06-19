#include <bits/stdc++.h>
using namespace std;
char temp[510];
long long c[510];
string s;
bool visited[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,failed = 0;
	scanf("%lld%lld",&n,&m);
	scanf("%s",&temp);
	for (long long i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	while (true){
		long long delta = 0;
		for (long long i=1;i<=n;i++){
			if (failed>=c[i] && !visited[i]){
				delta++;
				visited[i] = true;
			}
		}
		if (delta==0){
			break;
		}
	}
	if (n-failed<m){
		printf("0");
		return 0;
	}
	long long ans = 1;
	for (long long i=1;i<=m;i++){
		ans = ans*i%998244353;
	}
	printf("%lld",ans%998244353);
	return 0;
}
