/*
贪心思路：
首先先把每个人对应到最好的东西上(一样的随意选择)
然后看有没有太多的一个社团

对于这些人，只要转移走多出来的，一定不会造成新的太多的社团。
所以需要对于其排序，关键字为落差，其中另外两个社团取max，就可以完成了 
*/ 
#include<bits/stdc++.h>
#define int long long
using namespace std;
ifstream fin("club.in");
ofstream fout("club.out");
using Pair=pair<int,int>;
const int maxn=1e5+5;
int T,n,tp[maxn],c[3],d[3][maxn],ans;
Pair a[maxn][3];
signed main() {
	fin>>T;
	while(T--) {
		fin>>n; ans=c[0]=c[1]=c[2]=0;
		for(int i=1;i<=n;i++) {
			for(int j=0;j<3;j++) {
				int x; fin>>x;
				a[i][j]={x,j};
			}
			sort(a[i],a[i]+3);
			ans+=a[i][2].first,tp[i]=a[i][2].second;
			d[tp[i]][++c[tp[i]]]=a[i][2].first-a[i][1].first;
		}
		for(int i=0;i<3;i++) {
			if(c[i]>n/2) {
				sort(d[i]+1,d[i]+c[i]+1);
				for(int j=1;j<=c[i]-n/2;j++)  ans-=d[i][j];
			}
		}
		fout<<ans<<"\n";
	}
	return 0;
}
