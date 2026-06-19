#include <bits/stdc++.h>
using namespace std;
int n,m;
int target;
int it;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	vector<int> a(n*m+1);
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	target = a[1];
	sort(a.begin()+1,a.begin()+1+n*m,greater<int>());
	for (int i=1;i<=n*m;i++){
		if (a[i] == target){
			it = i;
			break;
		}
	}
	//cout << it << '\n';
	if ((int)ceil(1.0*it/n)&1){
		cout << (int)ceil(1.0*it/n) << ' ' << (it%n == 0 ? n : it%n); 
	}
	else{
		cout << (int)ceil(1.0*it/n) << ' ' << (it%n == 0 ? 1 : n-it%n+1);
	}
	return 0; 
}
