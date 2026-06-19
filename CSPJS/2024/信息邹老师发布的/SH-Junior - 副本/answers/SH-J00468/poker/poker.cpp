#include <iostream>
#include <conio.h>
using namespace std;
int b[60],f[1000],n,ans=52;
string a[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i][0]=='D')b[i]+=100;
		else if(a[i][0]=='C')b[i]+=200;
		else if(a[i][0]=='H')b[i]+=300;
		else if(a[i][0]=='S')b[i]+=400;
		if(a[i][1]=='A')b[i]+=1;
		else if(a[i][1]=='2')b[i]+=2;
		else if(a[i][1]=='3')b[i]+=3;
		else if(a[i][1]=='4')b[i]+=4;
		else if(a[i][1]=='5')b[i]+=5;
		else if(a[i][1]=='6')b[i]+=6;
		else if(a[i][1]=='7')b[i]+=7;
		else if(a[i][1]=='8')b[i]+=8;
		else if(a[i][1]=='9')b[i]+=9;
		else if(a[i][1]=='T')b[i]+=10;
		else if(a[i][1]=='J')b[i]+=11;
		else if(a[i][1]=='Q')b[i]+=12;
		else if(a[i][1]=='K')b[i]+=13;
		if(f[b[i]]==0)
		{
			f[b[i]]=1;
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
