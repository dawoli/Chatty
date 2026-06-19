#include<bits/stdc++.h>
using namespace std;
map<pair<string,string>,int>s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s[{s1,s2}]++;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) cout<<0<<endl;
		else{
			int pos1,pos2;
			for(int j=0;j<t1.size();j++){
				if(t1[j]!=t2[j]){
					pos1=j;
					break;
				}
			}
			for(int j=t1.size()-1;j>=0;j--){
				if(t1[j]!=t2[j]){
					pos2=j;
					break;
				}
			}
			int cnt=0;
			for(int j=0;j<=pos1;j++){
				for(int z=pos2;z<t1.size();z++){
					string t3=t1.substr(j,z-j+1);
					string t4=t2.substr(j,z-j+1);
					cnt+=s[{t3,t4}];
				}
			}
			cout<<cnt<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
