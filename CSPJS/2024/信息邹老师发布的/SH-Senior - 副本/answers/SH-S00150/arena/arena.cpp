#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.in","w",stdout);
	int n,m,k=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	while(pow(2,k)<n){
		k++;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		cout<<1<<endl;
	}
	return 0;
}





