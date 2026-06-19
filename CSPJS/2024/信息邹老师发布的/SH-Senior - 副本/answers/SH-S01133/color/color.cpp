#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int N=2e5+5;
int t, n, a[N], ef[N], ls[1111111], eg[N];
long long sum[N], dp[N];

int main(){
	freopen("color.in", "i", stdin);
	freopen("color.out", "o", stdout);
	cin >> t;
	while(t--){
		memset(ls, -1, sizeof(ls));
		sum[0]=0;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> a[i];
			sum[i+1]=sum[i];
			if(i>=1 && a[i]==a[i-1]) sum[i+1]+=a[i];
			ef[i]=ls[a[i]];
			if(ls[a[i]]!=-1) eg[ef[i]]=i;
			ls[a[i]]=i;
		}
		memset(dp, 0, sizeof(dp));
		for(int i=2; i<=n; i++){
			int k=i-1, cs=0, ks=i-1;
			dp[i]=max(dp[i], dp[k]+cs);
			while(k!=-1){
				while(k==ef[k]+1 && ef[k]!=-1) k=ef[k];
				int ps;
				if(ef[k]==-1) ps=k;
				k=ef[k];
				if(ef[k]!=-1) cs+=a[i-1];
				cs=cs+max(0ll, sum[eg[k]-1]-sum[k+1]);

				if(k==-1) dp[i]=max(dp[i], dp[ps]+cs);
				else dp[i]=max(dp[i], dp[ks+1]+cs);
							   				if(ks!=i-1 && a[ks+1]==a[k-1]) cs+=a[ks+1]; 

				ks=k;
			}
		}
		cout << dp[n] << endl;
	}
} 
