#include<iostream>
using namespace std;
using i64=long long;
const int N=505,MOD=998244353;
int n,m;
bool s[N];
int c[N];
i64 S[N];
void init()
{
	S[1]=1;
	for (int i=2;i<N;i++)
	{
		S[i]=S[i-1]*i%MOD;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	cin>>n>>m;
	bool flag=1;
	for (int i=1;i<=n;i++)
	{
		char tmp;
		cin>>tmp;
		if (tmp=='0')	flag=0;
		s[i]=tmp-'0';
	}
	int num=0;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
		if (c[i])	num++;
	}
	cout<<num<<"\n";
	if (flag)       //ÌØÊâÐÔÖÊA 
	{
		cout<<S[num]<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

