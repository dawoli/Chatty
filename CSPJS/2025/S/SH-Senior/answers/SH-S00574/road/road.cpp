#include<bits/stdc++.h>
#define Code using
#define By namespace
#define CChara std
Code By CChara;
#define int long long
int n,m,k;
//不要管乡镇，直接求最小生成树！
struct side
{
	int begin;
	int end;//无向边，无序的
	int value; 
}arr[3145140]; 
bool cmp(side A,side B)
{
	return A.value<=B.value;
}
int father[10010];
int Find(int n)
{
	if(father[n]==n)
	{
		return n;
	}
	if(father[n]!=n)
	{
		father[n]=Find(father[n]);
	}
	return father[n];
}
void merge(int a,int b)
{
	int fathera=Find(a);
	int fatherb=Find(b);
	father[fatherb]=fathera;
	return;
}
signed main()
{
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//Please Check Before Handing In!!
	cin>>n>>m>>k;
	int i;
	for(i=1;i<=n+k;i++)
	{
		father[i]=i;
	}
	for(i=1;i<=m;i++)
	{
		cin>>arr[i].begin>>arr[i].end>>arr[i].value;
	}
	int gunmu=0; 
	for(int abcd=1;abcd<=k;abcd++)
	{
		cin>>gunmu;
		for(int j=1;j<=n;j++)
		{
			cin>>arr[i].value;
			arr[i].begin=j;
			arr[i].end=n+abcd;
			i++;
		}
	}
//	cout<<i<<endl;
	int tmp=i; 
	sort(arr+1,arr+tmp,cmp);
	int ans=0;
	for(i=1;i<=tmp;i++)
	{
//		cout<<arr[i].value<<endl;
		int begin=arr[i].begin;
		int end=arr[i].end;
		if(Find(begin)==Find(end))
		{
			continue;
		}
		else
		{
			ans+=arr[i].value;
			merge(begin,end);
		}
	}
	cout<<ans<<endl;
	return 0;
}

