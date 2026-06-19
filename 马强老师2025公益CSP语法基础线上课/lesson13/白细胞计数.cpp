/*
  abs(a)   a==1   abs(1)==1   abs(x)：求x的绝对值
		   a==-1  abs(-1)==1   5-4==1  1-4==-3-->3    
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	double d[301]={};
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	double sum=0,ave=0,maxi=0;
	for(int i=1;i<=n;i++)
		sum+=d[i];
	ave=sum/n;
	cout<<fixed<<setprecision(2)<<ave<<' ';
	for(int i=1;i<=n;i++)
		if(abs(d[i]-ave)>maxi )
			maxi=abs(d[i]-ave);
	cout<<fixed<<setprecision(2)<<maxi<<endl;
	return 0;
}
