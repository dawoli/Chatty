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
const int N=1e5+10;
int t,n,m,a[N],c[N],d[100][100];
int X[4];

int zhenglog2(int x) {
	int y=log2(x);
	if (pow(2,y)<x) {
		return y+1;
	}
	return y;
}

int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	read(t);
	while(t--) {
		read(n,m);
		for(int i=1;i<=n;i++){
			read(a[i]);
		}
		for(int i=1;i<=m;i++) {
			read(c[i]);
		}
		for (int i=1;i<=zhenglog2(n);i++) {
			for(int j=1;j<=(pow(2,zhenglog2(n)-i));j++) {
				read(d[i][j]);
			}
		}
		read(t);
		for (int i=1;i<=t;i++) {
			for(int j=0;j<=3;j++) {
				read(X[j]);
			}
		}
	}
	return 0;
}
