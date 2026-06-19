#include<bits/stdc++.h>
using namespace std;
string s,t,w;
long long int m,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=1;
	for(char c:s){
		if(c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9' || c=='0'){
			m=c-'0';
			t+=c;
		}
	}
	sort(t.begin(),t.end());
	for(char c:t){
		if(c=='9'){
			w+=c;
		}
	}
	for(char c:t){
		if(c=='8'){
			w+=c;
		}
	}
	for(char c:t){
		if(c=='7'){
			w+=c;
		}
	}
	for(char c:t){
		if(c=='6'){
			w+=c;
		}
	}
	for(char c:t){
		if(c=='5'){
			w+=c;
		}
	}
	for(char c:t){
		if(c=='4'){
			w+=c;
		}
	}
	for(char c:t){
		if(c=='3'){
			w+=c;
		}
	}
	for(char c:t){
		if(c=='2'){
			w+=c;
		}
	}
	for(char c:t){
		if(c=='1'){
			w+=c;
		}
	}
	for(char c:t){
		if(c=='0'){
			w+=c;
		}
	}
	cout<<w;
	return 0;
}
