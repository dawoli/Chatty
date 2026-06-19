#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt = 52;
	char co,sc;
	cin>>n;
	while(n--){
		cin>>co>>sc;
		if(a[co][sc] == 0){
			cnt--;
			a[co][sc]++;
		}
	}
	cout<<cnt;
	return 0;
} 
