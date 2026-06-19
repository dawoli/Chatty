#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+10;
const int mod=998244353;
const int base=13331;
const int inf=0x3f3f3f3f;
int n,q;
string s[N][2];
int len[N];
struct Hash{
	vector<int> hash,pw;
	inline void init(string &s){
		int n=s.size();
		s=' '+s;
		hash.resize(n+10),pw.resize(n+10);
		hash[0]=0,pw[0]=1;
		for(int i=1;i<=n;i++){
			hash[i]=(1ll*hash[i-1]*base+s[i]-'a')%mod;
			pw[i]=1ll*pw[i-1]*base%mod;
		}
	}
	inline int get(int l,int r){
		return (hash[r]-1ll*hash[l-1]*pw[r-l+1]%mod+mod)%mod;
	}
}a[N][2];
vector<pii> vec[26*26];
inline int get(int x,int y){ return x*26+y; }
inline int calc(string t1,string t2){
	if(t1.size()!=t2.size())
		return 0;
	int m=t1.size();
	Hash h1,h2;
	h1.init(t1),h2.init(t2);
	int pre=0,suf=m+1;
	for(int i=1;i<=m;i++)
		if(t1[i]!=t2[i]){
			pre=i;
			break;
		}
	for(int i=m;i>=1;i--)
		if(t1[i]!=t2[i]){
			suf=i;
			break;
		}
	pii minx={inf,0};
	for(int i=pre;i<=suf;i++)
		minx=min(minx,{vec[get(t1[i]-'a',t2[i]-'a')].size(),i});
	int ans=0,pos1=minx.second;
	for(auto p:vec[get(t1[pos1]-'a',t2[pos1]-'a')]){
		int id=p.first,pos2=p.second;
		int l=pos1-pos2+1,r=l+len[id]-1;
		if(l<=0||r>=m+1||l>pre||r<suf)
			continue;
		ans+=(a[id][0].get(1,len[id])==h1.get(l,r)&&a[id][1].get(1,len[id])==h2.get(l,r));
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1],len[i]=s[i][0].size();
		a[i][0].init(s[i][0]),a[i][1].init(s[i][1]);
		for(int j=1;j<=len[i];j++)
			vec[get(s[i][0][j]-'a',s[i][1][j]-'a')].push_back({i,j});
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		cout<<calc(t1,t2)<<endl;
	}
	return 0;
}
