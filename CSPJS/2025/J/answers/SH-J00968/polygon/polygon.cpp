#include<bits/stdc++.h>
using namespace std;
int n;
int l[5001];
bool lan[5001];
set<vector<int>>pract;
int ans=0;
bool poly(bool used[5001],int con,int snum)
{
	if(snum<3)return false;
	int Max=0,Sum=0;
	for(int i=1; i<=con; i++)
	{
		if(used[i])
		{
			Sum+=l[i];
			if(l[i]>Max)Max=l[i];
		}
	}
	return Sum>2*Max;
}
void use(bool used[5001],int con,int snum)
{
	if(poly(used,con,snum))
	{
		vector<int>temp(snum+1,0);
		int cnt=1;
		for(int i=1; i<=con; i++)
		{
			if(used[i])
			{
				temp[cnt]=l[i];
				cnt++;
			}
			if(cnt==snum)break;
		}
		/*for(int opa=1;opa<=snum;opa++)
		{
			cout<<temp[opa]<<" ";
		}
		cout<<endl;*/
		pract.insert(temp);
	}
	if(con>=n)return;

	bool used1[5001];
	for(int i=1; i<=con; i++)used1[i]=used[i];
	for(int i=0; i<=1; i++)
	{
		used1[con+1]=i;
		use(used1,con+1,snum+i);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>l[i];
	}
	sort(l+1,l+n);
	use(lan,0,0);
	cout<<(pract.size()+1)%998244353<<endl;
}
