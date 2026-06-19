#include<bits/stdc++.h>
#include<string>
using namespace std;
int arr[100000]={0};
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	int k=0;
	for(unsigned int i=0;i<str.length();i++)
	{
		if(str[i]>=48&&str[i]<=57)
		{
			arr[k]=(int)str[i]-48;
			k++;
		}
	}
	sort(arr,arr+k,cmp);
	int ans=0;
	for(int i=0;i<k;i++)
	{
		ans+=arr[i]*pow(10,i);
	}
	cout<<ans;
	return 0;
}
