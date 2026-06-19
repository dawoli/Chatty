#include<bits/stdc++.h>
using namespace std;

int t, n, k, q, sl[10010], r[10010], c[10010], tmp, cnt=0;
vector<int> s[100010];
map<int, int> mp;
int qjj[3003][3003][3];

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	scanf("%d", &t);
	for(int nxx=1;nxx<=t;nxx++) {
		scanf("%d%d%d", &n, &k, &q);
		for(int i=1;i<=n;i++) {
			scanf("%d", &sl[i]);
			for(int j=1;j<=sl[i];j++) {
				scanf("%d", &tmp);
				if(mp[tmp]==0) {
					mp[tmp]=cnt+1;
					cnt++;
				}
				tmp=mp[tmp];
				s[i].push_back(tmp);
			}
		}
		
		for(int j=1;j<=q;j++) scanf("%d%d", &r[j], &c[j]);
		memset(qjj, 0, sizeof(qjj));
		
		for(int i=2;i<=k;i++) {
			for(int j=1;j<=n;j++) {
				for(int lk=0;lk<=sl[j]-i;lk++) {
					int een=lk+i-1;
					if(qjj[s[j][lk]][s[j][een]][1]==0) qjj[s[j][lk]][s[j][een]][1]=j;
					else qjj[s[j][lk]][s[j][een]][2]=j;
				}
			}
		}
		for(int i=1;i<=cnt;i++) {
			for(int j=i+1;j<=n;j++) {
				for(int l=j+1;l<=n;l++) {
					if(qjj[i][j][1]*qjj[j][l][1]==0) continue;
					if(qjj[i][j][1]!=qjj[j][l][1]) {
						qjj[i][l][1]=qjj[i][l][2]=qjj[j][l][1];
						break;
					}
					if(qjj[i][j][1]*qjj[j][l][2]==0) continue;
					qjj[i][l][1]=qjj[i][l][2]=qjj[j][l][2];
				}
			}
		}
		for(int i=1;i<=q;i++) {
			if(qjj[1][c[i]][1]!=0||qjj[1][c[i]][1]!=0) cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
