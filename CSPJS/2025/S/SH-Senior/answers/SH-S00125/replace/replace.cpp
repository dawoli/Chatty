#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string> m;
int q,n,ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string a,b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		m[a]=b;
	}
	while(q--){
		cin>>a>>b;
		int f=a.size();
		for(auto t:m){
			string s=t.first,a1=a;
			int now=0;
			int k=a.find(s);
			while(k<=f)
			{
				a1=a;			
				a1.erase(k,s.size());
				a1.insert(k,t.second);
				//cout<<a1<<endl;
				if(a1==b) ans++;
				now=k+1;
				k=a.find(s,now);
			}
		}
	}
	cout<<ans;
}
