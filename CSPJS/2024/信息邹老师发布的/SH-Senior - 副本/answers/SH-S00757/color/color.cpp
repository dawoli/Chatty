#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("colour.in","r",stdin);
	freopen("colour.out","w",stdout);
	
	int T,max=0,ans=0;
	cin>>T;
	int answer[T];
	
	for(int x=0;x<T;x++)
	{
		max=0;
		ans = 0;
		int n;
		cin>>n;
		int A[n];
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		}
		int C[n];
		int colour[n];
		int cnt[n];
		
		for(int i=0;i<n;i++)
		{
			C[i] = 0;
		}
		
		for(int i=0;i<n;i++)
		{
			int a = 0;
			for(int p=0;p<2;p++)
			{
				ans = 0;
				for(int i=0;i<n;i++)
				{
					colour[i] = p;
				}
				for(int i=i+1;i<n;i++)
				{
					for(int k=i-1;k>=0;k--)
					{
						if(colour[i] == colour[k]&&A[i] == A[k])
						{
							C[i] = A[i];
							break;
						}
						else
						{
							C[i] = 0;
						}
					}
				}
				for(int i=0;i<n;i++)
				{
					ans = ans + C[i];
				}
				a = ans;
			}
			cnt[i] = a;
		}
		
		for(int i=0;i<n;i++)
		{
			if(cnt[i]>max)
			{
				max = cnt[i];
			}
		}
		answer[x] = max;
	}
	
	for(int i=0;i<T;i++)
	{
		cout<<answer[i]<<endl;
	}
	
	return 0;
}
