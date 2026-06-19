#include<bits/stdc++.h>
using namespace std;
const int N=2009;
struct two{
	string s1,s2;
};
two s[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	for(int i=1;i<=q;i++){
		string sa,sb;
		cin>>sa>>sb;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(sa==s[i].s1&&sb==s[i].s2){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
