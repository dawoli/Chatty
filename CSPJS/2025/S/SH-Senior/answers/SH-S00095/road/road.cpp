#include <bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,sum;
long long r[10010][10010],c[110],a[110][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n >> m >>k;
	for(int i = 1;i<=m;i++){
		cin >> u >>v >>w;
		r[u][v] = w;
		sum += w; 
	}
	//for(int i = 1;i<=k;i++){
		
	//}
	cout << sum;
	
	return 0;
} 
