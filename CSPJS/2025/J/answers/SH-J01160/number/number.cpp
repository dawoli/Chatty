#include <bits/stdc++.h>
using namespace std;
string s;
int p[20];
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') p[0]++;
		if(s[i]=='1') p[1]++;
		if(s[i]=='2') p[2]++;
		if(s[i]=='3') p[3]++;
		if(s[i]=='4') p[4]++;
		if(s[i]=='5') p[5]++;
		if(s[i]=='6') p[6]++;
		if(s[i]=='7') p[7]++;		
		if(s[i]=='8') p[8]++;
		if(s[i]=='9') p[9]++;
	}
	bool k=false;
	for(int i=9;i>0;i--){
		if(p[i]>0){
			for(int j=1;j<=p[i];j++){
				cout<<i;
			}
			k=true;
		}	
	}
	if(k&&p[0]>0){
		for(int i=1;i<=p[0];i++) cout<<0;
	}
	cout<<endl;
	return 0;
} 
