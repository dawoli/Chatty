#include<bits/stdc++.h>
using namespace std;

string col[]={"D","C","H","S"};
string num[]={"A","2","3","4","5","6","7","8","9","T","J","Q","K"};

map<string,bool> vis;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=52;
	cin>>n;
	for(int i=1;i<=n;++i){
		string s;cin>>s;
		vis[s]=1;
	}
	for(int i=0;i<4;++i){
		for(int j=0;j<13;++j){
			string s=col[i]+num[j];
			if(vis[s])--ans;
		}
	}
	cout<<ans;
}
//Hughpig(Luogu646208)
