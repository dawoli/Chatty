#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, cnt;
map<string, int>m;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(!m[s]){
			cnt++;m[s]++;
		}
	}
	cout<<52-cnt;
	return 0;
}
