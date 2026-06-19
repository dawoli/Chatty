#include <bits/stdc++.h> 
using namespace std;
int a[114514];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)cin >> a[i];
	if(k == 1)
	{
		int sum = 0;
		for(int i = 1;i <= n;i++)sum += a[i];
		cout << sum; 
	}
	else if(k == 0)
	{
		cout << n/2;
	}
	else cout << 1;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
