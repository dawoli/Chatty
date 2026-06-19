#include<bits/stdc++.h>
using namespace std;
int n,m,a[1145];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i = 1;i <= n * m;i++) cin>>a[i];
	int tmp = a[1];
	sort(a + 1,a + n * m + 1);
	reverse(a + 1,a + n * m + 1);
	int x = 1,y = 1;
	for(int i = 1;i <= n * m;i++){
		if(a[i] == tmp){
			cout<<x<<" "<<y<<endl;
			return 0; 
		}
		if((x % 2 == 1 && y == n) || (x % 2 == 0 && y == 1)) x++;
		else if(x % 2 == 1) y++;
		else y--;
	}
}
