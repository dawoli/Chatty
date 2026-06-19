#include<bits/stdc++.h>
using namespace std;
struct s{
	int number;
	int stick;
}a[15]={{8,7},{0,6},{6,6},{9,6},{2,5},{3,5},{5,5},{4,4},{7,3},{1,2}};
int cmp(s a1,s b1)
{
	if(a1.stick==b1.stick)
		return a1.number<b1.number;
	return a1.stick>b1.stick;
}
int f(int n,int step){
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	
	int minn=INT_MAX;
	for(int i=0;i<10;i++)
	{	
		if(n<a[i].stick)
			continue;
		int n1=n-a[i].stick;
		int	f1=f(n1,step*10);
		if(n1<=1&&i==1)
		continue;
		minn=min(minn,int(f1+a[i].number*step));
	}
	return minn;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","r",stdout);
	int t,n;
	cin>>t;
	sort(a,a+10,cmp);
	for(int i=0;i<t;i++){
		cin>>n;
		if(n==1)
			cout<<-1;
		else
			cout<<f(n,1)<<endl;
	} 
	return 0;
}
