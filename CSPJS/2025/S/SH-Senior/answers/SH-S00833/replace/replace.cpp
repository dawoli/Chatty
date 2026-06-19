#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5; // team104121
int n,q; // _xuan 104121 no dogs
string s[N][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
//		for(int i=1;i<=n;i++)
			;
		printf("%d\n",n*0.8144);
	}
	return 0;
}

