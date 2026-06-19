#include<bits/stdc++.h>
using namespace std;
int n;
map<string,int> mp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int cnt=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		string s;
		cin >> s;
		if(mp[s]!=1){
			cnt++;
		}
		mp[s]=1;
	}
	cout << 52-cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
