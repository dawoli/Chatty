#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x) {
    x=0;bool f=0;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=1;ch=getchar();}
    while(ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    f?x=-x:0;
}
template<typename type, typename ...T>
inline void read(type &x,T &...y) {
    read(x);
    read(y...);
}
const int N=2e5+10;
int t,n,a[N],dp[N][2];// 0 red, 1 blue
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	read(t);
	while(t--) {
		read(n);
		for (int i=1;i<=n;i++) {
			read(a[i]);
		}
		/*
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=n;i++) {
			for (int j=i-1;j>=1;j--) {
				if (a[i]==a[j]) {
					dp[i][1]=max(dp[i][1],dp[i-1][0]+a[j]);
					dp[i][0]=max(dp[i][0],dp[i-1][1]+a[j]);
				}
			}
		}
		cout<<max(dp[n][0],dp[n][1])<<endl;
		*/
		if (n<=100) {
			long long ansall=-1;

			for (int i=0;i<(1<<n);i++) {
				int b=0,r=0;
				long long ans=0;
				for (int j=1;j<=n;j++) {
					if ((i>>(j-1))&1) {
						if(b&&a[j]==a[b]) ans+=a[j];
						b=j;
					} else {
						if (r&&a[j]==a[r]) ans+=a[j];
						r=j;
					}
				}
				ansall=max(ans,ansall);
			}
			cout<<ansall<<endl;
		}
	}
	return 0;
}
