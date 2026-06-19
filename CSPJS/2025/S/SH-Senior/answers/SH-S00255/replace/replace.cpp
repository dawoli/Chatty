#include<bits/stdc++.h>
using namespace std;
string s1[2000005],s2[2000005];
int p[200005];
bool flag1=true;
void test(string k){
	int cnt=0;
	for(int i=0;i<k.size();i++){
		if(k[i]=='b') cnt++;
		if(cnt>1) flag1=false;
		if(k[i]!='a'&&k[i]!='b'){
			flag1=false;
			return;
		}
	}
	if(cnt==0) flag1=false;
	return;
}
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
		if(flag1==true) test(s1[i]);
		if(flag1==true) test(s2[i]);
	}
	while(q--){
		string s3,s4;
		cin>>s3>>s4;
		if(s3.size()!=s4.size()){
			cout<<0;
			continue;
		}
		int cnt1=0,cnt2=0;
		if(flag1==true) test(s3);
		if(flag1==true) test(s4);
		if(flag1==true){
			
			continue;
		}
		int last=-1,first=1919810;
		for(int i=0;i<s3.size();i++){
			if(s3[i]!=s4[i]){
				if(i<first) first=i;
				if(i>last) last=i;
			}
		}
		string s11="",s12="";
		for(int i=first;i<=last;i++){
			s11[i-first]=s3[first];
			s12[i-first]=s4[first];
		}
		
	}
	return 0;
}
