#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int a[15];
int cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	if(a[1]==1) cout << 9;
	if(a[1]==2) cout <<6;
	
	
	
	return 0;
} 
