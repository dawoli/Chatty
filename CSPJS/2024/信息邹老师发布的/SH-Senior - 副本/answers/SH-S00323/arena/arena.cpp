#include<bits/stdc++.h>
using namespace std;
int a[100010],c[100010],x[300][10];
bool d[20][20];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	int k=0;
	while(k++){
		if(pow(2,k)>=n){
			break;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=pow(2,k-i);j++){
			char c;
			cin>>c;
			d[i][j]=c-'0';
		}
	}
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>x[i][1]>>x[i][2]>>x[i][3]>>x[i][4];
	}
	cout<<T;
	return 0;
}
