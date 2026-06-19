#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[110];
int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	fclose(stdin);
	fclose(stdout);

	cin >> n >> m;
	for(int i = 0 ; i < n*m ; i ++){
		cin >> a[i];
	}
	int c = a[0];
	cout << endl;
	for(int i = 0 ; i < n*m ; i++){
		for(int j = 0 ; j < n*m ; j++){
			if(a[j+1] > a[j]){
				int b = a[j];
				a[j] = a[j+1];
				a[j+1] = b;
			}
		}
	}
	int sum = 0;
	for(int i = 0 ; i < n*m ; i++){
		if(a[i] == c){
			sum = i;
		}
	}
	int x = (sum + 1) % n;
	int y = (sum + 1 - x) / n;
	if(x == 0){
		if(y % 2 == 0){
			cout << y << " " << 1;
		}
		if(y % 2 != 0){
			cout << y << " " << n;
		}
	}
	else{
		if(y % 2 == 0){
			cout << y+1 << " " << x;
		}
		if(y % 2 != 0){
			cout << y+1 << " " << n - x;
		}	
	}
	return 0;
}
