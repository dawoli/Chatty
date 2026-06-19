#include<bits/stdc++.h>
using namespace std;
int n,q;
map<unsigned long long,int> mp;
int cntp=0;
vector<string> gr1[200005];
vector<string> gr2[200005];
unsigned long long mns(string str1,string str2){
	bool flg=0;
	unsigned long long answ=0;
	int ld=-1;
	unsigned long long temp=0;
	for(int i=str1.length()-1;i>=0;i--){
		if(str1[i]!=str2[i]){
			ld=i;
			break;
		}
	}
	for(int i=0;i<=ld;i++){
		if(!flg&&str1[i]!=str2[i]){
			flg=1;
		}
		if(flg){
			answ*=52;
			answ+=(str2[i]-str1[i]+25);
			temp*=26;
			temp+=(str1[i]-'a');
		}
	}
	unsigned long long fna=answ*19260817+temp;
	return fna;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	unsigned long long tp;
	string str1,str2;
	for(int i=1;i<=n;i++){
		cin>>str1>>str2;
		tp=mns(str1,str2);
		if(mp[tp]==0) mp[tp]=++cntp;
		gr1[mp[tp]].push_back(str1);
		gr2[mp[tp]].push_back(str2);
	}
	for(int i=1;i<=q;i++){
		cin>>str1>>str2;
		if(str1.length()!=str2.length()){
			cout<<0<<'\n';
			continue;
		}
		tp=mns(str1,str2);
		int xb=mp[tp];
		int myans=0;
		for(int j=0;j<gr1[xb].size();j++){
			if((str1.find(gr1[xb][j]))<100000000&&str2.find(gr2[xb][j])<100000000){
				myans++;
			}
		}
		cout<<myans<<'\n';
	}
	return 0;
}

