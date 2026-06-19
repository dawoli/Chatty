#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
int oth[22]={-1,1,7,4,2,6,8,10,18,22,28,68,88,100,108,188,200,208,288,688};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		ans.clear();
		int n;
		cin>>n;
		if(n<=20)
		{
			cout<<oth[n-1]<<endl;
			continue;
		}
		if(n%7==0)
		{
			for(int i=1;i<=n/7;i++)
			{
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		if(n%7==1)
		{
			cout<<"10";
			for(int i=1;i<=n/7-1;i++)
			{
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		int k=n;
		int cnt=0; 
		int sum=0;
		while(k)
		{
			if(cnt==0)
			{
				k-=7;
				cnt++;
				ans.push_back(8);
			}
			else
			{
				if(k>=6)
				{
					k-=6;
					ans.push_back(0);
				}
				else if(k==5)
				{
					k-=5;
					ans.push_back(2);
				}
				else if(k==4)
				{
					k-=4;
					ans.push_back(4);
				}
				else if(k==3)
				{
					k-=3;
					ans.push_back(7);
				}
				else if(k==2)
				{
					k-=2;
					ans.push_back(1);
				}
				else
				{
					ans.clear();
					break;
				}
			}
		}
		sort(ans.begin(),ans.end());
		if(ans.size()==0)
		{
			cout<<"-1";
			continue;
		}
		int fir=0;
		for(int i=0;i<ans.size();i++)
		{
			int j=1;
			while(fir==0&&ans[i]==0)
			{
				swap(ans[i],ans[i+j]);
				j++;
				if(ans[j]!=0)
				{
					fir=1;
				}
				else
				{
					swap(ans[i],ans[i+j]);
				}
			}
			cout<<ans[i];
		}
		cout<<endl;
	}
}
