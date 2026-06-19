#include<bits/stdc++.h>
using namespace std;
typedef pair<string,string> pss;
typedef unsigned long long ull;
#define fi first
#define se second
const int N = 2e5+5;
const ull base = 131;
int n,q;
pss a[N];
int beg[N];
map<pair<ull,ull>,vector<int> > mp;
ull hsh(string s,int l,int r){
	ull res = 0;
	for(int i = l;i<=r;i++){
		res = res*base + s[i];
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 1;i<=n;i++){
		cin >> a[i].fi >> a[i].se;
		int l = -1,r = a[i].fi.size();
		ull hsh1 = 0,hsh2 = 0;
		for(;l<(int)a[i].fi.size()-1;l++){
			hsh1 = hsh1*base + a[i].fi[l+1];
			hsh2 = hsh2*base + a[i].se[l+1];
			if(hsh1 != hsh2) break;
		}
		hsh1 = 0,hsh2 = 0;
		for(;r>0;r--){
			hsh1 = hsh1*base + a[i].fi[r-1];
			hsh2 = hsh2*base + a[i].se[r-1];
			if(hsh1 != hsh2) break;
		}
		//cout << l <<" " << r<< endl;
		if(l<r){
			mp[{hsh(a[i].fi,l+1,r-1),hsh(a[i].se,l+1,r-1)}].push_back(i);
			beg[i] = l+1;
		}
		//cout << beg[i] << endl;
	}
	while(q--){
		string t1,t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size()){
			printf("0\n");continue;
		}
		int l = -1,r = t1.size();
		ull hsh1 = 0,hsh2 = 0;
		for(;l<(int)t1.size()-1;l++){
			hsh1 = hsh1*base + t1[l+1];
			hsh2 = hsh2*base + t2[l+1];
			if(hsh1 != hsh2) break;
		}
		hsh1 = 0,hsh2 = 0;
		for(;r>0;r--){
			hsh1 = hsh1*base + t1[r-1];
			hsh2 = hsh2*base + t2[r-1];
			if(hsh1 != hsh2) break;
		}
		int len = r-l-1;
		vector<int> tmp = mp[{hsh(t1,l+1,r-1),hsh(t2,l+1,r-1)}];
		int ans = 0;
		for(int i:tmp){
			//cout << "i:"<<i << endl;
			if(beg[i] >= 1 && (l-beg[i]+1 < 0 || hsh(a[i].fi,0,beg[i]-1) != hsh(t1,l-beg[i]+1,l))) continue;
			if(beg[i]+len < (int)a[i].fi.size() && 
				(r+(int)a[i].fi.size()-beg[i]-len-1 >= (int)t1.size() || hsh(a[i].fi,beg[i]+len,(int)a[i].fi.size()-1) != hsh(t1,r,r+(int)a[i].fi.size()-beg[i]-len-1)))
				continue;
			ans ++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
