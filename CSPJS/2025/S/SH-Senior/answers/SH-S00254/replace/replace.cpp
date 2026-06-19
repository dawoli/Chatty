#include<bits/stdc++.h>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define pc putchar
int n,q;
string s[200010][3];
string t[200010][3];
#define ull unsigned long long
ull hsh1[200010],hsh2[200010],hsh3[200010];
int ft[200010],lt[200010],len[200010];
ull pw[200010];
const ull bs=107;
ull hs(int l,int r)
{
	return hsh3[r]-hsh3[l-1]*pw[r-l+1];
}
gp_hash_table<ull,int> mp;
vector<int> g[200010];
int cnt=0;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	rep(i,1,n) cin>>s[i][1]>>s[i][2];
	rep(i,1,q) cin>>t[i][1]>>t[i][2];
	pw[0]=1;
	rep(i,1,200000) pw[i]=pw[i-1]*bs;

		rep(i,1,n)
		{
			int p=s[i][1].size();
			len[i]=p;
			int fst=-1,lst=-1;
			rep(j,0,p-1)
			{
				if(s[i][1][j]!=s[i][2][j])
				{
					if(fst==-1) fst=j;
					lst=j;
				}
			}
			ft[i]=fst,lt[i]=lst;
			if(fst==-1&&lst==-1) continue;
			rep(j,fst,lst)
			{
				hsh1[i]=hsh1[i]*bs+(ull)(s[i][1][j]-'a');
				hsh1[i]=hsh1[i]*bs+(ull)(s[i][2][j]-'a');
			}
			if(mp[hsh1[i]]==0) 
			{
				mp[hsh1[i]]=++cnt;
				g[cnt].push_back(i);
			}
			else
			{
				g[mp[hsh1[i]]].push_back(i);
			}
			rep(j,0,p-1)
			{
				hsh2[i]=hsh2[i]*bs+(ull)(s[i][2][j]-'a');
			}
		//	cout<<fst<<" "<<lst<<" "<<hsh1[i]<<" "<<hsh2[i]<<endl;
		}
		rep(i,1,q)
		{
			int ans=0;
			ull thsh=0;
			int fst=-1,lst=-1;
			int p=t[i][1].size();
			rep(j,0,p-1)
			{
				if(t[i][1][j]!=t[i][2][j])
				{
					if(fst==-1) fst=j;
					lst=j;
				}
				if(j==0) hsh3[j]=(t[i][2][j]-'a');
				else hsh3[j]=hsh3[j-1]*bs+(t[i][2][j]-'a');
			}
			rep(j,fst,lst)
			{
				thsh=thsh*bs+(ull)(t[i][1][j]-'a');
				thsh=thsh*bs+(ull)(t[i][2][j]-'a');
			}
		//	cout<<thsh<<endl;
			int l=mp[thsh];
			if(l==0) 
			{
				cout<<0<<'\n';
				continue;
			}
			for(auto j:g[l])
			{
				if(thsh!=hsh1[j]) continue;
				if(ft[j]==-1||lt[j]==-1) continue;
				if(lst-fst+1!=lt[j]-ft[j]+1) continue;
				if(fst-(ft[j])<0) continue;
				if(lst+(len[j]-1-lt[j])>=p) continue;
				if(hsh2[j]==hs(fst-(ft[j]),lst+(len[j]-1-lt[j]))) ++ans;
			} 
			cout<<ans<<'\n';
		}
} 
