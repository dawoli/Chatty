#include <iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long cnt=0;
	long long l=0,r;
	for(long long i=n;i>=2;i--){
		l=0;
		r=l+i;
		while(r<n){
			long long maxn=0;
			long long cntn=0;
			for(long long j=l;j<=r;j++){
				cntn+=a[j];
				maxn = max(maxn,a[j]);
			}
			if(cntn>=maxn*2){
				cnt++;
			}
			l++;
			r++;
		}
	}
	cout<<cnt%998244353;
	return 0;
}
