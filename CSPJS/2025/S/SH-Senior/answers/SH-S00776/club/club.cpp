#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,pref[100005][4],c1,c2,c3,ans,over,counted;
vector<int> v;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		c1 = c2 = c3 = ans = over = 0;
		for(int i = 0; i < n; i++){
			cin >> pref[i][0] >> pref[i][1] >> pref[i][2];
			pref[i][3] = 0;
			if(pref[i][1]>pref[i][0])pref[i][3] = 1;
			if(pref[i][2]>pref[i][0] && pref[i][2] > pref[i][1])pref[i][3] = 2;
			if(pref[i][3] == 1)c2++;
			else if(pref[i][3] == 2)c3++;
			else c1++;
		}
		if(max(max(c1,c2),c3) <= n/2){
			for(int i = 0; i < n; i++)ans += pref[i][pref[i][3]];
			cout << ans << '\n';
		}
		else{
			v.clear();
			over = ((c1 > n/2)?0:((c2 > n/2)?1:2));
			if(over == 0)counted = c1;
			else if(over == 1)counted = c2;
			else counted = c3;
			for(int i = 0; i < n; i++)ans += pref[i][pref[i][3]];
			for(int i = 0; i < n; i++){
				if(pref[i][3] == over){
					v.push_back(pref[i][over] - max(pref[i][(over+1)%3],pref[i][(over+2)%3]));
				}
			}
			sort(v.begin(),v.end());
			for(int i = 0; i < counted - n/2; i++){
				ans -= v[i];
			}
			cout << ans << '\n';
		}
	}
	return 0;
}  
