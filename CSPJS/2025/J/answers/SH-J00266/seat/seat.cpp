#include<bits/stdc++.h>
using namespace std;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,1}};
int n,m,a[105],mp[15][15];
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	ifstream fin("seat.in");
	ofstream fout("seat.out"); 
	int rank = 1,x = 1,y = 1;
	fin>>n>>m;
	for(int i = 1; i <= n*m; ++i){
		fin>>a[i];
		if(a[i]>a[1])
			rank++;
	}
	if(rank%n == 0){
		if((rank/n)%2 == 0){
			x = 1;
			y = rank/n;
		}
		else{
			x = n, y = rank/n;
		}
	}
	else{
		if((rank/n+1)%2 == 0){
			x = n-rank%n+1;
			y = rank/n+1;
		}
		else{
			x = rank%n;
			y = rank/n+1;
		}
	}
	fout<<y<<" "<<x;
	return 0;
}
