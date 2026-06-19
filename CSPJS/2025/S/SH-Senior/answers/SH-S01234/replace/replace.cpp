#include<bits/stdc++.h>
using namespace std;

const int maxlen=5e6+10;
int n,q;
vector<pair<string,string>> s;
vector<pair<string,string>> t;

string cun1;
string cun2;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string tmpa,tmpb;
		cin>>tmpa>>tmpb;
		s.push_back({tmpa,tmpb});
	}
	for(int i=1;i<=q;i++){
		string tmpc,tmpd;
		cin>>tmpc>>tmpd;
		t.push_back({tmpc,tmpd});
	}
	for(int i=1;i<=t[i].first.length();i++){
		int cnt=0;
		if(t[i].first[i]=='b'){
			for(int j=1;j<=i-1;j++){
				cun1[j]=t[i].first[j];
			} 
			for(int j=1;j<=maxlen;j++){
				for(int k=1;k<=maxlen;k++){
					if(s[j].first[k]=='b' && k<=i){
						for(int w=1;w<=j;w++){
							cun2[w]=s[j].first[w];
						}
						for(int w=1;w<=maxlen;w++){
							if(cun1+cun2==t[i].second)cnt++;
						}
					}
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
