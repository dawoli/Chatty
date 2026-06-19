#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ii,ans;
	cin>>n>>q;
	string s[1][200000],t1,t2,tt;
	for(int i=0;i<n;i++){
		cin>>s[0][i]>>s[1][i];
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		for(int i=0;i<n;i++){
			tt=t1;
			if(tt.find(s[0][i])<=tt.length()-s[0][i].length()){
				ii=tt.find(s[0][i]);
				tt.erase(ii,s[0][i].length());
				tt.insert(ii,s[1][i]);
				if(tt==t2){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
