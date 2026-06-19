#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[105];
	for(int i=0;i<n*m;i++){
		cin >> a[i];
	}
	int r = a[0];
	sort(a, a+m*n, cmp);
	int k = 0;
	for(int i=0;i<n;i++){
		if(i & 1){
			for(int j=m-1;j>=0;j--){
				if(a[k] == r) cout << i + 1 << ' ' << j + 1;
				//cout << a[k] << ' ';
				k++;
			}
		}
		else{
			for(int j=0;j<m;j++){
				if(a[k] == r) cout << i + 1 << ' ' << j + 1;
				//cout << a[k] << ' ';
				k++;
			}
		}
		//cout << endl;
	}
	return 0;
}
