#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005],b[200005];
string q1,q2;
int ans=0;
int cl(int i)
{
	int cnt=0;
	bool fl=0;
	bool us=0;
	string fir="",s="",en="";
	for(int j=0;j<q1.size();j++)
	{
		if(us)
		{
			en+=q1[j];
		}
		else if(fl)
		{
//			cout<<j<<" "<<fir<<endl;
			if(cnt==a[i].size()-1)
			{
				us=1;
				en+=q1[j];
			}
			else if(q1[j]!=a[i][cnt+1])
			{
				fl=0;
				cnt=0;
				s+=q1[j];
				fir+=s;
				s="";
			}
			else
			{
				cnt++;
				s+=q1[j];
			}
		}
		else if(q1[j]==a[i][0])
		{
			fl=1;
			s+=q1[j];
		}
		else
		{
			fir+=q1[j];
		}
//		cout<<j<<" "<<fl<<" "<<us<<endl;
	}
//	cout<<fir<<" "<<b[i]<<" "<<en<<" ";
	if(!fl||fir+b[i]+en!=q2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>q1>>q2;
		for(int j=1;j<=n;j++)
		{
			ans+=cl(j);
//			cout<<j<<" "<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
