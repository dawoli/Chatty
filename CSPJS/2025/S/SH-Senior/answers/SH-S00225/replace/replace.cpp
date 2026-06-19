#include<bits/stdc++.h>
using namespace std;
pair<string,string> s[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		s[i].first=a,s[i].second=b;
//		cout<<s[i].first<<endl;
	}
	while(q--){
		int cnt=0;
		string st,to;
		cin>>st>>to;
		for(int i=1;i<=n;i++){
			int findst=st.find(s[i].first);
			if(findst!=string::npos){
				string x,y,z;
				x=st.substr(0,findst);
				y=st.substr(findst,s[i].first.size());
				z=st.substr(findst+s[i].first.size(),st.size()-(findst+s[i].first.size()-1));
//				cout<<x<<' '<<y<<' '<<z<<endl;
				y=s[i].second;
//				cout<<x<<' '<<y<<' '<<z<<endl;
				string newst=x+y+z;
//				cout<<"->"<<newst<<endl;
				if(newst==to)
					cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
