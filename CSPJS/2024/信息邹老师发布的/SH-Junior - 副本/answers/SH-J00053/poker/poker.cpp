# include <bits/stdc++.h>
using namespace std;
bool a['S']['Q'];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;cin >> n;
	string s;int cnt=0;
	for (int i=0;i<n;i++){
		cin >> s;
		int x=s[0],x2=s[1];
		if (a[x][x2]) cnt++;
		else a[x][x2]=1;
	}
	cout << 52-n+cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
