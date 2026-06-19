#include <bits/stdc++.h>
using namespace std;

map <string,bool> x;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	scanf("%d",&n);
	
	for(int i = 1;i <= n;i++){
		string a;
		cin >> a;
		x[a] = 1;
	}
	
	int sum = 52;
	int cnt = 0;
	for(auto it:x){
		cnt++;
	}
	cout << sum-cnt << endl;
	return 0;
}
