#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define NN 210

int n;
int a[N][4],a1[N];
long long dp[NN][NN][NN];

void bf(){ //55pts
	for(int i = 1;i <= n;++i){
		for(int j = 0;j <= n / 2;++j){
			for(int k = 0;k <= n / 2;++k)dp[i][j][k] = 0;
		}
	}
	for(int i = 1;i <= n;++i){
		for(int j = 0;j <= n / 2 && j <= i;++j){
			for(int k = 0;k <= n / 2 && k + j <= i;++k){
				int g3 = i - j - k;
				if(g3 < 0 || g3 > n / 2)continue; 
				if(j)dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j - 1][k] + a[i][1]);
				if(k)dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j][k - 1] + a[i][2]);
				if(g3)dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j][k] + a[i][3]);
			}
		}
	}
	long long ans = 0;
	for(int j = 0;j <= n / 2;++j){
		for(int k = 0;k <= n / 2 && j + k <= n;++k){
			int i = n - j - k;
			if(i < 0 || i > n / 2)continue;
			ans = max(ans,dp[n][j][k]);
		}
	}
	printf("%lld\n",ans);
}

void solveA(){ //5pts
	for(int i = 1;i <= n;++i)a1[i] = a[i][1];
	sort(a1 + 1,a1 + 1 + n);
	long long ans = 0;
	for(int i = n;i > n / 2;--i)ans += a1[i];
	printf("%lld\n",ans);
}

void solveB(){ //10pts
	long long ans = 0;
	for(int i = 1;i <= n;++i)ans += a[i][2],a1[i] = a[i][1] - a[i][2]; 
	sort(a1 + 1,a1 + 1 + n);
	for(int i = n;i > n / 2;--i)ans += a1[i];
	printf("%lld\n",ans);
}

bool vst[N];
struct d{ int val,idx; }b2[N],b3[N];
bool cmp(d x,d y){ return x.val > y.val; }

void solve(){ //思路有问题，时间不够了，放弃 
	long long ans = 0;
	for(int i = 1;i <= n;++i){
		vst[i] = 0;
		ans += a[i][1]; //全选1组 
		b2[i].val = a[i][2] - a[i][1];
		b3[i].val = a[i][3] - a[i][1];
		b2[i].idx = b3[i].idx = i;
	}
	sort(b2 + 1,b2 + 1 + n,cmp);
	sort(b3 + 1,b3 + 1 + n,cmp);
	int sz2 = 0,sz3 = 0,i = 0,j = 0;
	for(;i <= n;++i){
		if(sz2 == n / 2 && sz3 == n / 2)break;
		while((b3[j + 1].val > b2[i + 1].val || sz2 == n / 2) && sz3 < n / 2){
			if(b3[j + 1].val < 0)break;
			if(!vst[b3[j + 1].idx]){
				vst[b3[j + 1].idx] = 1;
				sz3++;
				ans += b3[j + 1].val;
//				printf("%d turn to group3(sz:%d),ans - > %lld\n",b3[j + 1].idx,sz3,ans);
			}
			++j;
		}
		if(b2[i + 1].val < 0)break;
		if(sz2 < n / 2 && !vst[b2[i + 1].idx]){
			vst[b2[i + 1].idx] = 1;
			sz2++;
			ans += b2[i + 1].val;
//			printf("%d turn to group2(sz:%d),ans - > %lld\n",b2[i + 1].idx,sz2,ans);
		}
	}
//	printf("\n");
	if(sz2 + sz3 < n / 2){
		
	}
	printf("%lld\n",ans);
}

int main(){
	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
	int T = 1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		bool flagA = true,flagB = true;
		for(int i = 1;i <= n;++i){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][3])flagA = false,flagB = false;
			if(a[i][2])flagA = false;
		}
		if(n <= 200)bf(); 
		else if(flagA)solveA();
		else if(flagB)solveB();
		else solve();
	}
	return 0;
}
