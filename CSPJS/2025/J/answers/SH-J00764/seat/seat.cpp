#include<bits/stdc++.h>
using namespace std;
long long c[10009];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>c[i]; 
	}
	long long ytr=c[1];
	sort(c+1,c+n*m+1);
	long long num[19][19];
	long long tmp=0;
	long long x,y;
	for(long long i=1;i<=m;i++){
		y=i;
		if(i%2){
			x=1;
			for(x;x<=n;x++){
				tmp++;
				num[x][y]=tmp;	
			}
		}
		else{
			x=m;
			for(x;x>=1;x--){
				tmp++;
				num[x][y]=tmp;	
			}
		}
	}
	long long trc;
	for(long long i=n*m;i>=1;i--){
		if(c[i]==ytr){
			trc=n*m-i+1;
			break;
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			if(num[i][j]==trc){
				cout<<j<<" "<<i;
				return 0;
			}			
		}
	}
	return 0;
}
