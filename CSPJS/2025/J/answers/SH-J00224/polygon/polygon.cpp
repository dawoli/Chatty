/***********
 * T4: 多边形 polygon 
 * 估分: 12
 * author: CB_X2_Jun (Luogu UID 1219707)
 * 到此一游 
 ***********/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,edge[5555];
int main()
{
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(false);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n<3){cout << 0;return 0;}
	if(n==3)
	{
		int maxedge=0,sss=0;
		for(int i=1; i<=n; i++){cin >> edge[i];maxedge=max(edge[i],maxedge);sss+=edge[i];}
		if(2*maxedge<sss)cout << 1;
		else cout << 0;
		return 0;
	}
//	int maxedge=0,sss=0;
//	for(int i=1; i<=n; i++){cin >> edge[i];maxedge=max(edge[i],maxedge);sss+=edge[i];}
//	if(maxedge==1)
//	{
//		unsigned long long 
//	}
	return 0;
}
