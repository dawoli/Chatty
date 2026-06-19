#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> a;
int u(int x,int y) {
	if(x==y) {
		if(a[x]==k) return 1;
		return 0;
	}
	int m=0;
	for(int i=x;i<y;i++) {
		int s=a[i];
		if(s==k) {
			m++;
			continue;
		}
		for(int j=i+1;j<y;j++) {
			s=s^a[j];
			if(s==k) {
				m++;
				i=j;
				break;
			}
		}
	}
//	cout<<x<<" "<<y<<" "<<m<<endl;
	for(int i=x;i<y;i++) {
		m=max(m,u(x,i)+u(i+1,y));
	}
	return m;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		int A;
		cin>>A;
		a.insert(a.end(),A);
	}
	cout<<u(0,n);
	return 0;
}
