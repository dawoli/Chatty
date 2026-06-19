#include<bits/stdc++.h>
using namespace std;
int n,q;
string replace1[200009][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>replace1[i][0]>>replace1[i][1];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			int start=0;
			while(s1.find(replace1[i][0],start)!=string::npos){
				int index=s1.find(replace1[i][0],start);
				if(index==s2.find(replace1[i][1],start)){
					if(s1.substr(0,index)==s2.substr(0,index) && s1.substr(index+replace1[i][0].size())==s2.substr(index+replace1[i][0].size())){
						ans++;
					}else{
						break;
					}
				}
				start+=index;
				start+=replace1[i][0].size();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
