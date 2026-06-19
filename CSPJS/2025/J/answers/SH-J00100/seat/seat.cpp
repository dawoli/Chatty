#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ar,a,cnt=1;
	cin>>n>>m>>ar;
	for(int i=1;i<m*n;i++){
		cin>>a;
		if(a>ar) cnt++;
	}
	for(int i=1;i<=m;i++){
		if((i)*n>=cnt){
			for(int j=1;j<=n;j++){
				if((i-1)*n+j==cnt){
					if(i%2!=0)
						cout<<i<<" "<<j;
					else cout<<i<<" "<<n-j+1;
					return 0;
				}
			}
		}
	}
	return 0;
}
