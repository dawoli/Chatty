#include <bits/stdc++.h>
using namespace std;
int a[200],c[200],n,m,l,r;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++){
		cin >> a[i];c[i]=a[i];
	}
	sort(c+1,c+n*m+1,cmp);
	for (int i = 1;i <= n*m;i++){
		if (c[i] == a[1]){
			l = i / n;
			if (l % 2 == 0) r = i % n;
			else r = n - (i%n);
			if (i % n != 0) l++;
			cout << l << ' ' << r;
			return 0;
		}
	}
} 
