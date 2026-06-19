#include<bits/stdc++.h>
using namespace std;
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
}
#define N 222222
#define M 5555555
#define int long long
const int base=20270417,mod=20271109;
int n,q,p1[M],p2[M],x[N],y[N],p0[N];
map<int,int>len1[128],len2[128];
map<int,map<int,int> >cnt1[128],cnt2[128],cnt;
int fp(int u,int v){
	if(!v)return 1;
	return fp(u*u%mod,v>>1)*(v&1?u:1)%mod;
}
int hsh(const string&x,int*p=p0){
	for(int i=1;i<=x.size();i++)
		p[i]=(p[i-1]*base+x[i-1])%mod;
	return p[x.size()];
}
int get(int l,int r,int*p=p0){
	return(p[r]-p[l-1]*fp(base,r-l+1)%mod+mod)%mod;
}
signed main(){
	open("replace");
	cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		x[i]=hsh(s1),y[i]=hsh(s2);
		if(cnt[x[i]][y[i]]){
			++cnt[x[i]][y[i]];
			continue;
		}
		cnt[x[i]][y[i]]=1;
		len1[s1.front()][s1.size()]=1;
		len2[s2.front()][s2.size()]=1;
		cnt1[s1.front()][x[i]][i]=1;
		cnt2[s2.front()][y[i]][i]=1;
	}
	while(q--){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}hsh(s1,p1),hsh(s2,p2);
		int m=s1.size(),ans=0,r=0;
		for(int i=m;i>=1;i--)
			if(s1[i-1]!=s2[i-1]){
				r=i;
				break;
			}
		for(int i=1;i<=m;i++){
			for(auto&k:len1[s1[i-1]])
				if(len2[s2[i-1]][k.first]&&i+k.first>r){
					int a=get(i,i+k.first-1,p1),b=get(i,i+k.first-1,p2);
//					cerr<<i<<' '<<k.first<<' '
//						<<(p1[i+k.first-1]==(p1[i+k.first-3]*fp(base,2)%mod+
//							s1[i+k.first-3]*base%mod+s1[i+k.first-2])%mod)<<' '
//						<<hsh("bc")<<' '<<hsh("de")<<endl;
					for(auto&l:cnt1[s1[i-1]][a])
						if(cnt2[s2[i-1]][b][l.first]){
//							cerr<<i<<' '<<k.first<<' '<<r<<' '<<l.first<<endl;
							ans+=cnt[x[l.first]][y[l.first]];
						}
				}
			if(s1[i-1]!=s2[i-1])break;
		}
		cout<<ans<<endl;
	}
}
