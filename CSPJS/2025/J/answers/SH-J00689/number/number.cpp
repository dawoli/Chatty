#include<iostream>
#include<algorithm>
#define debug(x) (cerr<<#x<<':'<<(x)<<endl)
#define endl '\n'
using namespace std;
typedef long long ll;
ll cnt[128];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    char ch;
	while(cin>>ch) if(ch>='0'&&ch<='9') cnt[ch-'0']++;
    for(int j=9;j>=0;j--) for(int i=1;i<=cnt[j];i++) cout<<j;
	return 0;
}

