#include<bits/stdc++.h>
using namespace std;

const int N = 110;

int n, m, pos, row, col;
int a[N];


void quick_sort(int l,int r){
	if (l >= r) return;
	
	int x = a[(l+r)>>1], i = l-1, j = r+1;
	while(i < j){
		do i++; while (a[i] > x && i <= r);
		do j--; while(a[j] < x && j >= l);
		if (i < j) swap(a[i], a[j]);
	}
	
	quick_sort(l, j);
	quick_sort(j+1, r);
}


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 0; i < n*m; i++) cin >> a[i];
	int score = a[0];
	
	quick_sort(0, n*m);
	
	for (int i = 0; i < n*m; i++){
		if (a[i] == score) pos = i+1; 
	}
	
	
	col = (pos-1)/ m + 1;
	if (col % 2 == 0){
		row = pos%m;
		if (row == 0) row = m;
		row = m - row+1;
	} else{
		row = pos%m;
		if (row == 0) row = m;
	}
	
	cout << col << ' ' << row << endl;
	
	return 0;
}

