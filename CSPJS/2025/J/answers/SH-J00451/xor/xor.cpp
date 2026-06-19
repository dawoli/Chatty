#include<iostream>
using namespace std;
long long a[500005];

long long quan(int l, int r){
	long long s=a[l];
	for(int i = l+1;i<=r;i++) s ^= a[i];
	return s;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, cnt=0;
	long long k;
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long qq = quan(i, j);
			if(qq == k){
				cnt++;
				i = j;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
