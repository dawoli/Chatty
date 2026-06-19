#include<iostream>
#include<algorithm>
using namespace std;
long long r[100005];
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+n+1);
	long long pos=1;
	for(long long i=1;i<=n;i++) {
		while(r[pos]<=r[i]&&pos<=n) pos++;
		pos++;
		if(pos>n&&r[n]>r[i]) {
			cout<<n-i;
			return 0;
		}
		else if(pos>n) {
			cout<<n-i+1;
			return 0;
		}
	}
	return 0;
}
