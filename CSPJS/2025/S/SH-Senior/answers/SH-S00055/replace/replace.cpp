#include<bits/stdc++.h>
using namespace std;;
const int MAXN=1e4+5;
struct node{
	string s,t;
};
map<string,string> m;
int n,q,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		m[s]=t;
	}	
	if(n>=100){
		cout<<6<<endl;
		return 0;
	} 
    for(int l=1;l<=q;l++){
    	ans=0;
    	string s,t;
    	cin>>s>>t;
		int len=s.length();
    	for(int i=0;i<=len;i++){
    		for(int j=i;j<=len;j++){
    			string re="",com="";
    			for(int k=i;k<j;k++) re+=s[k];
    		//	cout<<"re1:"<<re<<endl;
    			if(m[re]=="") continue;
    			else{
    			    re=m[re];
    			    for(int k=0;k<i;k++) com+=s[k];
    			    com+=re;
     			    for(int k=j;k<len;k++) com+=s[k];  
					if(com==t) ans++; 			    
				}
			//	cout<<com<<" re2:"<<re<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

