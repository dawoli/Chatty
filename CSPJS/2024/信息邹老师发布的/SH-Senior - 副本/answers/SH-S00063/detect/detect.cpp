#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,l,v;
int posl[101010],posr[101010],meter[101010];
vector<int>vec[101010];
bool in[101010];
bool cal(int x,int y)
{
	if(vec[y].size()<vec[x].size()) return 0;
	int i,j;
	for(i=0,j=0;i<vec[x].size()&&j<vec[y].size();i++,j++)
	{
		while(j<vec[y].size()&&vec[x][i]!=vec[y][j]) j++;
	}
	if(j>=vec[y].size()) return 0;
	return 1;
}
void solve()
{
	memset(posl,0,sizeof(posl));
	memset(posr,0,sizeof(posr));
	memset(in,0,sizeof(in));
	cin>>n>>m>>l>>v;
	for(int i=1;i<=n;i++)
	{
		int d,v,a;
		cin>>d>>v>>a;
		if(a==0||d==l)
		{
			if(v>3) posl[i]=d,posr[i]=l;
			else posl[i]=posr[i]=-1;
		}
		else
		{
			double pos=((9.0-v*v)*1.0)/(2.0*a);
			if(abs(pos-(int(pos)))<=1e-10) pos=(int(pos));
			if(abs(pos-(int(pos+1)))<=1e-10) pos=(int(pos+1));
			if(abs(pos-(int(pos-1)))<=1e-10) pos=(int(pos-1));
			pos+=d;
			if(a>0)
			{
				if(v>3) posl[i]=d,posr[i]=l;
				if(v==3) posl[i]=d+1,posr[i]=l;
				else
				{
					if(pos<l) posl[i]=ceil(pos+1e-10),posr[i]=l;
					else posl[i]=posr[i]=-1;
				}
			}
			else
			{
				if(v>3)
				{
					if(pos<=l) posl[i]=d,posr[i]=floor(pos-1e-10);
					else posl[i]=d,posr[i]=l;
				}
				else posl[i]=posr[i]=-1;
			}
		}
	}
	int ans1=0,ans2=0;
	for(int i=1;i<=m;i++)
	{
		cin>>meter[i];
		for(int j=1;j<=n;j++)
		{
			if(posl[j]<=meter[i]&&meter[i]<=posr[j])
			{
				in[j]=1;
				vec[i].push_back(j);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		bool flag=0;
		for(int j=1;j<=m;j++)
		{
			if(i==j) continue;
			if(cal(i,j)&&vec[i]!=vec[j])
			{
				flag=1;
				break;
			}
		}
		for(int j=1;j<i;j++)
		{
			if(vec[i]==vec[j])
			{
				flag=1;
				break;
			}
		}
		if(vec[i].empty()) flag=1;
		ans2+=flag;
//		if(flag) cout<<i<<" ";
	}
	for(int i=1;i<=n;i++) ans1+=in[i];
	cout<<ans1<<" "<<ans2<<endl;
	for(int i=1;i<=m;i++) vec[i].clear();
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--) solve();
	return 0;
}
