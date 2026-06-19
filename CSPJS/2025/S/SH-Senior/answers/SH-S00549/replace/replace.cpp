#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		string t1,t2;
		int tt1=-1,tt2=-1;
		string dif1="",dif2="";
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				tt1=i;
				break;
			}
		}
		for(int i=t1.size()-1;i>=0;i--){
			if(t1[i]!=t2[i]){
				tt2=i;
				break;
			}
		}
		for(int i=tt1;i<=tt2;i++){
			dif1+=t1[i];
			dif2+=t2[i];
		} 
		string diff1=dif1,diff2=dif2;
		//cout<<dif1<<" "<<dif2<<endl;
		int ans=0;
		for(int i=1;i<=n;i++){
			dif1=diff1;
			dif2=diff2;
			if(s[i][0].size()<dif1.size()) continue;
			else if(s[i][0].size()==dif1.size()){
				if(s[i][0]==dif1&&s[i][1]==dif2) ans++;
			}else{
				while(dif1[0]!=s[i][0][0]&&tt1>0){
					tt1--;
					dif1=t1[tt1]+dif1;
					dif2=t2[tt1]+dif2;
				}
				while(dif1[dif1.size()-1]!=s[i][0][s[i][0].size()-1]&&tt2<t1.size()){
					tt2++;
					dif1=dif1+t1[tt2];
					dif2=dif2+t2[tt2];
				}	
				if(s[i][0]==dif1&&s[i][1]==dif2) ans++;			
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

