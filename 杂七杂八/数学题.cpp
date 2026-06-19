//算式105*110*115*120……*490*495*500的积的末尾有几个0 
#include<bits/stdc++.h>
using namespace std;
int c2(int a)
{
    int cnt=0;
	while(a%2==0)
	{
	    cnt++;
		a/=2;	
	}	
	return cnt;
} 
int c5(int a)
{
    int cnt=0;
	while(a%5==0)
	{
	    cnt++;
		a/=5;	
	}	
	return cnt;
} 
int main()
{
	int cnt2=0,cnt5=0,sum2[501]={},sum5[501]={},add2[50]={},add5[50]={};
	for(int i=105;i<=500;i+=5)
	{
		cnt2+=c2(i);
		cnt5+=c5(i);
		sum2[i]=c2(i);
		sum5[i]=c5(i);
		for(int j=0;j<=c2(i);j++)add2[j]++;
		for(int j=0;j<=c5(i);j++)add5[j]++;
		cout<<i<<"有"<<c2(i)<<"个2，"<<c5(i)<<"个5"<<endl;
	}
	for(int i=1;;i++)
	{
	    if(add2[i]==0)break;
		cout<<"有"<<i<<"个2的数有"<<add2[i]<<"个，它们分别是：";
		for(int j=105;j<=500;j+=5)
		{
			if(sum2[j]>=i)cout<<j<<"，";	
		}	
		cout<<endl;
	} 
	for(int i=1;;i++)
	{
	    if(add5[i]==0)break;
		cout<<"有"<<i<<"个5的数有"<<add5[i]<<"个，它们分别是：";
		for(int j=105;j<=500;j+=5)
		{
			if(sum5[j]>=i)cout<<j<<"，";	
		}	
		cout<<endl;
	} 	
	cout<<"总共有"<<cnt2<<"个2，" <<cnt5<<"个5，";
	int ans=min(cnt2,cnt5);
	cout<<"积的末尾有"<<ans<<"个0";
	return 0; 
}
