#include <bits/stdc++.h>
using namespace std;
int n,m,ans=1,cnt;
char c[505];
bool a[505];
int s[505];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>c;
	for(int i=0;i<strlen(c);i++){
		a[i]=(c[i]-'0'==1);
		cnt++;
		ans*=cnt;
	}
	for(int i=1;i<=n;i++) cin>>s[i];
	cout<<ans;
	return 0;
} 
