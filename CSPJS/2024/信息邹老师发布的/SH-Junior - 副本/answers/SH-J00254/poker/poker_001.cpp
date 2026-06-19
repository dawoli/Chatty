#include<bits/stdc++.h>
using namespace std;
long long D[14],C[14],H[14],S[14];
inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void write(long long x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0'); 
}

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	long long n,ans=0;
	n=read();
	for(long long i=1;i<=n;i++)
	{
		char a;
		char b;
		cin>>a>>b;
		if(a=='D')
		{
			if(b=='A') D[1]=1;
			else if(b=='J') D[11]=1;
			else if(b=='Q') D[12]=1;
			else if(b=='K') D[13]=1;
			else if(b=='T') D[10]=1;
			else if(b=='2') D[2]=1;
			else if(b=='3') D[3]=1;
			else if(b=='4') D[4]=1;
			else if(b=='5') D[5]=1;
			else if(b=='6') D[6]=1;
			else if(b=='7') D[7]=1;
			else if(b=='8') D[8]=1;
			else if(b=='9') D[9]=1;
		}
		else if(a=='C')
		{
			if(b=='A') C[1]=1;
			else if(b=='J') C[11]=1;
			else if(b=='Q') C[12]=1;
			else if(b=='K') C[13]=1;
			else if(b=='T') C[10]=1;
			else if(b=='2') C[2]=1;
			else if(b=='3') C[3]=1;
			else if(b=='4') C[4]=1;
			else if(b=='5') C[5]=1;
			else if(b=='6') C[6]=1;
			else if(b=='7') C[7]=1;
			else if(b=='8') C[8]=1;
			else if(b=='9') C[9]=1;
		}
		else if(a=='H')
		{
			if(b=='A') H[1]=1;
			else if(b=='J') H[11]=1;
			else if(b=='Q') H[12]=1;
			else if(b=='K') H[13]=1;
			else if(b=='T') H[10]=1;
			else if(b=='2') H[2]=1;
			else if(b=='3') H[3]=1;
			else if(b=='4') H[4]=1;
			else if(b=='5') H[5]=1;
			else if(b=='6') H[6]=1;
			else if(b=='7') H[7]=1;
			else if(b=='8') H[8]=1;
			else if(b=='9') H[9]=1;
		}
		else if(a=='S')
		{
			if(b=='A') S[1]=1;
			else if(b=='J') S[11]=1;
			else if(b=='Q') S[12]=1;
			else if(b=='K') S[13]=1;
			else if(b=='T') S[10]=1;
			else if(b=='2') S[2]=1;
			else if(b=='3') S[3]=1;
			else if(b=='4') S[4]=1;
			else if(b=='5') S[5]=1;
			else if(b=='6') S[6]=1;
			else if(b=='7') S[7]=1;
			else if(b=='8') S[8]=1;
			else if(b=='9') S[9]=1;
		}
	}
	for(long long i=1;i<=13;i++)
	{
		if(S[i]==0) ans++;
		if(D[i]==0) ans++;
		if(C[i]==0) ans++;
		if(H[i]==0) ans++;
	}
	write(ans);
	return 0;
}
