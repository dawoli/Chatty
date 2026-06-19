#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000009;
const int N = 200009;
int n,q,ans;
string s[N][3],t[N][3];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s[i][1]>>s[i][2];
	}for(int i=1;i<=q;i++) {
		cin>>t[i][1]>>t[i][2];
	}if(n<=100&&q<=100) {
		for(int i=1;i<=q;i++) {
			string tmp2;
			for(int l=0;l<t[i][1].size();l++) {//起始替换位置 
				if(l>0) tmp2+=t[i][1][l-1];//前缀 
				for(int k=1;k<=n;k++) {//谐音 
					string tmp=tmp2;//开始替换 
					int x=l;//t起始位置 
					int maxs=s[k][1].size(),maxt=t[i][1].size();//长度 
					if(l+maxs>=maxt) continue;
					for(int tk=0;x<l+maxs;x++,tk++) {
						if((t[i][1][x]!=s[k][1][tk])||(s[k][2][tk]!=t[i][2][x])) continue;
						tmp+=s[k][2][tk];
					}
					for(;x<t[i][1].size();x++) {
						tmp+=t[i][x];
					}
					if(tmp==t[i][2]) {
						ans++;
					}
					cout<<tmp<<endl;
				}
			}
			cout<<ans<<endl;
			ans=0;
		}
	}
	return 0;
}
