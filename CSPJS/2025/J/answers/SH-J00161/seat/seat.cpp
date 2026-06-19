#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int AGn=0,AGm=0;
	cin>>AGn>>AGm;
	int AGnumb=AGn*AGm;
	int AGa[AGnumb+1]={0};
	for(int AGi=0;AGi<AGnumb;AGi++)
	{
		cin>>AGa[AGi];
	}
	int AGr=AGa[0];
	for(int AGi=0;AGi<=AGnumb;AGi++)
	{
		for(int AGj=1;AGj<AGnumb;AGj++)
		{
			if(AGa[AGj-1]<AGa[AGj])
			{
				swap(AGa[AGj-1],AGa[AGj]);
			}
		}
	}
	int AGmb=0;
	for(int AGi=0;AGi<AGnumb;AGi++)
	{
		if(AGa[AGi]==AGr)
		{
			AGmb=AGi+1;
		}
	}
	int AGman[AGn][AGm];
	int AGnoww=1;
	int AGroww=1;
	int AGikun=1;
	for(int AGi=0;AGi<AGn;AGi++)
	{
		for(int AGj=0;AGj<AGm;AGj++)
		{
			AGman[AGi][AGj]=0;
		}
	}
	int AGfx=0;
	int AGnu=1;
	for(int AGi=0;AGi<=AGnumb+AGm/2;AGi++)
	{
		AGman[AGnoww-1][AGroww-1]=(AGroww-1)*AGn+AGnu;
		if(AGfx==0)
		{
			if(AGnoww+1<=AGn)
			{
				AGnoww++;
				AGnu++;
			}
			else
			{
				AGnoww=AGn;
				AGroww++;
				AGfx=1;
				AGnu=1;
			}
		}
		
		else if(AGfx==1)
		{
			if(AGnoww-1>=0)
			{
				AGnoww--;
				AGnu++;
			}
			else
			{
				AGnoww=1;
				AGroww++;
				AGfx=0;
				AGnu=1;
			}
		}
	}
	for(int AGi=0;AGi<AGn;AGi++)
	{
		for(int AGj=0;AGj<AGm;AGj++)
		{
			if(AGman[AGi][AGj]==AGmb)
			{
				cout<<AGj+1<<" "<<AGi+1;
				return 0;
			}
		}
	}
	return 0;
} 
