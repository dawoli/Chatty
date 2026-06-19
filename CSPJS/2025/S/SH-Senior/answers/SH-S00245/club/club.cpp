#include<bits/stdc++.h>
using namespace std;
//Ren5Jie4Di4Ling5%
int t,n,a[200005][5],dp[200005],mx;
int cnt1 = 0, cnt2 = 0, cnt3 = 0;
int num(int i){
	if(max(a[i][1],max(a[i][2],a[i][3])) == a[i][1]){
		cnt1++;
		if(cnt1<=mx){
			cout<<a[i][1]<<" ";
			return a[i][1];
		}
		else{
			if(max(a[i][2],a[i][3]) == a[i][2] && cnt2< mx){
				cnt2++;
				cout<<a[i][2]<<" ";
				return a[i][2];
			}
			else{
				cnt3++;
				cout<<a[i][3]<<" ";
				return a[i][3];
			}
		}
	}
	else if(max(a[i][1],max(a[i][2],a[i][3])) == a[i][2]){
		cnt2++;
		if(cnt2<=mx){
			cout<<a[i][2]<<" ";
			return a[i][2];
		}
		else{
			if(max(a[i][1],a[i][3]) == a[i][1] && cnt1 < mx){
				cnt1++;
				cout<<a[i][1]<<" ";
				return a[i][1];
			}
			else{
				cnt3++;
				cout<<a[i][3]<<" ";
				return a[i][3];
			}
		}
	}
	else{
		cnt3++;
		if(cnt3<=mx){
			cout<<a[i][3]<<" ";
			return a[i][3];
		}
		else{
			if(max(a[i][1],a[i][2]) == a[i][1] && cnt1< mx){
				cnt1++;
				cout<<a[i][1]<<" ";
				return a[i][1];
			}
			else{
				cnt2++;
				cout<<a[i][2]<<" ";
				return a[i][2];
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		mx = n/2;
		for(int i = 0; i < n; ++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			dp[i] = 0;			
		}
		for(int i = 1; i <= n; ++i){
			dp[i] = dp[i-1]+num(i-1);
		}
		cnt1 = cnt2 = cnt3 = 0;
	}
	cout<<dp[n];
	return 0;
}
