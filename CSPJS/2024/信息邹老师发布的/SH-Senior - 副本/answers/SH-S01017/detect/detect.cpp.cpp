#include<bits/stdc++.h>
using namespace std;
int dl[100100] , vl[100100] , al[100100];
int main(){
	freopen("detect.in" , "r" , stdin);
	freopen("detect.out" , "w" , stdout);
	int t,n,m,l,v,p,maxx=0,ret;
	cin >> t;
	for(int er=0;er<t;er++){
		ret = 0;
		maxx = 0;
		cin >> n >> m >> l >> v;
		for(int j=0;j<n;j++){
			cin >> dl[j] >> vl[j] >> al[j];
		}for(int h=0;h<m;h++){
			cin >> p;
			if(p > maxx){
				maxx = p;
			}
		}for(int k=0;k<n;k++){
			if(vl[k] <= v) continue;
			if(dl[k] > maxx) continue;
			ret++;
		}
		if(ret!=0)cout << ret << " " << m-1 << '\n';
		else cout << 0 << " " << m << '\n';
	}
	return 0;
}
