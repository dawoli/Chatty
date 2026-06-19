#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define N 200114
string s[N],t[N];
int ps[N],pt[N];
int len[N];
string sq[N],tq[N];
int d[N];
unordered_map<int,vector<pair<int,int> > > cnt;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	int n,nq;
	cin>>n>>nq;
	bool fl=true;
	for(int i=1;i<=n;i++) {
		cin>>s[i]>>t[i];
		for(int j=0;j<s[i].size();j++) {
			if(s[i][j]=='b') {
				if(ps[i]) {
					fl=false;
					break;
				}
				ps[i]=j+1;
			} 
			if(t[i][j]=='b') {
				if(pt[i]) {
					fl=false;
					break;
				}
				pt[i]=j+1;
			} 
			if(s[i][j]>'b') fl=false;
			if(t[i][j]>'b') fl=false;
		}
		len[i]=s[i].size();
		d[i]=ps[i]-pt[i];
		cnt[d[i]].push_back(make_pair(ps[i],pt[i]));
	}
	for(int i=-n;i<=n;i++) {
		if(cnt[i].size()!=0) {
			sort(cnt[i].begin(),cnt[i].end());
		} 
	} 
	for(int i=1;i<=nq;i++) {
		cin>>sq[i]>>tq[i];
		if(sq[i].size()!=tq[i].size()) {
			cout<<"0\n";
			continue;
		}
		bool fl2=true,cntwe=0;
		for(int j=0;j<sq[i].size();j++) {
			if(sq[i][j]>'b') {
				fl2=false;
				break;
			}
			if(sq[i][j]=='b') cntwe++;	
		}
		if(cntwe!=1) fl2=false;
		if(not(fl)||not(fl2)) {
			int ans=0;
			for(int k=1;k<=n;k++) {//用手上每一个n对照前面的
				if(s[k]==t[k]) continue;
				if(sq[i].size()<len[k]) continue;
				for(int j=0;j<sq[i].size()-len[k]+1;j++) {
					string w=sq[i];
					if(w[j]==s[k][0]) {
						for(int l=0;l<len[k];l++) {
							w[j+l]=t[k][l];
						}
					}
					if(w==tq[i]) {
						ans++;
						break;
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		int ps2=0,pt2=0; 
		for(int j=0;j<sq[i].size();j++) {
			if(sq[i][j]=='b') {
				ps2=j+1;
				break;
			}
		}
		for(int j=0;j<tq[i].size();j++) {
			if(tq[i][j]=='b') {
				pt2=j+1;
				break;
			}
		}
		int x=lower_bound(cnt[ps2-pt2].begin(),cnt[ps2-pt2].end(),make_pair(ps2,pt2))-cnt[ps2-pt2].begin();
		cout<<x<<"\n";
	}
	return 0;
} 
