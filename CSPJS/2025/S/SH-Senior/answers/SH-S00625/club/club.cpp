#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1.1e5;
int T,n;
ll a[N][5],b[N],mx[N],d[N];
ll cnt[5];
ll ans;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--) {
		//init
		memset(cnt,0,sizeof(cnt));
		ans=0;
		cin >> n;
		for(int i=1;i<=n;i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) {
				mx[i]=1;
				cnt[1]++;
				d[i]=a[i][1]-max(a[i][2],a[i][3]);
			}
			else if(a[i][2]>=a[i][3]) {
				mx[i]=2;
				cnt[2]++;
				d[i]=a[i][2]-max(a[i][1],a[i][3]);
			}
			else {
				mx[i]=3;
				cnt[3]++;
				d[i]=a[i][3]-max(a[i][1],a[i][2]);
			}
			ans+=a[i][mx[i]];
		}
		int r=0;
		if(cnt[1]>(n/2)) r=1;
		if(cnt[2]>(n/2)) r=2;
		if(cnt[3]>(n/2)) r=3;
		if(r==0) cout << ans << '\n';
		else {
			int rn=0;
			for(int i=1;i<=n;i++) {
				if(mx[i]==r) {
					rn++;
					b[rn]=d[i];
				}
			}
			sort(b+1,b+rn+1);
			for(int i=1;i<=rn-(n/2);i++) {
				ans-=b[i];
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
