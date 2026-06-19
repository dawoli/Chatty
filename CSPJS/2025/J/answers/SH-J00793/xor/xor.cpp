#include<bits/stdc++.h>
using namespace std;
long long a[500001];
bool l[500001];
bool r[500001];
long long k;
long long dfs(long long l,long long r){
	long long result;
	if(l == r){
		return k == a[l];
	}
	long long c = l;
	for(int i=l+1;i<=r;i++){
		c ^= a[i];
	}
	for(int i=l;i<r;i++){
		c += max(c,dfs(l,i) + dfs(i+1,r));
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n;
	cin >> n;
	cin >> k;
	for(long long i = 0;i<n;i++){
		cin >> a[i];
	}
	if(n <= 2){
		if(n == 1){
			cout << (a[1] == k) << "\n";
		}
		cout << (a[1] == k + a[2] == k) << "\n";
	}
	cout << dfs(1,n) / (4-k) << "\n";
	return 0;
}
