#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500009;
int a[N];
bool ok[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	ll k;
	cin>>n>>k;
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			ok[i]=1;
		}
	}
	ll sub=0;
	for(int i=1;i<=n;i++){
		if(ok[i]) continue;
		for(int j=i;j<=n;j++){
			if(j==i&&!ok[j]){
				sub=a[j];
			}else if(ok[j]){
				break;
			}else{
				sub=sub^a[j];
				if(sub==k&&!ok[j]){
					ans++;
					ok[j]=1;
					i=j+1;
					j=i;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
