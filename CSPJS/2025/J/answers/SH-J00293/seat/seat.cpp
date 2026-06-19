#include<bits/stdc++.h>

using namespace std;

int a[120];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m; cin >> n >> m;
	for(int i = 1; i <= n*m; i ++)
		cin >> a[i];
		
	int R = a[1];
	sort(a+1,a+n*m+1,greater<int>());
	
	int cnt = 0;
	for(int j = 1; j <= m; j ++){
		if(j % 2 == 1){
			for(int i = 1; i <= n; i ++){
				if(a[++cnt] == R){
					cout << j << ' ' << i;
					return 0;
				}
			}
		}
		else{
			for(int i = n; i >= 1; i --){
				if(a[++cnt] == R){
					cout << j << ' ' << i;
					return 0;
				}
			}
		}
	}
	
	return 0;
}
