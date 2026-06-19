#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[11451];
int b[11451];
int c[11451];
void dfs(int x)
{
	if(x==n+1){
//		for(int i=1;i<=n;i++) cout << b[i];
//		cout << endl;
		int ret = 0;
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(b[i]==b[j]){
					if(a[i]==a[j]) c[i] = a[j];
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			ret += c[i];
			c[i] = 0;
		}
		ans = max(ans,ret);
		return;
	}
	b[x]=1;
	dfs(x+1);
	b[x]=0;
	dfs(x+1);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		ans = 0;
		dfs(2);
		cout << ans << endl;
	}
	return 0;
}

