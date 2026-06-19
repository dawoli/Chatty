#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
bool flagb=0;
int n,q,ans;
vector<int>l[27];
string s1[N],s2[N];
void dfs(string t1,string t2){
	int k;
	string x1,x2,y1,y2;
	for(int i=0;i<t1.size();i++){
		int x=t1[i]-'a'+1;
		for(int j=0;j<l[x].size();j++){
			k=l[x][j];
			int www=t1.size()-i-s1[k].size();
			//cout<<"                           i="<<i<<" k="<<k<<"   t1: "<<t1.size()<<" s1["<<k<<"]: "<<s1[k].size()<<"   "<<www<<endl;
			if(www<0){
				//cout<<"No !!!   i="<<i<<" k="<<k<<endl;
				continue;
			}
			if(t1.substr(i,s1[k].size())==s1[k]&&t2.substr(i,s1[k].size())==s2[k]){
				x1=t1.substr(0,i);
				x2=t2.substr(0,i);
				y1=t1.substr(i+s1[k].size(),www);
				y2=t2.substr(i+s1[k].size(),www);
				//cout<<"x1: "<<x1<<" y1: "<<y1<<" x2: "<<x2<<" y2: "<<y2<<endl;
				if(x1==x2&&y1==y2){
					//cout<<"Use i="<<i<<"  k="<<k<<endl;
					//cout<<"s1: "<<s1[k]<<" --> s2: "<<s2[k]<<endl;
					ans++;
				}
			}
		}
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		l[s1[i][0]-'a'+1].push_back(i);
	}
	string t1,t2;
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t1>>t2;
		dfs(t1,t2);
		cout<<ans<<endl;
	}
	return 0;
}
