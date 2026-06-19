#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3+5;
ll n,ans=0;
ll x[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1; i<=n; i++)	cin >> x[i];
	for(int i=1; i<=n-2; i++){
		for(int j=i+1; j<=n-1; j++){
			for(int z=j+1; z<=n; z++){
				ll a=x[i],b=x[j],c=x[z];
				ll m = max(a,max(b,c));
				if(a+b+c<=2*m)	continue;
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
