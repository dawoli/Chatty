#include <bits/stdc++.h>
using namespace std;
int a;
char x1[53],x2[53];
bool D[14],C[14],H[14],S[14];
int cnt=0;
void abc(char a,char b)
{
	if(a=='D')
	{
		if(b=='A'){
			D[1]=false;return ;
		}
		if(b=='T'){
			D[10]=false;return ;
		}
		if(b=='J'){
			D[11]=false;return ;
		}
		if(b=='Q'){
			D[12]=false;return ;
		}
		if(b=='K'){
			D[13]=false;return ;
		}
		D[int(b)-48]=false;return ;
	}
	if(a=='C')
	{
		if(b=='A'){
			C[1]=false;return ;
		}
		if(b=='T'){
			C[10]=false;return ;
		}
		if(b=='J'){
			C[11]=false;return ;
		}
		if(b=='Q'){
			C[12]=false;return ;
		}
		if(b=='K'){
			C[13]=false;return ;
		}
		C[int(b)-48]=false;return ;
	}
	if(a=='H')
	{
		if(b=='A'){
			H[1]=false;return ;
		}
		if(b=='T'){
			H[10]=false;return ;
		}
		if(b=='J'){
			H[11]=false;return ;
		}
		if(b=='Q'){
			H[12]=false;return ;
		}
		if(b=='K'){
			H[13]=false;return ;
		}
		H[int(b)-48]=false;return ;
	}
	if(a=='S')
	{
		if(b=='A'){
			S[1]=false;return ;
		}
		if(b=='T'){
			S[10]=false;return ;
		}
		if(b=='J'){
			S[11]=false;return ;
		}
		if(b=='Q'){
			S[12]=false;return ;
		}
		if(b=='K'){
			S[13]=false;return ;
		}
		S[int(b)-48]=false;return ;
	}
	return ;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	for(int i=1;i<=13;i++)
	{
		D[i]=true;C[i]=true;H[i]=true;S[i]=true;
	}
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%c%c",&x1[i],&x2[i]);
		abc(x1[i],x2[i]);
	}
	for(int i=1;i<=13;i++)
	{
		if(D[i]) cnt++;
		if(C[i]) cnt++;
		if(H[i]) cnt++;
		if(S[i]) cnt++;
	}
	printf("%d",cnt);
	return 0; 
}
