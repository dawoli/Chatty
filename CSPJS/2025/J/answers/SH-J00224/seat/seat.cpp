/***********
 * T2: 座位 seat 
 * 估分: 100
 * author: CB_X2_Jun (Luogu UID 1219707)
 * 到此一游 
 ***********/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,s[111],kc[15][15],k;
bool ccc(int a, int b)
{
	return a>b;
}
int main()
{
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(false);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++)cin >> s[i];
	k=s[1];
	sort(s+1,s+n*m+1,ccc);
	int idx=1;
	int lie=1,nh=1;
	while(true)
	{
		kc[lie][nh]=s[idx];
		if(s[idx]==k){cout << lie << " " << nh << endl;return 0;}
		if((lie/n+1)%2==1&&nh<n)nh++;
		else if((lie/n+1)%2==1&&nh==n)lie++;
		else if((lie/n+1)%2==0&&nh>1)nh--;
		else if((lie/n+1)%2==0&&nh==1)lie++;
		idx++; 
	}
	return 0;
}
