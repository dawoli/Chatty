#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const long long mod = 998244353;
int n;
long long a[10007];
long long f[20007];//f[x]代表有多少种情况能得到x，如果x == 10001，代表的是有多少种情况能大于等于x 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	f[0] = 1ll;
	
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	
	sort(a+1,a+n+1);
	
	long long cnt = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 10001;j > a[i];j--){
			cnt = (cnt+f[j])%mod;
		}
		
		for(int j = 10001;j >= 0;j--){
			if(f[j] == 0) continue;
			int nid = min(10001,j + int(a[i]));
			f[nid]+=f[j];
			f[nid]%=mod;
		}
		/*for(int j = 0;j <= 11;j++){
			cout << f[j] << " ";
		}cout << endl;*/ 
	}
	printf("%lld\n",cnt);
	return 0;
} //感觉可能不是正解（谁好人家第四题代码这么短），但是大样例过了 
//CCF是大坏蛋 
