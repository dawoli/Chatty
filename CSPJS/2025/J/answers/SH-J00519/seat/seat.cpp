#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin >> n >> m >> r;
	int a[105];
	for(int i = 2; i <= n * m; i ++)
	{
		cin >> a[i];
	}
	int cnt = 0;
	int x = 1;
	int y = 1;
	for(int i = 2; i <= n * m; i++){
		if(a[i] > r){
			cnt++;
			
		}
	}
	
	while(cnt){
		if(x < n){
			x++;	
		}
		else if(x >= n){
			y++;
			x = 1;
		}
		cnt --;
	}//递推到包含r本身的座位 
	if(y % 2 == 0){
		x = n - x+1;
	}
		
	
	
	cout << y << " " << x;
	return 0;
}
