#include <bits/stdc++.h>
using namespace std;
int n=0;
bool p[5][53];
char po[2];
int ans=52,x=0,y = 0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> po;
		if(po[0] == 'D'){
			x = 0;
		}else if(po[0] == 'C'){
			x = 1;
		}else if(po[0] == 'H'){
			x = 2;
		}else{
			x = 3;
		}
		y = po[2] - '0';
		if(p[x][y] != 1){
			ans--;
		}
		p[x][y] = 1;
	}
	cout << ans;
	return 0;
}
