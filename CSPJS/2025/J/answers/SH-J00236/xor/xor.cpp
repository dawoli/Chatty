#include <bits/stdc++.h>
using namespace std;

int n,k,ant=0,cnt=0;
int a[500001];

struct lr{
	int l,r;
} b[7500000];
int xorr(int x,int y)
{
	short xa[21],ya[21];
	long long z=0,maxx=0;
	
	for(int i=0;i<=20;i++)
	{
		xa[i]=x%2;
		x/=2;
		if(i>maxx) maxx=i;
		if(x==0) break;
	}
	//for(int i=0;i<=maxx;i++) cout<<xa[i]<<' ';
	for(int i=0;i<=20;i++)
	{
		ya[i]=y%2;
		y/=2;
		if(i>maxx) maxx=i;
		if(y==0) break;
	}
	for(int j=0;j<=maxx;j++)
	{
		if(xa[j] + ya[j]!=1)
		{
			z+=pow(2,j);
		}
	} 
	return z;
}

void search(int bg,int rr,int t)
{
	if(t>cnt) cnt=t;
	for(int i=bg+1;i<=ant;i++)
	{
		if(b[i].l>rr){
			search(i,b[i].l,t+1);
		}
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
	}
	int t;
	for(int i=1;i<=n;i++)
	{
		t=a[i];
		if(t==k){
			ant++;
			b[ant].l=i;
			b[ant].r=i;
		}
		//cout<<t<<endl;
		for(int j=i+1;j<=n;j++)
		{
			int c=xorr(t,a[j]);
			t=c;
			if(t==k){
				ant++;
				b[ant].l=i;
				b[ant].r=j;
			}
			
			//cout<<xorr(t,a[j])<<' ';
		}
	}
	//cout<<xorr(xorr(1,0),3);
	//cout<<ant<<endl;
	for(int i=1;i<=ant;i++)
	{
		search(i,b[i].r,1);
	}
	cout<<cnt;
	return 0;
} 
