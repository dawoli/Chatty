#include<bits/stdc++.h>
using namespace std;
int n, m, x[102], sc;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)cin >> x[i];
	sc = x[1];
	sort(x + 1, x + 1 + n * m);
	int cnt;
	for(int i = n * m;i >= 1;i--){
		if(x[i] == sc){
			cnt = n * m - i + 1;
			break;
		}
	}
	int l = cnt / n;
	if(cnt % n >= 1)l++;
	bool down = 1;
	int r = 0;
	for(int i = 1;i <= cnt;i++){
		if(down)r++;
		if(!down)r--;
		if(r == n + 1){
			down = 0;
			r = n;
		}
		if(r == 0){
			down = 1;
			r = 1;
		}
	}
	cout << l << " " << r << endl;
	return 0;
}
