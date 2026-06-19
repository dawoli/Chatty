#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	map<string,string> replace;
	string s1,s2;
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		replace[s1]=s2;
	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) cout<<0<<endl;
		else{
			int st,ed;
			for(int i=0;i<t1.size();i++){
				if(t1[i]!=t2[i]&&t1[i-1]==t2[i-1]) st=i;
				if(t1[i]==t2[i]&&t1[i-1]!=t2[i-1]){
					ed=i-1;
					continue;
				}
			}
			string tp1="",tp2="";
			for(int i=ed+1;i<t1.size();i++) tp1+=t1[i];
			for(int i=ed+1;i<t2.size();i++) tp2+=t2[i];
			if(tp1!=tp2) cout<<0<<endl;
			else{
				string td1="",td2="";
				for(int i=st;i<=ed;i++) td1+=t1[i];
				for(int i=st;i<=ed;i++) td2+=t2[i];
				if(replace[td1]==td2) ans++;
				for(int i=st-1;i>=0;i--){
					td1=t1[i]+td1;
					td2=t2[i]+td2;
					string tdp1=td1,tdp2=td2;
					if(replace[tdp1]==tdp2) ans++;
					for(int j=ed+1;j<t1.size();j++){
						tdp1+=t1[j];
						tdp2+=t2[j];
						if(replace[tdp1]==tdp2) ans++;
					}
				}
				cout<<ans<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
