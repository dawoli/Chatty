#include<bits/stdc++.h>
#define ll long long
using namespace std;
set<string> a;
ll n; 
string now;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	while(n--){
		cin >> now;
		a.insert(now);
	}
	if (a.size()>52){
		cout << 0;
	}
	else cout << 52-a.size();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
