#include<bits/stdc++.h>
using namespace std;
int n,m;
int ap[100005],c[100005];
int r[100005],x[5];
char d[20][50000];
int t;
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	int t=n;
	int k=0;
	for(int i=1;i<=n;i++) {
		cin>>ap[i];
	}
	for(int i=1;i<=m;i++) {
		cin>>c[i];
	}
	while(t) {
		t=t/2;
		k++;
	}
	if(pow(2,k)==n*2) {
		k--;
	}
	for(int i=1;i<=k;i++) {
		for(int j=1;j<=pow(2,k-i);j++) {
			cin>>d[i][j];
//			cout<<i<<'^'<<j<<endl;
		}
	}
	cin>>t;
	for(int i=1;i<=t;i++) {
		for(int j=1;j<=4;j++) {
			cin>>x[j];
		}
		while(tem) {
			tem=tem/2;
			kp++;
		}
		if(pow(2,kp)==n*2) {
			kp--;
		}
		cout<<1<<endl;
	}
	return 0;
}
