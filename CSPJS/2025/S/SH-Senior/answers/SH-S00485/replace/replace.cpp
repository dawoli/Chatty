#include<iostream>
#include<cstring>
using namespace std;
string subs(string s,int st,int ed){
	if(ed>s.size())return "";
	string r="";
	for(int i=st;i<ed;i++)r+=s[i];
	return r;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int r,q;
	cin>>r>>q;
	pair<string,string> dic[r];
	for(int i=0;i<r;i++)cin>>dic[i].first>>dic[i].second;
	string src,tgt;
	int cnt;
	while(q--){
		cin>>src>>tgt;
		cnt=0;
		for(int i=0;i<r;i++){
			for(int j=0;j<src.size();j++){
				if(src[j]==dic[i].first[0]&&!strcmp(dic[i].first.c_str(),subs(src,j,j+dic[i].first.size()).c_str())&&!strcmp((subs(src,0,j)+dic[i].second+subs(src,j+dic[i].first.size(),src.size())).c_str(),tgt.c_str())){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

