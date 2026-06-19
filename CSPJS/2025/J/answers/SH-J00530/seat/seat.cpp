#include <bits/stdc++.h>
using namespace std;
int inp[1000], n, m, ming, temp, pos, col;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.ans", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%d", &ming);
	for (int i=1;i<=(n*m)-1;i++){
		scanf("%d", &temp);
		inp[temp]++;
	}
	for (int i=ming;i<=100;i++){
		pos += inp[i];
	}
	pos ++;
//	cout << pos << endl;
	
	col = floor(pos/n)+1;
//	cout << col << endl;
	if (col%2 || pos%n ==0){
		cout << col << " ";
		cout << pos - (col-1)*n << endl;
	}else{
		cout << col << " ";
		cout << n - (pos - (col-1)*n)+1 << endl;
	}
//	cout << pos << endl;
	return 0;
}
