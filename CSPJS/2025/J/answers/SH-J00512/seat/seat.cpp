#include <bits/stdc++.h>
using namespace std;
int n,m,score;
int a[109];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int rank = 1;
	cin >> a[0];
	for(int i=1; i<n*m; i++){
		cin >> a[i];
		if(a[i] > a[0]){
			rank++;
		}
	}
	int row = 0;
	int crank = rank;
	while(rank > 0){
		rank -= n;
		row++;
	}
	int line = 0;
	if(row % 2 == 0){
		line = n - (crank-1) % n ;
	}else{
		line = (crank-1) % n + 1;
	}
	cout << row << " " << line;
	
	return 0;
}

