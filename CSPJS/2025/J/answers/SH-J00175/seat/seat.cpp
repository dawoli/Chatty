#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int c,r;
	int reco,tmp,numbe=0;
	int a[200];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]); 
	}
	reco=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i;j<=n*m;j++)
		{
			if(a[i]<a[j])
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;	
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i] == reco){
			numbe = i;
		}
	}
	int ans_line=numbe%n;
	int ans_straight=(numbe-ans_line)/n;
	if(ans_straight%2 != 0 && ans_line!=0)
	{
		c=ans_straight+1;
		r=n-ans_line+1;
	}
	else if(ans_straight%2!=0 && ans_line==0){
		c=ans_straight;
		r=n;
	}
	else if(ans_straight%2==0 && ans_line!=0)
	{
		c=ans_straight+1;
		r=ans_line;
	}
	else if(ans_straight%2==0 && ans_line!=0){
		c=ans_straight;
		r=1;
	}
	printf("%d%d",c,r);
	return 0;
}
