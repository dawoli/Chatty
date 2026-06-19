#include<bits/stdc++.h>
using namespace std;
string s1[200009],s2[200009];
struct aaa{
	int x,y;
};
map<pair<string,string>,vector<aaa> > mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		string tmp1=s1[i],tmp2=s2[i];
		int cnt=0;
		while(tmp1[0]==tmp2[0]&&tmp1.size())
			tmp1.erase(0,1),tmp2.erase(0,1),cnt++;
		for(int j=tmp1.size()-1;j>-1;j--){
			if(tmp1[j]==tmp2[j])
				tmp1.erase(j,1),tmp2.erase(j,1);
			else
				break;
		}
		mp[{tmp1,tmp2}].push_back({i,cnt});
	}
	while(q--){
		int ans=0;
		string a1,a2;
		cin>>a1>>a2;
		string t1=a1,t2=a2;
		int cnt=0;
		while(t1[0]==t2[0]&&t1.size())
			t1.erase(0,1),t2.erase(0,1),cnt++;
		for(int j=t1.size()-1;j>-1;j--){
			if(t1[j]==t2[j])
				t1.erase(j,1),t2.erase(j,1);
			else
				break;
		}
		for(int j=0;j<mp[{t1,t2}].size();j++){
			int k=mp[{t1,t2}][j].x;
			int k2=mp[{t1,t2}][j].y;
			if(cnt<k2)
				continue;
			string b1=a1.substr(cnt-k2,s1[k].size()),b2=a2.substr(cnt-k2,s2[k].size());
			if(s1[k]==b1&&s2[k]==b2)
				ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//ÆÀ²â»ú·¢Á¦
//rp++ 
