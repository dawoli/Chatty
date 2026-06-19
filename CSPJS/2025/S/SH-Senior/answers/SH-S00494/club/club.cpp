#include<bits/stdc++.h>
using namespace std;
#define int long long
int m[100005];
int h[4];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		h[1]=0;
		h[2]=0;
		h[3]=0;
		int ans=0;
		multiset<int> s[4];
		for(int i=1;i<=n;i++) {
			int a,b,c;
			cin >> a >> b >> c;
			if(a>b&&a>c) {
				m[i]=a;
				h[1]++;
				s[1].insert(min(a-b,a-c));
			}
			else if(b>c) {
				m[i]=b;
				h[2]++;
				s[2].insert(min(b-a,b-c));
			}
			else {
				m[i]=c;
				h[3]++;
				s[3].insert(min(c-b,c-a));
			}
			ans+=m[i];
		}
		if(h[1]>n/2) {
			for(int i=h[1];i>n/2;i--) {
				set<int>::iterator it=s[1].begin();
				ans-=*it;
				s[1].erase(it);
			}
		}
		if(h[2]>n/2) {
			for(int i=h[2];i>n/2;i--) {
				set<int>::iterator it=s[2].begin();
				ans-=*it;
				s[2].erase(it);
			}
		}
		if(h[3]>n/2) {
			for(int i=h[3];i>n/2;i--) {
				set<int>::iterator it=s[3].begin();
				ans-=*it;
				s[3].erase(it);
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
