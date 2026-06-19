#include <fstream>
#include <map>
using namespace std;

ifstream fin("color.in");
ofstream fout("color.out");

int dfs(int a[],int n,int x=1)
{
	if(x>=n)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]*a[j]>0)
				{
					if(a[i]==a[j])
					{
						ans=ans+abs(a[i]);
					}
					break; 
				}
			}
		}
		return ans;
	}
	int ans = dfs(a,n,x+1);
	a[x]=-a[x];
	return max(ans,dfs(a,n,x+1));
}

void solve()
{
	int n;
	fin>>n;
	if(n<=20)
	{
		int a[50];
		for(int i=1;i<=n;i++)
		{
			fin>>a[i]; 
		}
		fout<<dfs(a,n)<<endl;
	}
}

int main()
{
	int T;
	fin>>T;
	for(int i=1; i<=T; i++)
	{
		solve();
	}
}
