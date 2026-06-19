#include<bits/stdc++.h>
#define int long long
#define rint register int
using namespace std;

int t,n;
int k1,k2,k3;
int a[100010][4];
int sum = -1;
int ans = 0;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int k){
	if(k>n){
		sum = max(sum,ans);
		return ;
	}
	if(k1<n/2){
		k1++;
		ans+=a[k][1];
	//	cout << ans << endl;
		dfs(k+1);
		ans-=a[k][1];
		k1--;
	}
	if(k2<n/2){
		k2++;
		ans+=a[k][2];
	//	cout << ans << endl;
		dfs(k+1);
		ans-=a[k][2];
		k2--;
	}
	if(k3<n/2){
		k3++;
		ans+=a[k][3];
		//cout << ans << endl;
		dfs(k+1);
		ans-=a[k][3];
		k3--;
	}
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--){
		memset(a,0,sizeof(a));
		sum = -1;
		ans = 0;
		k1 = 0,k2 = 0,k3 = 0;
		cin >> n;
		bool flag = false;
		for(int i = 1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2] !=0 || a[i][3] != 0){
				flag = true;
			}
		}
		if(flag){
			dfs(1);
			//cout << endl;
			cout << sum << endl;
		}else{
			int ff[100010];
			for(int i = 1;i<=n;i++){
				ff[i] = a[i][0];
				
			}
			sort(ff+1,ff+n+1,cmp);
			int sum = 0;
			for(int i = 1;i<=n/2;i++){
				sum += ff[i];
			}
			cout << sum << endl;
		}
	}
	return 0;
}
