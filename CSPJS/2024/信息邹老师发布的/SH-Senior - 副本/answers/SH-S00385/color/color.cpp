#include<bits/stdc++.h>
using namespace std;
int n;
int a[210000];
int c[210000];
void solve(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	int ans = 0;
	for(long long i = 0;i < (1LL << n);i++){
		for(int j = 0;j < n;j++){
			c[j + 1] = (bool)(i & (1 << j));
		}
		int sum = 0;
		for(int j = 1;j <= n;j++){
			for(int k = j - 1;k >= 1;k--){
				if(c[k] == c[j]){
					if(a[j] == a[k]) sum += a[j];
					break;
				}
			}
		}
//		cout << sum << endl;
		ans = max(ans,sum); 
	}
	printf("%d\n",ans);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i = 1;i <= T;i++){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
