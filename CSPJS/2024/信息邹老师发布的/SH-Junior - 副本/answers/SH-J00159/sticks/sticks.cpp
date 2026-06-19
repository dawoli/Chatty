#include <bits/stdc++.h>
using namespace std;
long long t,n,rund,i,p,ans,fst,rmn,maxp;
int nums[10] = {6,2,5,5,4,5,6,3,7,6};
long long psb[10000000];
int dp[100000];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	for (i=0;i<100000;i++)dp[i]=0;
	cin >> t;
	for (rund=0;rund<t;rund++){
		cin >> n;
		if (n<2){cout << -1 << endl;continue;}
		if (n<8){
			for (i=1;i<10;i++)if (n==nums[i]){
				cout << i << endl;
				break;
			}
			continue;
		}
		double tt=n/7.0;
		maxp=ceil(tt);
		rmn = n%7;
		if (rmn == 0)maxp = n/7;
		for (i=0;i<maxp-1;i++)dp[i] = 8;
		if (rmn==0){
			dp[maxp-1] = 8;
		}
		if (rmn==1){
			if (maxp >= 2){
				dp[maxp-1] = 1;
				dp[maxp-2] = 0;
			}
		}
		if (rmn==2){
			dp[maxp-1] = 1;
		}
		if (rmn==3){
			if (maxp >= 3){
				dp[maxp-1] = 2;
				dp[maxp-2] = 0;
				dp[maxp-3]= 0;
			}
		}
		if (rmn==4){
			if (maxp >= 2){
				dp[maxp-1] = 2;
				dp[maxp-2] = 0;
			}
		}
		if (rmn==5){
			dp[maxp-1] = 2;
		}
		if (rmn==6){
			dp[maxp-1] = 6;
		}
		for (p=maxp-1;p>=0;p--)cout << dp[p];
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

