#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
int a[N][4];
int b[N];
long long ans=0;
bool cmp(int a,int b) {
	return a>b;
}
void solveA() {
	sort(b+1,b+n+1,cmp);
	long long ans=0;
	for(int i=1;i<=n/2;i++) {
		ans+=b[i];
	}
	cout<<ans<<endl;
}
int q[32],y[4];
void search(int x) {
	if (x==n+1) {
		long long tmp=0;
		for (int i=1;i<=n;i++) {
			tmp+=a[i][q[i]];
		}
		ans=max(ans,tmp);
	}
	for (int i=1;i<=3;i++) {
		if (y[i]<n/2) {
			q[x]=i;
			y[i]++;
			search(x+1);
			y[i]--;
		}
		
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		ans=0;
		for (int i=1;i<=4;i++) {
			y[i]=0;
		}
		bool flag=1;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=3;j++) {
				cin>>a[i][j];
			}
			b[i]=a[i][1];
			if(a[i][2]!=0||a[i][3]!=0) {
				flag=0;
			}
		}
		if(flag==1) {
			solveA();
			continue;
		}
		search(1);
		cout<<ans<<endl;
	}
	return 0;
}

