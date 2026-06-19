#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,L=5e6;
const int bas=131,yjy=998244353,zyx=1e9+7;
//love_zyx
typedef long long ll;
typedef pair<ll,ll> pll;
int n,q,len[N],ans;
string s[2];
pll h[2][N],tmp;
vector<pll> hq[2];
ll pwy[L],pwz[L];
void print(pll x)
{
	cout<<x.first<<' '<<x.second<<endl;
}
pll add(pll x,pll y)
{
	pll res;
	res.first=(x.first+y.first)%yjy;
	res.second=(x.second+y.second)%zyx;
	return res;
}
pll sub(pll x,pll y)
{
	pll res;
	res.first=(x.first-y.first)%yjy;
	res.second=(x.second-y.second)%zyx;
	return res;
}
pll ls(pll x,int b)
{
	pll res;
	res.first=x.first*pwy[b]%yjy;
	res.second=x.second*pwz[b]%zyx;
	return res;
}
pll gethash(int l,int r)
{
	pll res=ls(hq[0][l-1],r-l+1);
	res=sub(hq[0][r],res);
	return res;
}
bool equal(pll x,pll y)
{
	x.first+=yjy;
	x.first%=yjy;
	x.second+=zyx;
	x.second%=zyx;
	y.first+=yjy;
	y.first%=yjy;
	y.second+=zyx;
	y.second%=zyx;
	return x==y;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	pwy[0]=1;
	pwz[0]=1;
	for(int i=1;i<L;i++)
	{
		pwy[i]=pwy[i-1]*bas%yjy;
		pwz[i]=pwz[i-1]*bas%zyx;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s[0]>>s[1];
		len[i]=s[0].size();
		tmp=make_pair(0,0);
		for(int j=1;j<=len[i];j++)
		{
			tmp.first=tmp.first*bas+s[0][j-1]-'a'+1;
			tmp.first%=yjy;
			tmp.second=tmp.second*bas+s[0][j-1]-'a'+1;
			tmp.second%=zyx;
		}
		h[0][i]=tmp;
		tmp=make_pair(0,0);
		for(int j=1;j<=len[i];j++)
		{
			tmp.first=tmp.first*bas+s[1][j-1]-'a'+1;
			tmp.first%=yjy;
			tmp.second=tmp.second*bas+s[1][j-1]-'a'+1;
			tmp.second%=zyx;
		}
		h[1][i]=tmp;
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>s[0]>>s[1];
		int sz=s[0].size();
		hq[0].resize(sz+1);
		hq[1].resize(sz+1);
		hq[0][0]=make_pair(0,0);
		hq[1][0]=make_pair(0,0);
		for(int j=1;j<=sz;j++)
		{
			tmp.first=hq[0][j-1].first*bas+s[0][j-1]-'a'+1;
			tmp.first%=yjy;
			tmp.second=hq[0][j-1].second*bas+s[0][j-1]-'a'+1;
			tmp.second%=zyx;
			hq[0][j]=tmp;
			tmp.first=hq[1][j-1].first*bas+s[1][j-1]-'a'+1;
			tmp.first%=yjy;
			tmp.second=hq[1][j-1].second*bas+s[1][j-1]-'a'+1;
			tmp.second%=zyx;
			hq[1][j]=tmp;
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<sz;k++)
			{
				int r=k+len[j];
				if(r>sz)break;
				tmp=gethash(k+1,r);
				if(!equal(h[0][j],tmp))continue;
				pll ch=add(sub(hq[0][sz],ls(h[0][j],sz-r)),ls(h[1][j],sz-r));
				if(equal(ch,hq[1][sz]))ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
