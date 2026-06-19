#include <iostream>
using namespace std;
bool check(int a[],int l,int r,int k) {
	int re=0;
	for(int i=l; i<=r; i++) {
		re^=a[i];
	}
	if(re==k)return true;
	else return false;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[500010];
	for(int i=0; i<n; i++)cin>>a[i];
	int ans=0;
	for(int i=0; i<n; i++) {
		for(int j=i; j<n; j++) {
			if(check(a,i,j,k)) {
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
}
