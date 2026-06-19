#include<bits/stdc++.h>
using namespace std;
int n,m;
int r[100005];
bool a[100005];
bool cmp(int a,int b) {
	return a<b;
}
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	m=n;
	for(int j=1;j<=n;j++) {
		cin>>r[j];
	}
	sort(r+1,r+n+1,cmp);
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			if(r[j]>r[i]&&!a[j]) {
				a[j]=1;
				m--;
				break;
			}
		}
	}
	cout<<m;
	return 0;
}
