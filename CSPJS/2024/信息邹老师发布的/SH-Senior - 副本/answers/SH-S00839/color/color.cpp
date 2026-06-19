#include<bits/stdc++.h>
using namespace std;
int n;
int A[200005];
//int co[200005];
//int l1,l2;
int dfs(int i ,int l1,int l2){
	if(i >= n){
		if(A[l1] == A[i] || A[l2] == A[i]){
			return A[i];
		}
	}
	int ans = 0;
	if(A[l1] == A[i]){
		ans = max(ans, A[i] + dfs(i+1,i,l2));
	}else{
		ans = max(ans, dfs(i+1,i,l2));
	}
	if(A[l2] == A[i]){
		ans = max(ans, A[i] + dfs(i+1,l1,i));
	}else{
		ans = max(ans, dfs(i+1,l1,i));
	}
	return ans;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> A[i];
		}
		if(n <= 16){
//			cout << 1;
			cout << dfs(1,0,0) << endl;
		}else{
			cout << 0 << endl;
		}
	}
	
	return 0;
} 
