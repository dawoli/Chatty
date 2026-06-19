#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n,t,sum = 0,num[8];

struct mem {
	int a,b,c;
	int lmax,tmax,cnt0;
	bool operator < (const mem& rhs) {
		if(cnt0 != rhs.cnt0)
			return cnt0 > rhs.cnt0;
		return lmax > rhs.lmax;
	}
}m[N];

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	while(t--) {
		sum = 0;
		memset(num,0,sizeof(num));
		
		cin >> n;
		for(int i = 1;i <= n;i++) {
			cin >> m[i].a >> m[i].b >> m[i].c;
			m[i].lmax = max(m[i].a,max(m[i].b,m[i].c));
			if(m[i].lmax == m[i].a) {
				m[i].tmax = 1;
			} else if(m[i].lmax == m[i].b) {
				m[i].tmax = 2;
			} else {
				m[i].tmax = 3;
			}
			m[i].cnt0 = (m[i].a == 0) + (m[i].b == 0) + (m[i].c == 0);
		}
		sort(m+1,m+n+1);
		for(int i = 1;i <= n;i++) {
			if(num[m[i].tmax] >= n/2) {
				int fst = max(m[i].a,max(m[i].b,m[i].c));
				int trd = min(m[i].a,min(m[i].b,m[i].c));
				if(fst != m[i].a && trd != m[i].a)
					m[i].lmax = m[i].a, m[i].tmax = 1;
				else if(fst != m[i].b && trd != m[i].b)
					m[i].lmax = m[i].b, m[i].tmax = 2;
				else
					m[i].lmax = m[i].c, m[i].tmax = 3;
			}
			sum += m[i].lmax;
			num[m[i].tmax]++;
		}
		cout << sum << "\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
