#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,sco;
}a[1005];
bool cmp(node a,node b){
	return a.sco>b.sco;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sco;
		a[i].num=i;
	}
	sort(a+1,a+1+(n*m),cmp);
	
	int p=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].num==1)
		{
			p=i;
		}
	}
	int h=0;
	if(p%n)
	{
		h=p/n+1;
	}
	else h=p/n;
	if(h%2==0)
	{
		cout<<h<<" ";
		if(p%n==0)cout<<1;
		else cout<<n+1-p%n;
	}else
	{
		cout<<h<<" ";
		if(p%n==0)cout<<n;
		else cout<<p%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

