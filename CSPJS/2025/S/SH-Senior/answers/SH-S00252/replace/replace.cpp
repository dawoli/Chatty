#include<bits/stdc++.h>
using namespace std;
#define int long long
const int w=128;
const int seed=1e9+7;
map<string,int> m;
vector<vector<int>> v(200002);
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,bh=1; cin>>n>>q;
	for (int i=0;i<n;i++){
		string t1,t2,t=""; cin>>t1>>t2;
		int len=t1.size();
		int f=t1.size()-1,l=0;
		for (int j=0;j<len;j++){
			if (t1[j]!=t2[j]) f=j;
		}
		for (int j=len-1;j>=0;j--){
			if (t1[j]!=t2[j]) l=j;
		}
		if (f>=l){
			for (int j=l;j<=f;j++){
				t+=t1[j];
			}
			for (int j=l;j<=f;j++){
				t+=t2[j];
			}
			m[t]++; m[t]--;
			if (m[t]==0) m[t]=bh;
			string tt="";
			for (int y=l-1,j=f+1;y>=0||j<len;y--,j++){
				if (y>=0) tt+=t1[y]; 
				if (j<len) tt+=t1[j];
			} 
			int ans=0;
			for (int h=0;h<tt.size();h++){
				ans=ans*w%seed+tt[h];
			}
			v[m[t]].push_back(ans);
		}
	}
	for (int i=0;i<q;i++){
		int ans=0;
		string t1,t2,t=""; cin>>t1>>t2;
		int len=t1.size();
		int f=t1.size()-1,l=0;
		for (int j=0;j<len;j++){
			if (t1[j]!=t2[j]) f=j;
		}
		for (int j=len-1;j>=0;j--){
			if (t1[j]!=t2[j]) l=j;
		}
		for (int j=l;j<=f;j++){
			t+=t1[j];
		}
		for (int j=l;j<=f;j++){
			t+=t2[j];
		}
		m[t]++; m[t]--;
		if (m[t]==0) cout<<0<<endl;
		else{
			string tt="";
			vector<int> o;
			for (int y=l-1,j=f+1;y>=-1||j<=len;y--,j++){
				if (y>=0) tt+=t1[y]; 
				if (j<len) tt+=t1[j];
				int ans=0;
				for (int h=0;h<tt.size();h++){
					ans=ans*w%seed+tt[h];
				}
				o.push_back(ans);
			}
			for (int j=0;j<o.size();j++){
				for (int x=0;x<v[m[t]].size();x++){
					if (v[m[t]][x]==o[j]){
						ans++;
						break;
					}
				}
			}
			cout<<ans<<endl;
		} 
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
