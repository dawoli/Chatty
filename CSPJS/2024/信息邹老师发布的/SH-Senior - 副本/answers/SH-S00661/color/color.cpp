#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[200005];
int c[200005];
int dp[200005][3];
int nus[1000001];
int color[200005];
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		int maxa=0;
		int mana=-1;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			dp[i][1]=0;
			dp[i][2]=0;
			nus[a[i]]++;
			maxa=max(maxa,a[i]);
		}
		int flag=0;
		for(int i=1;i<=maxa;i++) {
			if(nus[i]>1) {
				flag=1;
			}
	//		cout<<i<<':'<<nus[i]<<endl;
			if(nus[i]==n) {
				flag=2;
				mana=a[i];
				break;
			}
		}
		if(flag==0) {
			for(int i=1;i<=maxa;i++) {
				nus[i]=0;
			}
			cout<<0<<endl;
			continue;
		}
		if(flag==2) {
			for(int i=1;i<=maxa;i++) {
				nus[i]=0;
			}
			cout<<mana*(n-1)<<endl;
			continue;
		}
		int ansa=0;
		for(int i=1;i<=pow(2,n);i++) {
			int temp=i;
			int k=n;
			while(temp) {
				color[k]=temp%2;
				temp/=2;
				k--;
			}
			c[1]=0;
			for(int j=2;j<=n;j++) {
				c[j]=0;
				for(int k=j-1;k>=1;k--) {
					if(a[j]==a[k]&&color[j]==color[k]) {
						c[j]=a[j];
						break;
					}
				}
			}
			int ans=0;
			for(int j=1;j<=n;j++) {
				ans+=c[j];
			}
			ansa=max(ansa,ans);
		}
		cout<<ansa<<endl;
		for(int i=2;i<=n;i++) {
			int dis;
			for(int j=1;j<i;j++) {
				if(a[i]==a[j]) {
					dis=i-j+1;
				}
			}
		}
		for(int i=1;i<=maxa;i++) {
			nus[i]=0;
		}
	}
	return 0;
}
