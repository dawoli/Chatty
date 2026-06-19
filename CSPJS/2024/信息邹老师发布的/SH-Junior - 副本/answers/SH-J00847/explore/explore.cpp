#include<bits/stdc++.h>
using namespace std;
/*
_CRTIMP double __cdecl j0 (double) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
_CRTIMP double __cdecl j1 (double) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
_CRTIMP double __cdecl jn (int, double) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
_CRTIMP double __cdecl y0 (double) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
_CRTIMP double __cdecl y1 (double) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
_CRTIMP double __cdecl yn (int, double) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
*/
//对于所有测试数据，保证：1 ≤ T ≤ 5, 1 ≤ n, m ≤ 10^3, 1 ≤ k ≤ 10^6, 1 ≤ x0 ≤ n, 1 ≤ y0 ≤ m, 0 ≤ d0 ≤ 3，且机器人的起始位置为空地。
//这个位置是 x 即代表它是障碍，否则代表它是空地。数据保证机器人初始时所在的位置为空地。
const int N=1e3+1;
int t,n,m,k,x,y,d,ans;
char a[N][N];
bool vis[N][N];
typedef void (*func)(int &x,int &y);
inline bool inmap(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=m;
}
inline void east(int &x,int &y)
{
	++y;
}
inline void south(int &x,int &y)
{
	++x;
}
inline void west(int &x,int &y)
{
	--y;
}
inline void north(int &x,int &y)
{
	--x;
}
func move_function[4]={east,south,west,north};
inline void move(int &x,int &y,int d)
{
	move_function[d](x,y);
}
inline void move()
{
	vis[x][y]=true;
	int xx=x,yy=y;
	move(xx,yy,d);
	if(inmap(xx,yy)&&a[xx][yy]!='x'){
		x=xx;
		y=yy;
	}else{
		d=(d+1)%4;
	}
	vis[x][y]=true;
}
inline void clear(int n,int m)
{
	//多测清空 
	ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j) vis[i][j]=false;
}
inline void solve()
{
	cin>>n>>m>>k>>x>>y>>d;
	clear(n,m);//多测清空 
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j) cin>>a[i][j];
	for(int i=1;i<=k;++i) move();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j) ans+=vis[i][j];
	cout<<ans<<endl;
}
inline void Main()
{
	//abcdefghijklmnopqrstuvwxyz
	cin>>t;
	for(int i=1;i<=t;++i) solve();
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Main();
	fclose(stdin);
	fclose(stdout);
 	return 0;
}

