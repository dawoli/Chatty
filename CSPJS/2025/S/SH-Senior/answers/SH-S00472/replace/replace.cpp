#include<bits/stdc++.h>
#define mkp make_pair
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn= 1 ;

struct node{
	int nxt[27];
	int to[27];
};

int n,q;
node trie[(int)2e6+9]; //特地开大空间 
int nS=1;

void put1()
{
	string s1,s2;
	cin>>s1>>s2;
	
	int i=0;
	int cur=1;
	for(;i<s1.length();++i) //走trie 
	{
		if(trie[cur].nxt[s1[i]-'a']==0)
			trie[cur].nxt[s1[i]-'a']=++nS; //开辟 
		
		cur=trie[cur].nxt[s1[i]-'a'];
		if(trie[cur].to[s2[i]-'a']==0) 
			trie[cur].to[s2[i]-'a']= -1 ; //-1表示可以走 但不是end 
	}
	--i;
	if(trie[cur].to[s2[i]-'a']==-1) 
		trie[cur].to[s2[i]-'a']=1;
	else
		++trie[cur].to[s2[i]-'a'] ;
}

void query1()
{
	
	string t1,t2;
	cin>>t1>>t2;
	if(t1.length()!=t2.length())
	{
		cout<<"0"<<endl;
		return ;
	}
	
	int pre=0;//不一样的第一位
	while(t1[pre]==t2[pre]) ++pre;
	int lst=t1.length()-1; //不一样的最后一位 
	while(t1[lst]==t2[lst]) --lst;
	 
	ll ans=0; //////////////////////////////////////
	int cur=1;
	
	for(int l=0;l<=pre;++l)
	{
		cur=1;
		for(int i=l;i<t1.length();++i) //走trie 
		{
			if(trie[cur].nxt[t1[i]-'a']==0) //下面没有路了 
			{
				break;
			}
			
			cur=trie[cur].nxt[t1[i]-'a'];
			
			//cout<<"i="<<i<<" now="<<t1[i]-'a'<<" to="<<trie[cur].to[t2[i]-'a']<<endl;
			
			if(trie[cur].to[t2[i]-'a']==0) //没得替换
			{
				break;
			} 
			else if(i>=lst && trie[cur].to[t2[i]-'a']!=-1) //换到了第i位 i>=lst 则t1 t2后面都一样 
			{
				ans+=trie[cur].to[t2[i]-'a'];
			}
		}
	}
	
	cout<<ans<<endl;
}

void solve()
{
	for(int i=1;i<=n;++i)
	{
		put1();
	}
	for(int i=1;i<=q;++i)
	{
		query1();
	}
	return ;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	solve();
	
	return 0;
}

