#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int js[100]={},js2;
	for(int i=0;i<s.length();i++){
		if((s[i]>='0')&&(s[i]<='9')){
			js[s[i]-'0']++;
			js2++;
		}
	}
	while(1){
		if(js[9]){
			cout<<9;
			js[9]--;
		}
		else if(js[8]){
			cout<<8;
			js[8]--;
		}
		else if(js[7]){
			cout<<7;
			js[7]--;
		}
		else if(js[6]){
			cout<<6;
			js[6]--;
		}
		else if(js[5]){
			cout<<5;
			js[5]--;
		}
		else if(js[4]){
			cout<<4;
			js[4]--;
		}
		else if(js[3]){
			cout<<3;
			js[3]--;
		}
		else if(js[2]){
			cout<<2;
			js[2]--;
		}
		else if(js[1]){
			cout<<1;
			js[1]--;
		}
		else if(js[0]){
			cout<<0;
			js[0]--;
		}
		else{
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//-static-libgcc
