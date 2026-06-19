#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD=998244353;
int n,m,a[505],ans;
bool used[15];
string s;
void dfs(int pos,int num){
	if(pos>n)
	{
		if(num>=m)
		    ++ans;
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(!used[i]&&a[i]>pos-num-1&&s[pos-1]=='1')
		{
			used[i]=true;
		    dfs(pos+1,num+1);
		    used[i]=false;
		}
		else if(!used[i])
		{
		    used[i]=true;
		    dfs(pos+1,num);
		    used[i]=false;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    bool A=true;
    for(int i=0;i<s.size();++i)
        if(s[i]=='1')
        {
            A=false;
            break;
		}
	if(A)
	{
		int ret=1;
		for(int i=1;i<=n;++i)
		    ret=(ret*i)%MOD;
		cout<<ret<<endl;
		return 0;
	}
    if(m==n)
    {
    	for(int i=0;i<s.size();++i)
    		if(s[i]=='0')
    		{
    			cout<<"0";
    			return 0;
			}
		int ret=1;
		for(int i=1;i<=n;++i)
		    ret=(ret*i)%MOD;
		cout<<ret<<endl;
		return 0;
	}
	if(n<=10)
	{
		dfs(1,0);
		cout<<ans%MOD;
		return 0;
	}
	if(m==1)
	{
		int len=0,num=0;
		for(int i=0;i<s.size();++i)
		{
			if(s[i]=='1')
			    break;
			len++;
		}
		for(int i=1;i<=n;++i)
		    if(a[i]>len)
		    	++num;
		if(num==0)
		{
			cout<<0<<endl;
			return 0;
		}
		if(num>len)
		{
			int ret=1;
		    for(int i=1;i<=n;++i)
		        ret=(ret*i)%MOD;
		    cout<<ret<<endl;
		    return 0;
		}
		int all=1,k=1,z=1,y=1,w=1;
		for(int i=1;i<=n;++i)
		    all=(all*i)%MOD;
		for(int i=1;i<=num;++i)
		    k=(k*i)%MOD;
		for(int i=1;i<=len-num;++i)
		    z=z*(n-num+1-i)/i;
		for(int i=1;i<=num;++i)
		    y=y*(len+1-i)/i;
		for(int i=1;i<=n-len;++i)
		    w=(w*i)%MOD;
		k=(((((k*z)%MOD)*y)%MOD)*w)%MOD;
		cout<<((all-k)%MOD+MOD)%MOD;
		return 0;
	}
	cout<<114514<<endl;
	return 0;
}
