#include<bits/stdc++.h>
using namespace std;
#define N 100005
long long n;
int attack_defense[N];
bool flag[N],flag1[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>attack_defense[i];
	}
	sort(attack_defense,attack_defense+n);
	for(int i=0;i<n;i++)
	{
		if(attack_defense[i]<attack_defense[i+1]&&flag1[i+1]!=1)
		{
			flag[i]=1;
			flag1[i+1]=1;
			attack_defense[i]=0;
		}
	}
	sort(attack_defense,attack_defense+n);
	for(int i=0;i<n;i++)
	{
		if(attack_defense[i]!=0)
		{
			if(attack_defense[i]<attack_defense[i+1]&&flag1[i+1]!=1)
			{
				flag[i]=1;
				flag1[i+1]=1;
				attack_defense[i]=0;
			}
		}
	}
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		if(flag[i]==0&&attack_defense[i]!=0)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
