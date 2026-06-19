#include<bits/stdc++.h>
using namespace std;
int n,m,u,b,cnt;
int a[110];
bool fan;
bool cmp(int a,int b) {
	return a > b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++)cin >> a[i];
	int g  = a[1];
	sort(a + 1,a + 1 + n*m,cmp);
	for(int i = 1; i <= n*m ; i++) {
		if(a[i] == g) {
			if(i % m != 0) b = i/m +1;
			else  b = i/m;
		}
	}
	if(b % 2 == 0)fan = 1;
	int p = (b-1)*m+1;
	if(fan == 1) {
		for(int i = p+n-1; i >= p; i--) {
			cnt++;
			if(a[i] == g) 
			{
				u = cnt;
			 } 
		}
	}else {
		for(int i = p;i <= p+n-1; i++)
		{
			cnt++;
			if(a[i] == g)  u = cnt;
		}
	}
	cout << b <<" "<< u<<endl;


	return 0;
}

