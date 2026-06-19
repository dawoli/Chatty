#include<bits/stdc++.h>
#define ll long long
using namespace std;
int m,n,k,a,minn=INT_MAX;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	while(m--){
		cin >> a >>a >> a;
	}
	while(k--){
		int sum=0;
		cin >> sum;
		for(int i=1;i<=n;i++){
			cin >> a;
			sum+=a;
		}
		minn=min(minn,sum);
	}
	cout << minn;
	return 0;
}

