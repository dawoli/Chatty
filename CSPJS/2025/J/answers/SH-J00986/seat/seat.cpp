#include<bits/stdc++.h>
using namespace std;

const long long N=15;
long long n,m;
long long a[N*N];
long long r;
bool dir;//0up 1down
long long f[N][N];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,greater<long long>());
	long long x=1,y=1,dir=1,cnt=1;
	while(cnt<=n*m){
		f[x][y]=a[cnt];
		cnt++;
		if(dir==0 and x==1){
			dir=1;
			y++;
		}
		else if(dir==0){
			x--;
		}
		else if(dir==1 and x==n){
			y++;
			dir=0;
		}
		else if(dir==1){
			x++;
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			if(f[i][j]==r){
				cout<<j<<" "<<i<<"\n";
				return 0;
			}
		}
	}
	return 0;
}
