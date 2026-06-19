#include<bits/stdc++.h>
using namespace std;
vector<int> v;
map<string,string> mp;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
		v.push_back(s1.size());
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());

	for(int i=1;i<=q;i++){
		int j=1,cnt=0;
		string t1,t2;
		cin>>t1>>t2;
		t1=" "+t1;
		for(auto len:v){
			int m=t1.size();
			string t_=t1;
			for(int l=1;l+len-1<m;l++){
				int r=l+len-1;
				string str="";
				for(int k=l;k<=r;k++){
					str+=t1[k];
				}
				if(mp[str]!="") {
					str=mp[str];
					for(int k=l;k<=r;k++){
						t1[k]=str[k-l];
					}
				}
				if(t1==" "+t2) cnt++;	
				t1=t_;	
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
