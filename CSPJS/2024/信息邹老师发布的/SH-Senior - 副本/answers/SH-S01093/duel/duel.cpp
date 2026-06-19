#include <bits/stdc++.h>
using namespace std;
int r[100001];
int a[100001];
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>r[i];
	sort(r+1,r+n+1);
	int j=1,sum=0,num=r[1];
	for(int i=1; i<=n; i++) {
		if(r[i]==num) {
			sum++;
		} else {
			a[j]=sum;
			sum=1;
			j++;
			num=r[i];
		}
	}
	a[j]=sum;
	for(int i=2; i<=j; i++) {
		if(a[i]>=a[i-1]) {
			a[i]=a[i];

		} else {
			a[i]+=abs(a[i]-a[i-1]);
		}
	}
	cout<<a[j];
	return 0;
}
