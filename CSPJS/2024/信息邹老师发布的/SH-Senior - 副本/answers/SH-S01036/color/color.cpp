#include <bits/stdc++.h>
using namespace std;
int color[100000];//0ºì 1À¶
int a[100000],c[100000]; 
int main()
{
	int t,m,n,sum[100];
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++)
			cin>>a[j];
		for(int j=1;j<=n;j++)
			for(int k=j;k<=n;k++){
				if(a[j]==a[k])	
					color[j]=!color[j-1];
					color[k]=color[j];
			}
		for(int k=0;i<n;k++) 
			for(int j=k-1;j>0;j--)
				if(a[k]==a[j] && color[k]==color[j])
					c[k]=a[k];
				else
					c[k]=0;
		for(int k=0;k<n;k++)
			sum[i]+=c[k];
	}
	for(int i=0;i<t;i++)
		cout<<sum[i]<<endl;
	return 0;
}
//3
//3
//1 2 1
//4
//1 2 3 4
//8
//3 5 2 5 1 2 1 4
