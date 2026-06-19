#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+9;
const int SMN=1e3+9;
const int SML=2e3+9;
const int base=998244353;
const int MOD=2e9+7;
int n,q;
string s[N][3],t[N][3];
void solveBF(){
	for(int i=1;i<=q;i++){//处理每个问题 
		int lpos=n+1; int rpos=-1;
		for(int j=0;j<t[i][1].size();j++){
			if(t[i][1][j]!=t[i][2][j]) lpos=min(lpos,j),rpos=max(rpos,j);
			else continue;
		}
//		cout<<"lpos:"<<lpos<<" "<<"rpos:"<<rpos<<endl;
		int len=rpos-lpos+1;
		int ans=0;
		for(int j=1;j<=n;j++){
//			cout<<"判断"<<s[j][1]<<endl;
			bool ok=0;
			if(s[j][1].size()<len) continue;
			else{
				for(int k=max(0LL,(int)(rpos-s[j][1].size()+1));k+s[j][1].size()-1<t[i][1].size();k++){
//					cout<<"开始"<<k<<":";
					string subt1=""; string subt2="";
					for(int pos=k;pos<=k+s[j][1].size()-1;pos++) subt1+=t[i][1][pos],subt2+=t[i][2][pos];
//					cout<<subt1<<" "<<subt2<<endl;
					if(subt1==s[j][1]&&subt2==s[j][2]){
						ok=1;
						break;
					}
				}
			}
			if(ok==1) ans++;
		}
		cout<<ans<<endl;
	}
}
void solve(){
	
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int lensum=0;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2],lensum+=s[i][1].size()+s[i][2].size();
	for(int i=1;i<=q;i++) cin>>t[i][1]>>t[i][2],lensum+=t[i][1].size()+t[i][2].size();
	if(n<=1e3&&q<=1e3&&lensum<=2e3) solveBF();
	else solve();
	return 0;
}
