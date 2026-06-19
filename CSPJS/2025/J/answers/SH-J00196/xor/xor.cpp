#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		int sum = a[i];
		if(sum == k){
			cnt++;
			continue;
		}
		for(int j = i + 1;j <= n;j++){
			sum = sum ^ a[j];
			if(sum == k || a[j] == k){
				i = j;
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}

