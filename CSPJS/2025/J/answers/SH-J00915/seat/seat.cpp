#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
long long n;
long long m,x,y;
long long a[15][15];
long long b[105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int cnt=0;
	for(int i=1;i<=n*m;i++){
		cin >> b[i];
	}
	y=b[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i;j<=n*m;j++){
			x=b[i];
			if(b[i]<b[j]){
				x=b[j];
				b[j]=b[j-i];
				b[j-i]=x;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cnt++;
			a[i][j]=b[cnt];
		}	
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==y){
				cout << i << " " << j;
			}
		} 
	}
	
	
	return 0;
} 
