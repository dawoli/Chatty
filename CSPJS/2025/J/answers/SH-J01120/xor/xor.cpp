#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n<<endl;
	}
	else
	{
		long long ans=0;
		for(long long i=1;i<=n;){
			long long ss=(a[i] xor a[i+1]);
			if(ss==k){
				ans++;i=i+2;continue;
			}
			long long y=i;
			for(long long j=i+2;j<=n;j++){
				if((ss xor a[j])==k){
					ans++;
					i=j+1;
				}
			}
			if(i==y){
				i++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
