#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
string s1[N],s2[N];
int n,q;
bool judge(string t1, string t2){
	int where=0;
	while(where<t1.size()){
		if(t1[where]==t2[where]){
			where++;
			continue;
		}
		else return false;
	}
	return true;
}
bool replace(string t1, int start, int id, string t2){
	string rs=s2[id];
	for(int i=0;i<rs.length();i++){
		t1[start+i]=rs[i];
	}
	return judge(t1,t2);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i];
		cin>>s2[i];
	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		string t3=t1;
		for(int i=0;i<t1.length();i++){
			for(int j=0;j<n;j++){
				if(t1[i]==s1[j][0]&&replace(t1,i,j,t2)){
					ans++;
				} 
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
}
