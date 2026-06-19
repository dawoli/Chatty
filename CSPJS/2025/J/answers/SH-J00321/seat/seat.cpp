#include<bits/stdc++.h>
using namespace std;
int a[107];
bool cmp(int a,int b){
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p=0;
	cin >> n >> m;
	for(int i = 0 ; i < n*m; i++)
		cin >> a[i];
	int r = a[0];
	sort(a,a+n,cmp);
	while(p){
		if (a[p]<=r) break;
		p++;
	}
	int ans = n*m-p;
	int rm = ans%n;
	int rn = (ans-rm)/n;
	cout << min(n,rn) << " ";
	if(rn%2==1) cout << n*2-rm-1;
	else cout << rm+1;  
	return 0;
}
