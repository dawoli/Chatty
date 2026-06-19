#include<iostream>
#include<map>
using namespace std;
int n,q,ans=0;
string t1,t2;
string s1[5000001],s2[5000001];
int main(void){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t1>>t2;
		for(int i=0;i<t1.size();++i){
			for(int len=1;i+len-1<t1.size();++len){
				string f=t1.substr(i,len);
				for(int j=1;j<=n;++j){
					if(f==s1[j]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
