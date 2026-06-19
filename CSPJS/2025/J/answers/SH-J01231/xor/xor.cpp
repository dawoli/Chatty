#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+5;
int n,k,a[MAXN],cnt1;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool flag = true,zr = true; 
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] == 1) cnt1++;
		if(a[i] == 0) flag=false;
		if(a[i] > 1) zr = false;
	}
	if(zr){
		if(k==0&&flag){
			cout << n/2;
			return 0;
		}
		else if(k==1){
			cout << cnt1;
			return 0;
		}
		else if(k==0&&flag==false){
			cout << n-cnt1+cnt1/2;
			return 0;
		}
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] == k){
			cnt++;
			continue;
		}
		int Xor = a[i];
		for(int j = i+1;j <= n;j++){
			if(a[j] == k){
				cnt++,i=j;
				break;
			}
			else if(a[j] != k){
				Xor ^= a[j];
			}
			if(Xor == k){
				cnt++,i=j;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
