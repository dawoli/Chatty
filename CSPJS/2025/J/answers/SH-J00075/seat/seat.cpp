#include<bits/stdc++.h>
using namespace std;

const int maxn=200;
int Seat[maxn][maxn],Rank,Score,n,m,a[maxn],cnt=0;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				Seat[j][i]=++cnt;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				Seat[j][i]=++cnt;
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<Seat[i][j]<<" ";
		}cout<<"\n";
	}*/
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	Score=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==Score) Rank=i;
	}
	Rank=(n*m)+1-Rank;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(Seat[i][j]==Rank){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
