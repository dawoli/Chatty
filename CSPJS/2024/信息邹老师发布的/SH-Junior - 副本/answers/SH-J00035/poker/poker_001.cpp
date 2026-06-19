#include <bits/stdc++.h> 
using namespace std;

string a[100];
int n,cnt;

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	cnt = 52-n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		for(int j = 1; j <= i-1; j++)
		{
			if(a[i]==a[j]){
				
				cnt++;
				break;
			}
		}
	} 
	cout << cnt;
}
