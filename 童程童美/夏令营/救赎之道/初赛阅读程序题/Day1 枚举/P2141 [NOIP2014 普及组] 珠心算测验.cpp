#include<bits/stdc++.h>
using namespace std;
int a[105], n, ct;
bool hasSum(int k)
{
	for(int i = 1; i <= n-1; ++i)
		for(int j = i + 1; j <= n; ++j)
			if(a[k] == a[i] + a[j])
				return true;
	return false; 
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int k = 1; k <= n; ++k) 
		if(hasSum(k))
			ct++;
	cout << ct;
    return 0;
} 
