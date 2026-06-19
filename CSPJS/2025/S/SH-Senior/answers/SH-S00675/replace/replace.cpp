#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node {
	int len, idx;
};

bool cmp(Node a, Node b) {
	return a.len<b.len;
}

int bifind(vector<Node> s1, int x) {
	int l=1, r=(int)s1.size()-1, ans=-1;
	while(l<=r) {
		int mid=(l+r)/2;
		if(s1[mid].len==x) {
			ans=mid, r=mid-1;
		}
		else if(s1[mid].len<x) l=mid+1;
		else r=mid-1;
	}
	return ans;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n, q;
	cin>>n>>q;
	vector<string> sstr1(n+1);
	vector<string> sstr2(n+1);
	for(int i=1;i<=n;i++) cin>>sstr1[i]>>sstr2[i];
	vector<Node> a(n+1);
	for(int i=1;i<=n;i++) {
		int cnt=0;
		for(int j=0;j<(int)sstr1[i].length();j++) {
			if(sstr1[i][j]==sstr2[i][j]) continue;
			cnt++;
		}
		a[i].len=cnt; a[i].idx=i;
	}
	sort(a.begin()+1, a.end(), cmp);
	
	
	while(q--) {
		string tstr1, tstr2;
		cin>>tstr1>>tstr2;
		if((int)tstr1.length()!=(int)tstr2.length()) {
			cout<<0<<endl;
			continue;
		}
		int cnt=0;
		for(int i=0;i<(int)tstr1.length();i++) {
			if(tstr1[i]==tstr2[i]) continue;
			cnt++;
		}
		int x=bifind(a, cnt);
		if(a[x].len>cnt||x==-1) {
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int i=x;a[i].len==cnt;i++) {
			if((int)tstr1.find(sstr1[a[i].idx])==(int)-1||(int)tstr2.find(sstr2[a[i].idx])==(int)-1) continue;
			if(tstr1.find(sstr1[a[i].idx])==tstr2.find(sstr2[a[i].idx])) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
