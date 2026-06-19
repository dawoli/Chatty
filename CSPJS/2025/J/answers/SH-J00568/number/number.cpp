#include<bits/stdc++.h>
using namespace std;
string s;
int n[10];
int main(){
	freopen("number.in","r",stdin);//
	freopen("number.out","w",stdout);
	cin>>s;
	//cout<<s;//
	int l=s.size();
	//cout<<l;//
	for(int i=0;i<l;i++){
		if((s[i]-'0')>=0 && (s[i]-'0')<=9){
			n[s[i]-'0']++;
		}
	}
	for(int i=9;i>-1;i--){
		//cout<<i;//
		while(n[i]>0){
			cout<<i;
			n[i]--;
		}
	}
	return 0;
}
