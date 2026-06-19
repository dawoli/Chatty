/*
所谓接龙序列，本质上就是选开头和结尾

如何找到一个序列(2<=len<=101)
使得a[i]=1,a[i]在a[i+1]前不超过k-1的距离，并且a[n+1]=c

对于sigma<=2000以及k<=5 70pts
我们考虑dp，预处理+dp即可
先把纯dp60分拿到再说，这是必须保底的

不要再贪了！

满分做法：
我们考虑转换成图论
考虑对于字典中相邻数，前面向后面连一条边，边权:第i个人
这个图有环，有重边，有自环
最终看从一个点开始，能连续经过多少种边
考虑缩点，一个环内部记录有哪些权值
前面一个点把后面的东西合并，算法复杂度O(sum of len) 
但是太难，应该拿部分分走人
*/
#include<bits/stdc++.h>
using namespace std;
using Pair=pair<int,int>;
const int maxn=2e5+5;
const int maxr=105;
int T,n,k,q;
int l[maxn];
int dp[maxn][maxr][2];
bool mem[maxn][maxr][2];
vector<int> s[maxn];
vector<Pair> bef[maxn];
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++) {
			cin>>l[i];
			for(int j=0;j<l[i];j++) {
				int a;
				cin>>a;
				s[i].push_back(a);
			}
		}
		for(int i=1;i<=n;i++) {
			for(int j1=0;j1<l[i];j1++) {
				for(int j2=max(0,j1-k+1);j2<j1;j2++) {
					bef[s[i][j1]].push_back({s[i][j2],i});
				}
			}
		}
		memset(mem,0,sizeof(mem));
		for(int i=1;i<maxn;i++)  mem[i][0][0]=true;
		for(int i=1;i<=100;i++) {
			for(int j=1;j<maxn;j++) {
				for(Pair b:bef[j]) {
					int v=b.first,id=b.first;
					for(int flag=0;flag<2;flag++) {
						if(mem[v][i-1][flag]&&dp[v][i-1][flag]!=id) {
							if(mem[j][i][0]&&id!=dp[j][i][0])  dp[j][i][1]=id,mem[j][i][1]=true;
							else  dp[j][i][0]=id,mem[j][i][0]=true;
						}
					}
				}
			}
		}
		while(q--) {
			int r,c;
			cin>>r>>c;
			if(mem[c][r][0]||mem[c][r][1])  cout<<"1\n";
			else  cout<<"0\n";
		}
	}
	return 0;
}
