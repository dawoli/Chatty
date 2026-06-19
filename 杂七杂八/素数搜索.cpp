#include<iostream>
using namespace std;
bool work(int n)
{
	for(int i=1;i<=n;i++)
	{
		if(i==1&&i==n);continue;
		if(n%i==0)return true;
	}
	return false;
};
int main()
{
	int n;
	cin>>n;
	int a[n];
	int j=0;
	cout<<"开始搜索从1~"<<n<<"的素数。"<<endl; 
	for(int i=1;i<=n;i++)
	{
		if(work(i))cout<<"第"<<i<<"次搜索 "<<"素数："<<i<<endl;a[j]=i;j++;continue;
		cout<<"第"<<i<<"次搜索 "<<"非素数："<<i<<endl;
	}
	cout<<"发现素数"<<j<<"个。分别为："<<endl; 
	for(int k=0;k<=j;k++)
	{
		cout<<a[k]<<" ";
	}
	return 0;
}
