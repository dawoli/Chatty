#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define ___ __int128
using namespace std;
const int N=1e5+5;

inline ll read() {
	ll x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int T,n,a[4][N],f[205][105][105],ans;
bool fl;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) {
		n=read();ans=0;fl=1;
		for(int i=1;i<=n;i++) {
			a[1][i]=read();a[2][i]=read();a[3][i]=read();
			if(a[2][i]!=0)fl=0;
		}
		if(n<=200) {
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;i++) {
				for(int j=0;j<=min(i,n/2);j++) {
					for(int k=0;k<=min(i,n/2);k++) {
						if(k+j>i)continue;
						if(j-1>=0)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[1][i]);
						if(k-1>=0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[2][i]);
						if(i-j-k<=min(i,n/2)&&i-j-k-1>=0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[3][i]);
						if(i==n&&j<=n/2&&k<=n/2&&i-j-k<=n/2) {
							if(ans<f[i][j][k]) {
								ans=f[i][j][k];
							}
						}
					}
				}
			}
			cout<<ans<<endl;
		}
		else if(fl) {
			sort(a[1]+1,a[1]+n+1);
			for(int i=n;i>=n/2+1;i--) ans+=a[1][i];
			cout<<ans;
		}
	}
	return 0;
}
