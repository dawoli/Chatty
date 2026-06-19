#include<bits/stdc++.h>
using namespace std;
int bb(int b){
	if(b == 'A') b = 1;
	if(b == 'T') b = 10;
	if(b == 'J') b = 11;
	if(b == 'Q') b = 12;
	if(b == 'K') b = 13;
	if('2' <= b && b <= '9') b = b - '0';
	return b;
}
int aa(int a){
	if(a == 'D') a = 1;
	if(a == 'C') a = 2;
	if(a == 'H') a = 3;
	if(a == 'S') a = 4;
	return a;
}
int n,cnt,vis[10][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		char a,b;
		cin >> a >> b;
		int a1 = aa(a);
		int b1 = bb(b);
		if(vis[a1][b1] != true){
			vis[a1][b1] = true;
			cnt++;
		}
	}
	cout << 52 - cnt;
	return 0;
}
