#include<bits/stdc++.h>
using namespace std;
bool d[14],c[14],h[14],s[14];
int m,ans;
string str;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str;
		if(str[1]=='T')m=10;
		else if(str[1]=='J')m=11;
		else if(str[1]=='Q')m=12;
		else if(str[1]=='K')m=13;
		else if(str[1]=='A')m=1;
		else m=str[1]-'0';
		switch(str[0]){
			case 'D':{
				d[m]=1;
				break;
			}
			case 'C':{
				c[m]=1;
				break;
			}
			case 'H':{
				h[m]=1;
				break;
			}
			case 'S':{
				s[m]=1;
				break;
			}
		}
		
	}
	for(int i=1;i<=13;i++){
		if(d[i]==0)ans++;
	}
	for(int i=1;i<=13;i++){
		if(c[i]==0)ans++;
	}
	for(int i=1;i<=13;i++){
		if(h[i]==0)ans++;
	}
	for(int i=1;i<=13;i++){
		if(s[i]==0)ans++;
	}
	cout<<ans;
	return 0;
}

