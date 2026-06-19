#include <cstdio>
#include <cctype>
#include <vector>
#include <iostream>
using namespace std;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int N=1e5+5;
const int L=2e5+5;
const int R=105;
int n,k,q,l[N];
vector<int> a[N];
vector<int> f[R][L];
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t=read();
	while(t--) {
		n=read(),k=read(),q=read();
		int MAX=0;
		for(int i=1;i<=n;i++) {
			l[i]=read();
			int lst=-k-1;
			for(int j=1;j<=l[i];j++) {
				int x=read(); MAX=max(MAX,x);
				if(i-lst+1>=2 and i-lst+1<=k)
					f[1][x].push_back(i);
				if(x==1) lst=x;
				a[i].push_back(x);
			}
		}
		for(int i=1;i<=100;i++)for(int j=1;j<=MAX;j++) {
			for(int p=0;p<f[i][j].size() and p<2;p++) {
				int id=f[i][j][p];
				for(int y=1;y<=n;y++)if(y!=id)
				for(int x=1;x<=l[y];x++)if(a[y][x-1]==j)
				for(int z=x+1;z<=l[y] and z<=x+k-1;z++)
					f[i+1][a[y][z-1]].push_back(y);
			}
		}
		while(q--) {
			int r=read(),e=read();
			if(f[r][e].size()) puts("1");
			else puts("0");
		}
		for(int i=1;i<=100;i++)for(int j=1;j<=MAX;j++)
			f[i][j].clear();
		for(int i=1;i<=n;i++) a[i].clear();
	}
	return 0;
}
