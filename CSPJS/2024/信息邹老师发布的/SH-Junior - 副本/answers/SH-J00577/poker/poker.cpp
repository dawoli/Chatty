#include <bits/stdc++.h>
using namespace std;
struct node
{
	int a,b;
}c[52];
bool cmp(node x,node y)
{
	if(x.a!=y.a) return x.a<y.a;
	else return x.b<y.b;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	char s,m; 
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> s >> m;
		if(s=='D') c[i].a=1;
		else if(s=='C') c[i].a=2;
		else if(s=='H') c[i].a=3;
		else c[i].a=4;
		if(m=='A') c[i].b=1;
		else if(m=='T') c[i].b=10;
		else if(m=='J') c[i].b=11;
		else if(m=='Q') c[i].b=12;
		else if(m=='K') c[i].b=13;
		else c[i].b=m-'0';
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if((c[i].b!=c[i+1].b&&c[i].a==c[i+1].a)||(c[i].a!=c[i+1].a)) cnt++;
	}
	cout << 52-cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
