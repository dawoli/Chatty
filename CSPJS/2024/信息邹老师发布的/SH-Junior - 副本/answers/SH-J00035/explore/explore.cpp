#include <bits/stdc++.h> 
using namespace std;

int a[1010][1010],t,n,m,k,x,y,d,cnt,detax,detay;
string s;


void f(int g){
	if(g==0){detax=0;detay=1;}
	if(g==1){detax=1;detay=0;}
	if(g==2){detax=0;detay=-1;}
	if(g==3){detax=-1;detay=0;}
}

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cin >> n >> m >> k >> x >> y >> d;
		for(int j = 1; j <= n; j++)
		{
			cin >> s;
			for(int j2 = 1; j2 <= m; j2++)
			{
				a[j][j2]=(s[j2-1]=='.');
			}
		}
		a[x][y]=2;
		cnt = 1;
		while(k>0)
		{
			f(d);
			while(!(x+detax >= 1 && x+detax <= n && y+detay >= 1 && y+detay <= m && a[x+detax][y+detay] != 0))
			{
				d++;
				f(d%4);
				k--;
				if(k <= 0) break;
			}
			if(k <= 0) break;
			if(a[x+detax][y+detay]==1)cnt++;
			a[x+detax][y+detay] = 2;
			x = x+detax;
			y = y+detay;
			k--;
			
		}
		
		cout << cnt << endl;
	} 

}
