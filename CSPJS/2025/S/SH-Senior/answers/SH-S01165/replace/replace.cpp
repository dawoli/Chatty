#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const int N=2e5+5,M=5e6+5;
const LL bs=13331;

int n,q;
string s1[N],s2[N];
LL p[M];
vector<LL> h1[N],h2[N],ha,hb;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	p[0]=1;
	for(int i=1; i<M; i++) p[i]=p[i-1]*bs;
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>s1[i]>>s2[i];
		int len=s1[i].size();
		h1[i].resize(len+1),h2[i].resize(len+1);
		h1[i][0]=h2[i][0]=0;
		for(int j=1; j<=len; j++){
			h1[i][j]=h1[i][j-1]*bs+s1[i][j-1];
			h2[i][j]=h2[i][j-1]*bs+s2[i][j-1];
		}
//		cout<<s1[i]<<':'<<h1[i][len]<<' '<<s2[i]<<':'<<h2[i][len]<<endl;
//		hp[{h1[i][len],h2[i][len]}]++;
	}
	for(int i=1; i<=q; i++){
		string sa,sb;
		cin>>sa>>sb;
		int len=sa.size();
		ha.resize(len+1),hb.resize(len+1);
		ha[0]=hb[0]=0;
		for(int j=1; j<=len; j++){
			ha[j]=ha[j-1]*bs+sa[j-1];
			hb[j]=hb[j-1]*bs+sb[j-1];
		}
		int res=0;
		for(int l=1; l<=len; l++){
			for(int r=len; r>=l; r--){
				LL A=ha[r]-ha[l-1]*p[r-l+1],B=hb[r]-hb[l-1]*p[r-l+1];
//				cout<<l<<' '<<r<<' '<<A<<' '<<B<<endl;
				int cnt=0;
				for(int j=1; j<=n; j++)
					if(h1[j][s1[j].size()]==A&&h2[j][s2[j].size()]==B)
						cnt++;
				res+=cnt;
				if(sa[r-1]!=sb[r-1]) break;
			}
			if(sa[l-1]!=sb[l-1]) break;
		}
		cout<<res<<endl;
	}
	return 0;
}
