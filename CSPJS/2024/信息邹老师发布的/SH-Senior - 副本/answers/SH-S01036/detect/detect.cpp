#include <bits/stdc++.h>
using namespace std;
int d[100000],v[100000],a[100000],p[100000];
int sum;
int use[100][100];
int main()
{
	int t,m,n,l,j=0,time[100],v1;
	int p[100],s[100];
	cin>>t;
	cin>>n>>m>>l>>v1;
	for(int f=0;f<n;f++)
		cin>>d[f]>>v[f]>>a[f];
	for(int f=0;f<n;f++)
		cin>>p[f];
//	for(int f=0;f<n;f++)
//		cout<<d[f]<<" "<<v[f]<<" "<<" "<<a[f]<<" "<<p[f]<<endl;
	for(int f=0;f<n;f++){
		if(v[f]>v1 && a[f]>=0)
			while(p[j]>d[f]){
				use[f][j]=1;//第f辆车的第j个点超速 
				j++;
			}
		else if(v[f]<=v1 && a[f]<=0)	break;
		else{
			time[f]=(3-v[f])/a[f];//t[f]为到达超速状态的时间 
			s[f]=d[f]+v[f]*time[f]+a[f]*pow(time[f],2);//s[f]为到达超速状态行驶的距离
			while(p[j]>s[f]){
				use[f][j]=1;//第f辆车的第j个点超速 
				j++;
				break;
			}
		}
	}
	for(int f=0;f<n;f++)
		for(int k=0;k<m;k++)
			if(use[f][k]==1){
				sum++;
				break;
			}
	for(int f=0;f<n;f++){
		for(int k=0;k<m;k++)
			cout<<use[f][k]<<" ";
		cout<<endl;
	}
	cout<<sum;
	return 0;	
}
//1
//5 5 15 3
//0 3 0
//12 4 0
//1 1 4
//5 5 -2
//6 4 -4
//2 5 8 9 15
