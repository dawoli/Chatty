#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int T=0,a[maxn],n;
vector<int> s[maxn];
bool check(int cur,int line)
{
	if(cur==0) return 0;
	int w=n-1-cur;
	line=line>>w;
	//cout<<"hanshu";
	//cout<<cur<<" "<<line<<endl;
	//system("pause");
	int length=cur,f=line&1;
	while(length>0)
	{
		length--;
		line=line>>1;
	//	cout<<"line"<<line<<endl<<"len"<<length<<endl<<f<<endl;
		if(line%2==f) 
		{
			if(a[length]==a[cur]) return 1;
			else return 0;
		}
	}
	return 0;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--) 
	{
		int f=0,mx=0;
		
		memset(a,0,sizeof a);
		n=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			//mx=max(mx,a[i]);
			//s[a[i]].push_back(i);
		}/*
		for(int i=0;i<=mx;i++)
		{
			if(s[i].size()>1)
			{
				f=1;
				break;
			} 
		}
		if(f==0)
		{
			cout<<0<<endl;
			break; 
		}*/
		//cout<<1<<endl;
		for(int i=0;i<=1<<n-1;i++)
		{
			int ans=0;
			for(int j=n-1;j>=0;j--)
			{
				if(check(j,i))
				{
					//cout<<j<<" "<<i<<endl;
					ans+=a[j];
	//				cout<<"本次+了"<<a[j]<<"的"<<ans<<endl;
				}
			}
	//		cout<<i<<"的ans"<<ans<<endl;
			mx=max(mx,ans);
		}
		cout<<mx<<endl;
	}
	return 0;	
} 
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 0
5 5 0
6 4 0
2 5 8 9 15
*/
