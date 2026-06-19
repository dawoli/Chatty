#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int T,n,ans;
int a[N];
bool clr[N];
int pre[N];
int preclr[N];
int p[N];

void dfs(int dep){
	if (dep > n){
		int sum = 0;
		for (int i = 0;i <= n;i++) preclr[i] = 0;
		int red = 0,blue = 0;
		for (int i = 1;i <= n;i++){
			if (clr[i] == 0){
				preclr[i] = red;
				red = i;
			}else{
				preclr[i] = blue;
				blue = i;
			}
		}

		for (int i = 1;i <= n;i++){
			if (preclr[i] == 0) sum += 0;
			else if (a[i] == a[preclr[i]]) sum += a[i];
		}
		
		ans = max(sum,ans);
		return;
	}
	clr[dep] = 0;
	dfs(dep+1);
	clr[dep] = 1;
	dfs(dep+1);
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	cin>>T;
	while (T--){
		
		ans = 0;
		for (int i = 0;i < N;i++){
			p[i] = 0;
			pre[i] = 0;
		}
		
		cin>>n;
		for (int i = 1;i <= n;i++) cin>>a[i];
		
		for (int i = 2;i <= n;i++){
			p[a[i-1]] = i-1;
			pre[i] = p[a[i]];
		}
		
		dfs(1);
		
		cout<<ans<<endl;
	}
	return 0;
}
