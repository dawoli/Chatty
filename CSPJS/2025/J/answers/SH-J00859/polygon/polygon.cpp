#include<iostream>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,ans=0;
int s[5010],pl[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("potygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		pl[i]=pl[i-1]+s[i];
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			if(s[j]*2<pl[j]-pl[i-1]){
				ans++;
				ans%=mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
