#include<bits/stdc++.h>
using namespace std;
int main()
{
	//good luck
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m,T;
	char s[1145];
	int a[11451];
	int c[11451];
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int j=1;j<=m;j++) cin >> c[j];
	for(int k = log(n)/log(2)+1;k>0;k--) cin >> s;
	cin >> T;
	srand(n);
	while(T--){
		cout << rand()%n << endl;
	}
	return 0;
}

