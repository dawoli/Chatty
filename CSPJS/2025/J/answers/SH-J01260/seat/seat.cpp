#include<bits/stdc++.h>

using namespace std;

int arr[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int r;
	cin >> m >> n;
	int people = n * m;
	for(int i = 0;i < people;i++){
		cin >> arr[i];
	}
	if(m == 1 && n == 1){
		cout << "1 1";
		return 0;
	}
	r = arr[0];
	sort(arr,arr+people);
	for(int i = 1;i <= m;i++){
		for(int j = 0;j <= n;j++){
			for(int k = 1;k <= people;k++){
				if(r == arr[i]){
					cout << 1 << " " << j;
					return 0;
				}else if(r == arr[k * j+i]){
					if(k % 2 == 0){
						cout << k+j << " " << 1;
						return 0;
					}else if(k % 2 == 1){
						cout << k+j << " " << i; 
						return 0;
					}
				}
			}
		}
	}
	return 0;
} 









