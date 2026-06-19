#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string puk[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int m=0;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		bool h=true;
		for(int j=1;j<=55;j++){
			if(puk[j]==s) h=false;
		}
		if(h){
			++m;
			puk[m]=s;	
		}
	}
	int ans=0;
	for(int i=1;i<=55;i++){
		if(puk[i]!="") ans++;
	}
	cout<<52-ans<<endl;//
	fclose(stdin);fclose(stdout);
}
