#include <bits/stdc++.h>
using namespace std;
int zs,n;.
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> zs;
	for(int i=1;i<=n;i++){
		cin >> n;
		if(n==1)cout << -1 << endl;
		else if(n%7==0){
			for(int i=1;i<=n/7;i++)cout << 8;
			cout << endl;
		}
		else if(n%7==0){
			int tmp=n/7;
			cout << 10;
			for(int i=1;i<=tmp-1;i++)cout << 8;
			cout << endl;
		}
	}
	return 0;
}
