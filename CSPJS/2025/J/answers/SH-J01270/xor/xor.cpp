#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500009;
int a[500009],s[500009];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(register int i=1;i<=n;i++)scanf("%d",&a[i]);
	register int q=1,ans=0;
	for(register int i=1;i<=n;i++){
		s[i]=(s[i-1]^a[i]);
		for(register int j=q;j<=i;j++){
			if((s[i]^s[j-1])==k){
				ans++;
				q=i+1;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}


