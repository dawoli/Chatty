#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::sort;

int jzha[110],jzhxl,jzhn,jzhm,jzhxlpos,jzhxlr,jzhxlc;

bool jzhcomp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>jzhn>>jzhm;
	for(int i=1;i<=jzhn*jzhm;i++) cin>>jzha[i];
	jzhxl=jzha[1];
	sort(jzha+1,jzha+1+jzhn*jzhm,jzhcomp);
	for(int i=1;i<=jzhn*jzhm;i++) if(jzha[i]==jzhxl)
	{
		jzhxlpos=i;
		break;
	}
	///*dbg*/ cout<<jzhxlpos<<std::endl;
	jzhxlc=(jzhxlpos-1)/jzhn+1;
	if(jzhxlc%2==1)
	{
		jzhxlr=(jzhxlpos-1)%jzhn+1;
	}
	else
	{
		jzhxlr=jzhn-((jzhxlpos-1)%jzhn);
	}
	cout<<jzhxlc<<' '<<jzhxlr;
	return 0;
} 
