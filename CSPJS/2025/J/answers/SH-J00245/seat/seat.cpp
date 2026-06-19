#include<bits/stdc++.h>
using namespace std;
const int KS=110;
int a[KS];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=0;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	int target=0;
	bool o=0;
	for(int i=1; i<=n*m; i++) {
		if(a[i]==t) {
			target=i;
			break;
		}
	}
	int cnt=0;
	while(target-n>=0) {
		target-=n;
		o^=1;
		cnt++;
	}
	if(target==0) {
		if(o==1) {
			cout<<cnt<<" "<<n<<"\n";
		} else {
			cout<<cnt<<" "<<1<<"\n";
		}
		return 0;
	}
	cnt++;
	if(o==0) {
		cout<<cnt<<" "<<target<<"\n";
	} else {
		cout<<cnt<<" "<<n-target+1<<"\n";
	}
	return 0;
}
