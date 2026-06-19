#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int q,n;
string s[N],t[N];
string cg(string r,int x,int y,string e){
	string ans="";
	for(int i=0;i<x;i++)ans+=r[i];
	ans+=e;
	for(int i=y+1;i<r.size();i++)ans+=r[i];
//	cout<<ans<<endl;
	return ans;
}
bool jd(string r,int x,string e){
	string d="";
	for(int i=x;i<x+e.size();i++)d+=r[i];
//	cout<<d<<' '<<e<<endl;
	return d==e;
}
void solve(){
	string a,b;
	int cnt=0;
	cin>>a>>b;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<n;j++){
			if(jd(a,i,s[j])&&cg(a,i,i+s[j].size()-1,t[j])==b){
				cnt++;
				break;
			}
		}
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>s[i]>>t[i];
	while(q--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

