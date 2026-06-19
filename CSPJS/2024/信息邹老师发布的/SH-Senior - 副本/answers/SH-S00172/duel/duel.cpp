#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,cnt,cnty;
bool isGG=true;
int r[N];
bool live[N];//live[j] 0:j died 1:j alive 
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//------输入------// 
	cin>>n;cnt=n;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
		cnty+=r[i]-1;
		if(r[i]>=3)isGG=false;
	}
	if(isGG)
	{
		cout<<cnty;
		return 0;
	}
	//-----初始化-----//
	for(int i=1;i<=n;i++)live[i]=1;
	//------贪心------//
	stable_sort(r+1,r+n+1);
	int minn=1e9,minc=-1;
	for(int i=1;i<=n;i++)
	{
		if(live[i])
		{
			minn=1e9,minc=-1;
			for(int j=1;j<=n;j++)
			{
				if(live[j] && r[i]>r[j] && r[j]<minn)
					minn=r[j],minc=j;
			}
//			cout<<"i:"<<i<<" minc:"<<minc<<'\n';
			if(minc!=-1)
			{
				live[minc]=0;
				cnt--;
			} 
		}
	}
	cout<<cnt<<'\n';
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*
GG

   /--------\    /--------\
  /             /          
  |             |
  |       ===|  |       ===|
  |          |  |          |
   \--------/    \--------/ 
*/
