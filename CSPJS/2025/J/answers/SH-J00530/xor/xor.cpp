#include <bits/stdc++.h>
using namespace std;
int n, k, in[1000], ans = 0, flag[1000];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdin);
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n; i++){
		scanf("%d", &in[i]);
	}
	int start = 0, end = 0, now=0;
	bool find = false;
	for(int i=1;i<=n;i++){
		now = 0;
		find = false;
		for (int j=i;j<=n;j++){
			if (!flag[j]){
				now ^=in[j];
			}else{
				break;
			}
//			cout << in[j] << endl;
			if(now == k){
				find = true;
				end = j;
				break;
			}
		}
		if (find){
			ans ++;
			for (int a=i;a<=end;a++){
				flag[a]=1;
//				cout << a << endl;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
