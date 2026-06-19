#include<bits/stdc++.h>
using namespace std;
int T,n;
string ans;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		ans="";
		cin>>n;
		string s="";
		if(n<2){
			cout<<"-1"<<endl;
			continue;
		}while(n-14>0){
			s="8"+s;
			n-=7;
		}if(n==13) s="68"+s;
		else if(n==12) s="28"+s;
		else if(n==11) s="26"+s;
		else if(n==10) s="22"+s;
		else if(n==9) s="18"+s;
		else if(n==8) s="16"+s;
		else if(n==7) s="8"+s;
		else if(n==6) s="6"+s;
		else if(n==5) s="2"+s;
		else if(n==4) s="4"+s;
		else if(n==3) s="7"+s;
		else if(n==2) s="1"+s;
		else if(n==1){
			for(int i=1;i<s.length();i++){
				s=ans[i]+s;
				s="222"+s;
			}
		}if(s) cout<<s<<endl;
		else cout<<ans<<endl;
	}fclose(stdin);
	fclose(stdout);
	return 0;
} 
