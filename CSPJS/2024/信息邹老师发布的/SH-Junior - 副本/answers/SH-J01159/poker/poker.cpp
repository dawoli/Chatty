#include<bits/stdc++.h>
using namespace std;
bool poker[13][4];
int a,b,n,ans;//a为花色编号，b为大小编号
void pan(char,char);
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char co,va;//co花色，va大小 
		cin>>co>>va;
		pan(co,va);
		poker[b][a]=true;
	}
	for(int i=0;i<13;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(!poker[i][j])
				ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
void pan(char c,char v)
{
	if(c=='D')
		a=0;
	if(c=='C')
		a=1;
	if(c=='H')
		a=2;
	if(c=='S')
		a=3;
	if(v=='A')
		b=0;
	if(v=='2')
		b=1;
	if(v=='3')
		b=2;
	if(v=='4')
		b=3;
	if(v=='5')
		b=4;
	if(v=='6')
		b=5;
	if(v=='7')
		b=6;
	if(v=='8')
		b=7;
	if(v=='9')
		b=8;
	if(v=='T')
		b=9;
	if(v=='J')
		b=10;
	if(v=='Q')
		b=11;
	if(v=='K')
		b=12;
	return ;
}
