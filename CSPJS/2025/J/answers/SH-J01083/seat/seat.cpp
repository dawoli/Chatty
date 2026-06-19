#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;
	int c[1000];
	bool flag = true;
	cin >> n >> m;
	for(int i=0;i<n*m;i++){
		cin >> c[i];
	}int tmp = c[0];
	for(int i=0;i<n*m;i++){
		for(int j=i+1;j<n*m;j++){
			if(c[i] < c[j]){
				swap(c[i] , c[j]);
			}
		}
	}
	int k = 0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(c[k] == tmp){
					cout << i << ' ' << j;
					flag = false;
					break;
				}k++;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(c[k] == tmp){
					cout << i << ' ' << j;
					flag = false;
					break;
				}k++;
		    }
		}if(flag == false){
			break;
		}
	}
	return 0;
} 
