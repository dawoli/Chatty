#include "bits/stdc++.h"
#define int long long
#define For(i, l, r) for(int i = (l) ; i <= (r) ; ++i)
using namespace std ;
const int N = 100005 ;
struct Node
{
	int x, y, z ;
	bool operator <(Node b) const
	{
		return z < b.z ;
	}
} ;
struct Node2
{
	int x, y, z, xx, yy, zz ;
	bool operator <(Node2 b) const
	{
		return z - zz > b.z - b.zz ;
	}
} ;
int T, n, lim, a[N][4], ans, cnt ;
inline Node calc(Node p)
{
	int x = p.x, y = p.y ;
	Node tmp1, tmp2 ;
	if(y == 1) tmp1 = {x, 2, a[x][2]}, tmp2 = {x, 3, a[x][3]} ;
	if(y == 2) tmp1 = {x, 1, a[x][1]}, tmp2 = {x, 3, a[x][3]} ;
	if(y == 3) tmp1 = {x, 1, a[x][1]}, tmp2 = {x, 2, a[x][2]} ;
	if(tmp1.z < tmp2.z) swap(tmp1, tmp2) ;
	return tmp1 ;
}
bool book[N] ;
pair<int, int> st[N] ;
priority_queue<Node> q ;
priority_queue<Node2> res[4] ;
signed main()
{
	freopen("club.in", "r", stdin) ;
	freopen("club.out", "w", stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> T ;
	For(t, 1, T)
	{
		while(!q.empty()) q.pop() ;
		memset(st, 0, sizeof(st)) ;
		memset(book, 0, sizeof(book)) ;
		memset(a, 0, sizeof(a)) ;
		memset(res, 0, sizeof()res) ;
		ans = cnt = 0 ;
		cin >> n ; lim = n >> 1 ;
		For(i, 1, n) For(j, 1, 3)
		{
			cin >> a[i][j] ;
			q.push({i, j, a[i][j]}) ;
		}
		while(!q.empty())
		{
			Node f = q.top() ; q.pop() ; // f 选用收益最值
//			cout << "f: " << f.x << " " << f.y << " " << f.z << "\n" ; 
			Node tmp = calc(f) ;
			if(book[f.x]) continue ; // 判重 
			if(res[f.y].size() == lim) // 装满 
			{
				Node2 ff = res[f.y].top() ; // ff 更换收益最值 
				if(f.z - calc(f).z > ff.z - ff.zz) // 更换有收益 
				{
					res[f.y].pop() ;
					res[f.y].push({f.x, f.y, f.z, tmp.x, tmp.y, tmp.z}) ;
					ans += ff.zz ;
//					++cnt ;
					book[f.x] = 1 ;
					// 被换的出栈 加答案 换的入栈  
				} // 否则不更改 
			}
			else // 没装满
			{
				res[f.y].push({f.x, f.y, f.z, tmp.x, tmp.y, tmp.z}) ;
				book[f.x] = 1 ;
			} 
		}
//		cout << "f done\n" ;
		For(i, 1, 3)
		{
			while(!res[i].empty())
			{
				Node2 tmp = res[i].top() ; res[i].pop() ;
//				cout << "tmp: " << tmp.x << " " << tmp.y << " " << tmp.z << " "
//				<< tmp.xx << " " << tmp.yy << " " << tmp.zz << "\n" ;
				ans += tmp.z ;
				++cnt ;
			}
		}
		cout << ans << "\n" ;
	}
	return 0 ;
}
/*
1
10
20 10 0
19 9 0
18 8 0
17 7 0
16 6 0
15 5 0
14 4 0
13 3 0
12 2 0
11 1 0
*/
