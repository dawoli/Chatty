#include<bits/stdc++.h>
using namespace std;
int n,l; 
int cnt=0;
bool d[52],c[52],h[52],z[52];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	 cin>>n;
	 for(int i=1;i<=n;i++){
	 	string s;
	 	cin>>s;
	 	l=s.size()-1;
		 	if(s[1]=='A'){
	 			s[1]=1;
			 }
			 if(s[1]=='J'){
			 	s[1]=11;
			 }
			 if(s[1]=='Q'){
			 	s[1]=12;
			 }
			 if(s[1]=='K'){
			 	s[1]=13;
			 }
			 if(s[1]=='T'){
			 	s[1]=10;
			 }
			 if(s[1]=='2'){
			 	s[1]=2;
			 }
			 if(s[1]=='3'){
			 	s[1]=3;
			 }
			 if(s[1]=='4'){
			 	s[1]=4;
			 }
			 if(s[1]=='5'){
			 	s[1]=5;
			 }
			 if(s[1]=='6'){
			 	s[1]=6;
			 }
			 if(s[1]=='7'){
			 	s[i]=7;
			 }
			 if(s[1]=='8'){
			 	s[1]=8;
			 }
			 if(s[1]=='9'){
			 	s[1]=9;
			 }
	 	if(s[0]=='D'){
	 		d[s[1]]=1;
		 }
		 if(s[0]=='C'){
		 	c[s[1]]=1;
		 }
		 if(s[0]=='H'){
		 	h[s[1]]=1;
		 }
		 if(s[0]=='S'){
		 	z[s[1]]=1;
		 }
	
	 }

	 for(int i=1;i<=13;i++){
	 	if(d[i]==0){
	 		cnt++; 
		 }
		 if(c[i]==0){
	 		cnt++; 
		 }
		 if(h[i]==0){
	 		cnt++; 
		 }
		 if(z[i]==0){
	 		cnt++; 
		 }
	 }
	 cout<<cnt;
	 return 0;
}
