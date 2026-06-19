#include<bits/stdc++.h>
using namespace std;
int s[5005];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n, maxn = 0;
	cin >>n;
	for(int i = 1; i <= n; i++) {
		cin >>s[i];
		if(s[i] > maxn) maxn = s[i];
	}
	sort(s+1, s+n+1);
	if(maxn == 1) {
		int posa=pow(2,n)-1-(n*n-n)/2-n;
		posa%=998244353;
		cout << posa << endl;
		return 0;
	}
	if(maxn<=5000&&n<=5000){
		int ans = 0;
		for(int i = n; i >= 3; i--) {
			for(int j = i-1; j>=2;j--){
				int sumup =s[j]+s[j-1];
				int qw = j-1;
				while(qw>=1){
					if(sumup > s[i]){
						ans+=pow(2,qw-1);
						ans%=998244353;
						sumup-=s[qw];
						qw--;
						sumup+=s[qw];
					}
					else{
						qw--;
						sumup+=s[qw];
					}	
				}
			}
		}
		cout <<ans;
		return 0;
	}
	if(n<=3) {
		if(s[1]+s[2] <= s[3]) return 0;
		cout << 1 << endl;
		return 0;
	}
	return 0;
}
