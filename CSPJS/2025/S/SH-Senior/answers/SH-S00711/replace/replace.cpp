#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=2e5+5;
int n,m;
string s[MAXN],t[MAXN],p[MAXN],q[MAXN];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    	cin>>p[i]>>q[i];
    for(int i=1;i<=m;++i)
    	cin>>s[i]>>t[i];
    if(m==1)
    {
    	int ans=0;
    	string l=s[1],o=t[1];
    	for(int i=1;i<=n;++i)
    	{
    		s[1]=l,t[1]=o;
    		bool flag=true;
    		int used=0;
    		while(s[1].find(p[i])<s[1].size())
    		{
    			bool st=true,ch=true;
    			int pos=s[1].find(p[i]);
    			for(int j=pos;j<pos+p[i].size();++j)
    			{
    				if(s[1][j]!=t[1][j])
    				    st=false;
    				if(q[i][j-pos]!=t[1][j])
    				    ch=false;
    				s[1][j]=t[1][j]='0';
				}
				if(!st&&!ch)
				{
					flag=false;
					break;
				}
				if(!st&&ch)
				    ++used;
				if(used>1)
				    break;
			}
			if(flag&&s[1]==t[1]&&used<=1)
			    ++ans;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(n<=1000&&m<=1000)
	{
		for(int i=1;i<=m;++i)
		{
			string l=s[i],o=t[i];
			int ans=0;
			for(int k=1;k<=n;++k)
			{
				s[i]=l,t[i]=o;
			    bool flag=true;
			    int used=0;
    		    while(s[i].find(p[k])<s[i].size())
    		    {
    			    bool st=true,ch=true;
    		    	int pos=s[i].find(p[k]);
    		    	for(int j=pos;j<pos+p[k].size();++j)
    		    	{
    		    		if(s[i][j]!=t[i][j])
    		    		    st=false;
    		    		if(q[k][j-pos]!=t[i][j])
    		    		    ch=false;
    		    		s[i][j]=t[i][j]='0';
			    	}
			     	if(!st&&!ch)
			    	{
			    		flag=false;
			    		break;
			    	}
			    	if(!st&&ch)
			    	    ++used;
			    	if(used>1)
			    	    break;
			    }
			    if(flag&&s[i]==t[i]&&used<=1)
			        ++ans;
		    }
		    cout<<ans<<endl;
		}
		return 0;
	}
	int B=0;
	for(int i=0;i<s[1].size();++i)
	{
	    if(s[1][i]!='a'&&s[1][i]!='b')
		{
		    B=0;
		    break;
		}
		if(s[1][i]=='b')
		    B++;
	}
	if(B==1)
	{
		int a[10000005];
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;++i)
		{
			int pos1=p[i].find('b'),pos2=q[i].find('b');
			a[pos2-pos1+500000]++;
		}
		for(int i=1;i<=m;++i)
		{
			int pos=s[i].find('b'),poss=t[i].find('b');
			cout<<a[poss-pos+500000]<<endl;
		}
		return 0;
	}
	for(int i=1;i<=m;++i)
	{
		string l=s[i],o=t[i];
		int ans=0;
		for(int k=1;k<=n;++k)
		{
			s[i]=l,t[i]=o;
		    bool flag=true;
		    int used=0;
   		    while(s[i].find(p[k])<s[i].size())
   		    {
   			    bool st=true,ch=true;
   		    	int pos=s[i].find(p[k]);
   		    	for(int j=pos;j<pos+p[k].size();++j)
   		    	{
   		    		if(s[i][j]!=t[i][j])
   		    		    st=false;
   		    		if(q[k][j-pos]!=t[i][j])
   		    		    ch=false;
   		    		s[i][j]=t[i][j]='0';
		    	}
		     	if(!st&&!ch)
		    	{
		    		flag=false;
		    		break;
		    	}
		    	if(!st&&ch)
		    	    ++used;
		    	if(used>1)
		    	    break;
		    }
		    if(flag&&s[i]==t[i]&&used<=1)
		        ++ans;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
