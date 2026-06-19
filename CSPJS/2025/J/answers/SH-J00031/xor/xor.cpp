#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N],n,k,cnt,bnd;
bool p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n; i++)
	{
		cin >> a[i];
		if(a[i]!=1)p = 1;
	}
	if(k == 0 && p == 0)
	{
		cout << n/2;
	}else if(k == 1 && p != 0){
		for(int i = 2;i <= n; i+=2)
		{
			if(a[i] == '0' && a[i-1] == '1')cnt++;
			else if(a[i] == '1'&& a[i-1] == '0')cnt++; 
		}
		cout << cnt;
	}
	else if(k == 0 && p != 0)
	{
		for(int i = 1;i <= n; i++)
		{
			if(a[i] == '0')bnd++;
		}
		cout << bnd;
	}

   return 0;
}

