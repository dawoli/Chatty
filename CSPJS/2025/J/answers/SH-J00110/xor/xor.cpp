#include<iostream>
using namespace std;
int a[500010];
int n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>k;
	int cnt1=0;
	int cnt2=0;
	int cnt3=0;
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1&&a[i-1]!=1)
		{
			cnt1++;
		}
		else if(a[i]==1&&a[i-1]==1&&flag==false)
		{
			cnt1++;
			cnt3++;
			flag=true;
		}
		else if(a[i]==1&&a[i-1]==1&&flag==true)
		{
			cnt1++;
			flag=false;
		}
		else if(a[i]==0)
		{
			cnt2++;
		}
	}
	if(k==0)
	{
		cout<<cnt2+cnt3<<endl;
	}
	if(k==1)
	{
		cout<<cnt1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
