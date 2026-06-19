#include<bits/stdc++.h>
using namespace std;
vector<pair<string,string>> s;//前变后 
int n,q;//二元组数 询问数
long long ans;
string cut(string a,int i,int length){
	string re="";
	for(int j=i;j!=i+length;j++){
		re=re+a[j];
	}
	return re;
}
void zzz(string from,string to,int i,bool used){
	if(i>from.size()){
		return;
	}
	if(i==from.size()){
		ans++;
		return;
	}
	if(from[i]==to[i]){
		//cout<<"$$$"<<from[i]<<' '<<to[i]<<endl;
		zzz(from,to,i+1,used);
	}
	if(used==false){
		for(int j=0;j!=s.size();j++){
			if(s[j].first.size()+i>from.size()){
				continue;
			}
			if(cut(from,i,s[j].first.size())==s[j].first and cut(to,i,s[j].second.size())==s[j].second){
				zzz(from,to,i+s[j].first.size(),true);
			}
		}	
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i!=n;i++){
		string a,b;
		cin>>a>>b;
		s.push_back(make_pair(a,b));
	}
	for(int z=0;z!=q;z++){
		string from,to;
		ans=0;
		cin>>from>>to;
		zzz(from,to,0,false);
		cout<<ans<<endl;
	}
	return 0;
}

