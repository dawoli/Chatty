#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int T, n, a[N];
bool color[N];
long long ans;

void dfs(int k){
//	cout<<k<<endl;
	if(k > n){
		long long tmp = 0;
		for(int i=1; i<=n; i++){
			int idx = -1;
			for(int j=i-1; j>=1; j--){
				if(color[j] == color[i] && a[i] == a[j]){
					idx = j;
					break;
				}
			}
//			printf("%d: %d\n", i, idx);
			if(idx != -1) tmp += a[idx];
		}
		ans = max(tmp, ans);
		return;
	}
	for(int i=0; i<=1; i++){
		color[k] = i;
		dfs(k+1);
	}
}

bool cmp(int i, int j){
	return i > j;
}

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		ans = 0;        
	 	dfs(1);          
	 	cout<<ans<<endl;
	}
	return 0;
}
