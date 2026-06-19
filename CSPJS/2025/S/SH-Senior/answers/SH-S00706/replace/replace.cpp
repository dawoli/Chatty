#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
string x[maxn],y[maxn];
int l,r,ans,n,q;
bool same[maxn];
int kmp[maxn];
void kmpp(string n1,string n2,int place,string k2)
{
	memset(kmp,0,sizeof(kmp));
	//cout<<n1<<" "<<n2<<endl;
	char a[maxn],b[maxn];
	int la,lb,j=0;
	for(int i=1;i<=n1.length();i++)
	{
		a[i]=n1[i-1]; 
	} 
	for(int i=1;i<=n2.length();i++)
	{
		b[i]=n2[i-1]; 
	} 
	la=n1.length();
	lb=n2.length();
	//cout<<la<<lb;
	for(int i=2;i<=lb;i++)
	{
		while(j&&b[i]!=b[j+1])j=kmp[j];
		if(b[i]==b[j+1])j++;
		kmp[i]=j;
		//cout<<"$";
	}
	j=0;
	//cout<<y[place]<<endl;
	for(int i=1;i<=la;i++)
	{
	//	cout<<j;
		while(j&&a[i]!=b[j+1])j=kmp[j];
		if(a[i]==b[j+1])j++;
		if(j==lb)
		{
			int w=i-lb+1;
			//cout<<w<<endl;
			if(w-1<=l&&w+y[place].length()-2>=r)
			{
				//cout<<"in"<<endl; 
				bool can=1;
				for(int v=0;v<y[place].length();v++)
				{
					if(y[place][v]!=k2[w-1+v])
					{
						can=0;
						break;
					}
				}
				if(can==1)
				{
					ans++;
				//	cout<<i<<"can"<<endl;
				}
			}
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		x[i]=a;
		y[i]=b;
	}
	for(int o=1;o<=q;o++)
	{
		memset(same,0,sizeof(same));
		string k1,k2;
		cin>>k1>>k2;
		if(k1.length()!=k2.length())
		{
			cout<<"0\n";
			continue;
		}
		l=-1,r=-1,ans=0;
		int ansmax=0;
		//cout<<k1<<endl<<k2<<endl;
		for(int i=0;i<k1.length();i++)
		{
			if(k1[i]==k2[i])
			{
				same[i]=1;
				if(l!=-1)r=i-1;	
			}
			else 
			{
				//cout<<i<<endl;
				if(l==-1)l=i;
				if(r!=-1)ansmax=1;
				same[i]=0;
			}
		}
		if(r==-1)r=k1.length()-1;
		//cout<<"%%%%%"<<l<<" "<<r<<endl;
		for(int i=1;i<=n;i++)
		{
			//cout<<i<<endl;
			kmpp(k1,x[i],i,k2);
		}
		if(ansmax==1)cout<<min(ansmax,ans)<<"\n";
		else cout<<ans<<"\n";
	}
	return 0;
}
