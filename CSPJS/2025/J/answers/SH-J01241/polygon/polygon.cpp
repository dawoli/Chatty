#include<bits/stdc++.h>
using namespace std;
int n[1000005];
int n1;
int ans = 0;
//map<string,int> mem;


int k = 1;


void dfs(int a,int tf,int sum1,int sum2,string s) {


	if(a >= n1+1) {
		if(sum1 > sum2 * 2) {
			ans++;
		}
	} else if(a == n1 && tf == 2) {
		dfs(a+1,tf+1,sum1+n[a],max(sum2,n[a]),s+'1');
	}//zhenghao
	else if(a == n1 && tf < 2) return;
	else {
		dfs(a+1,tf+1,sum1+n[a],max(sum2,n[a]),s+'1');
		dfs(a+1,tf,sum1,sum2,s+'0');
	}






}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n1;
	for(int i =1; i <= n1; i++) {
		cin >> n[i];
	}
	dfs(1,0,0,0,"");
	cout << ans % 998244353<< endl;


	fclose(stdin);
	fclose(stdout);
	return 0;
}
