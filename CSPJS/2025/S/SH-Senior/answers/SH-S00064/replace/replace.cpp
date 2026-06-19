#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

map<string,string> mp;
string s1[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		string s2;
		cin>>s1[i]>>s2;
		mp[s1[i]]=s2;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int l1=t1.length(),l2=t2.length();
		if(l1!=l2){
			cout<<"0\n";
		}
		else{
			int st,ed,ans=0;
			for(int i=0;i<l2;++i){
				if(t1[i]!=t2[i]){
					st=i;
					break;
				}
			}
			for(int i=l2-1;i>=0;--i){
				if(t1[i]!=t2[i]){
					ed=i;
					break;
				}
			}
			string error=t1.substr(st,ed-st+1);
			for(int i=1;i<=n;++i){
				if(t1.find(s1[i])<l1&&t1.find(s1[i])>=0){
					int ls1=s1[i].length();
					if(s1[i].find(error)<l1&&s1[i].find(error)>=0){
						string ts2=t2.substr(t1.find(s1[i]),ls1);
						if(ts2==mp[s1[i]]){
							ans++;
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
