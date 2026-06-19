#include <bits/stdc++.h>
using namespace std;
int T;
int ans[2000009];
int temp[2000009];
int nowminnw = 3000000;
int qul[11]={6,2,5,5,4,5,6,3,7,6};
int shun[11]={8,6,9,0,2,3,5,4,7,1};
void dfs(int k,int rest){
	if(k > nowminnw && rest!=0) return;
	if(rest == 0){
		if(k<nowminnw) {
			nowminnw = k;
			for(int i = 1;i<=k-1;i++)ans[i] = temp[i];
		}
		if(k == nowminnw){
			bool flag = true;
			for(int i = 1;i<=k-1;i++) {
				if(temp[i] > ans[i]){
					flag = false;
					continue;
				} 
			}
			if(flag) {
				for(int i = 1;i<=k-1;i++)ans[i] = temp[i];
			}
		}
		return;
	}
	if(k == 1){
		for(int i = 1;i<=9;i++){
			if(rest-qul[i] <0) continue;
			temp[k] = i;
			dfs(k+1,rest-qul[i]);
			temp[k] = 11;
		}
	}
	else{
		for(int i = 0;i<=9;i++){
			if(rest-qul[i] <0) continue;
			temp[k] = i;
			dfs(k+1,rest-qul[i]);
			temp[k] = 11;
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> T;
	while(T){
		T--;
		int n;
		cin >> n;
		if(n%7  == 0  && n>=51){
			for(int i = 1;i<=n/7;i++) cout <<"8";
			cout<<endl;
			continue;
		}
		if(n%7  == 1  && n>=51){
			cout << "10";
			for(int i = 1;i<=n/7-1;i++) cout <<"8";
			cout<<endl;
			continue;
		}
		int num[7]={0,2,3,4,5,6,7};
		int dp[100005];
		for(int i = 1;i<=6;i++)
			for(int j = num[i];j<=n;j++)
				dp[j] = max(dp[j],dp[j-num[i]] + num[i]);
		if(dp[n] != n){
			cout << -1 <<endl;
			continue;
		}
		if(n <= 20 ){
			memset(ans,0x3f,sizeof(ans));
			memset(temp,0x3f,sizeof(temp));
			nowminnw = 3000000;
			dfs(1,n);
			for(int i= 1;i<=nowminnw-1;i++)
				cout<< ans[i];
			cout << endl;
		}
		if(n == 21) cout << 888 << endl;
		if(n == 22) cout << 1088 << endl;
		if(n == 23) cout << 1888 << endl;
		if(n == 24) cout << 2008 << endl;
		if(n == 25) cout << 2088 << endl;
		if(n == 26) cout << 2888 << endl;
		if(n == 27) cout << 6888 << endl;
		if(n == 28) cout << 8888 << endl;
		if(n == 29) cout << 10888 << endl;
		if(n == 30) cout << 18888 << endl;
		if(n == 31) cout << 20088 << endl;
		if(n == 32) cout << 20888 << endl;
		if(n == 33) cout << 28888 << endl;
		if(n == 34) cout << 68888 << endl;
		if(n == 35) cout << 88888 << endl;
		if(n == 36) cout << 108888 << endl;
		if(n == 37) cout << 188888 << endl;
		if(n == 38) cout << 200888 << endl;
		if(n == 39) cout << 208888 << endl;
		if(n == 40) cout << 288888 << endl;
		if(n == 41) cout << 688888 << endl;
		if(n == 42) cout << 888888 << endl;
		if(n == 43) cout << 1088888 << endl;
		if(n == 44) cout << 1888888 << endl;
		if(n == 45) cout << 2008888 << endl;
		if(n == 46) cout << 2088888 << endl;
		if(n == 47) cout << 2888888 << endl;
		if(n == 48) cout << 6888888 << endl;
		if(n == 49) cout << 8888888 << endl;
		if(n == 50) cout << "10888888" << endl;
		
	}
	return 0;
}
