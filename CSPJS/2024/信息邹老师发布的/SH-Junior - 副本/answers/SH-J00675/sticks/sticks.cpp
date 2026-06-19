#include<bits/stdc++.h>
using namespace std;
const int num[] = {6,2,5,5,4,5,6,3,7,6};
string ans;
bool com(string s1,string s2){
	int len1 = s1.size(),len2 = s2.size();
	if (len1 > len2) return true;
	else if (len1 < len2) return false;
	for (int i = 0; i < len1; i++){
		if (s1[i] > s2[i]) return true;
	}
	return false;
}
void dfs(int cur,int n,string sum){
	if (n <= 0){
		if (n == 0) 
			if(!com(sum,ans)) ans = sum;
		return ;
	}
	if (cur > 1) for (int i = 0; i <= 9;i++) dfs(cur + 1,n - num[i],sum + (char)(i + '0'));
	else if (cur == 1) for (int i = 1; i <= 9; i++) dfs(cur + 1,n - num[i],sum + (char)(i + '0'));
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if (n < 2) {
			puts("-1");
			continue;
		} 
		for (int i = 1; i * 2 <= n; i++) ans += '1';
		dfs(1,n,"");
		cout << ans << endl;
	} 
	return 0;
}
