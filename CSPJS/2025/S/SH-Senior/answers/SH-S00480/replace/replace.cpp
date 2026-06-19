#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,q,sub[200009],mx[200009];
struct _REP
{
	string fr,to;
} rep[200009];
struct _QEY
{
	string fr,to;
} qes[200009];
map<char,ll> mp;

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	bool flag=true;
	scanf("%lld %lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>rep[i].fr>>rep[i].to;
		mp.clear();
		for(unsigned j=0;j<rep[i].fr.length();j++)
			mp[rep[i].fr[j]]++;
		if(!(mp['a']==(ll)rep[i].fr.length()-1&&mp['b']==1LL))
			flag=false;
		mp.clear();
		for(unsigned j=0;j<rep[i].to.length();j++)
			mp[rep[i].to[j]]++;
		if(!(mp['a']==(ll)rep[i].to.length()-1&&mp['b']==1LL))
			flag=false;
	}
	if(flag)
	{
		for(int i=1;i<=n;i++)
		{
			ll posa=-1,posb=-1,l=0;
			for(int j=0;j<(ll)rep[i].fr.length();j++)
			{
				if(rep[i].fr[j]=='b')
					posa=j,l=j;
			}
			for(int j=0;j<(ll)rep[i].to.length();j++)
			{
				if(rep[i].to[j]=='b')
					posb=j;
			}
			sub[i]=posa-posb;
			mx[i]=l;
		}
		ll ans=0;
		for(int i=1;i<=q;i++)
		{
			cin>>qes[i].fr>>qes[i].to;
			ll posa=-1,posb=-1,l=0;
			for(int j=0;j<(ll)qes[i].fr.length();j++)
			{
				if(qes[i].fr[j]=='b')
					posa=j,l=j;
			}
			for(int j=0;j<(ll)qes[i].to.length();j++)
			{
				if(qes[i].to[j]=='b')
					posb=j;
			}
			for(int j=1;j<=n;j++)
			{
				if(sub[j]==posa-posb&&mx[j]<=l)
					ans++;
			}
		}
		printf("%lld\n",ans);
	}
	else
	{
		for(int k=1;k<=q;k++)
		{
			cin>>qes[k].fr>>qes[k].to;
			if(qes[k].fr.length()!=qes[k].to.length())
			{
				printf("0\n");
				continue;
			}
			ll pos=-1,ans=0;
			for(int i=(ll)qes[k].to.length()-1;i>=0;i--)
				if(qes[k].to[i]!=qes[k].fr[i])
				{
					pos=i;
					break;
				}
			for(int i=1;i<=n;i++)
			{
				string tmpa="",tmpb="",tmpc="";
				for(int j=0;j<(ll)rep[i].fr.length();j++)
					tmpb+=qes[k].to[j], tmpc+=qes[k].fr[j];
//				cout<<tmpb<<" "<<tmpc<<" "<<pos-(ll)rep[i].fr.length()+1<<" "<<(ll)qes[k].to.length()-(ll)rep[i].fr.length()<<endl;
				for(ll j=0;j<=(ll)qes[k].to.length()-(ll)rep[i].fr.length();j++)
				{
					if(tmpa+rep[i].to==tmpb&&tmpa+rep[i].fr==tmpc&&j+(ll)rep[i].to.length()-1>=pos)
						ans++;
					tmpa+=qes[k].fr[j];
					tmpb+=qes[k].to[j+(ll)rep[i].fr.length()];
					tmpc+=qes[k].fr[j+(ll)rep[i].fr.length()];
//					cout<<tmpa<<" "<<tmpb<<" "<<tmpc<<endl;
				}
			}
			printf("%lld\n",ans);
		}
	}
}
