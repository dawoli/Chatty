#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		int a1,a2,a3;cin>>a1>>a2>>a3;
	bool flag=true;
	for(int i=1;i<=k;i++){
		int c;cin>>c;if(c) flag=false;
		for(int j=1;j<=n;j++){
			int b;cin>>b;if(b) flag=false;
		}if(flag) break;
	}
	if(flag){
		cout<<0;
		return 0;
	}
	return 0;
}
