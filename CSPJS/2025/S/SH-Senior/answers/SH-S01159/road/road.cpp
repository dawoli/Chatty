#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int cnt=0;
	int a,b,c;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		cnt+=c;
	}
	int x;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>x;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
