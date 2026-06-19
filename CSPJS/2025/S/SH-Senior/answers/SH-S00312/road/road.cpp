#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		sum+=c;
	}
	cout<<sum;
	return 0;
}
