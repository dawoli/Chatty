#include<bits/stdc++.h>
using namespace std;
long long s;
int n;
vector<int>a;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3) {
		cout<<0;
		return 0;
	}
	if(n==3){
		cout<<1;
		return 0;
	}
	for(int i=0;i<n;++i) {
		int A;
		cin>>A;
		a.insert(a.end(),A);
	}
	sort(a.begin(),a.end());
	for(int i=2;i<n;++i) {
		int p,u=a[0]+a[1];
		if(u>a[i]) {
			p=i-1;
			long long P=1;
			for(int j=1;j<=p;++j) {
				P*=j;
			}
//			cout<<u<<" "<<i<<endl;
			s+=P%998244353;
			continue;
		}
		for(int j=2;j<i;++j) {
			u+=a[j]-a[j-2];
			if(u>a[i]) {
				p=i-1;
				long long P=1;
				for(int k=1;k<=p;++k) {
					P*=k;
				}
//				cout<<u<<" "<<i<<" "<<j<<" "<<p<<endl;
				s+=P%998244353;
				break;
			}
		}
	}
	cout<<s;
//	cout<<(s-25)/5*3+6;
	return 0;
}
