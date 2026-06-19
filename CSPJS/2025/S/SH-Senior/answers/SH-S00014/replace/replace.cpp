#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int n,q;
string s[N][2],t0,t1;
int same[N];

signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++) {
		cin>>t0>>t1;
		if(t0.length()!=t1.length()) cout<<0<<'\n';
		else {
			int len=t0.length(),ans=0;
			same[0]=(t0[0]==t1[0]);
			for(int j=1;j<len;j++) same[j]=same[j-1]+(int)(t0[j]==t1[j]);
			for(int j=0;j<len;j++) {
				for(int k=1;k<=n;k++) {
					if(same[j-1]!=j||same[len-1]-same[j+s[k][0].length()-1]!=len-j-s[k][0].length()) continue;
					int temp=0;
					while(temp<=s[k][0].length()&&temp<len&&t0[temp+j]==s[k][0][temp]&&s[k][1][temp]==t1[temp+j]) temp++;
					if(temp==s[k][0].length()&&same[j-1]==j&&same[len-1]-same[j+s[k][0].length()-1]==len-j-s[k][0].length()) {
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}	
	return 0;
}
