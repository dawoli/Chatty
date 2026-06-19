#include<bits/stdc++.h>
using namespace std;
char a[60],b[60];
int sd[20],sc[20],sh[20],ss[20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(a[i]=='D'){
			if(b[i]=='A'){
				sd[1]++;
			}
			else if(b[i]>=50 && b[i]<=57){
				sd[b[i]-'0']++;
			}
			else if(b[i]=='T'){
				sd[10]++;
			}
			else if(b[i]=='J'){
				sd[11]++;
			}
			else if(b[i]=='Q'){
				sd[12]++;
			}
			else{
				sd[13]++;
			}
		}
		else if(a[i]=='C'){
			if(b[i]=='A'){
				sc[1]++;
			}
			else if(b[i]>=50 && b[i]<=57){
				sc[b[i]-'0']++;
			}
			else if(b[i]=='T'){
				sc[10]++;
			}
			else if(b[i]=='J'){
				sc[11]++;
			}
			else if(b[i]=='Q'){
				sc[12]++;
			}
			else{
				sc[13]++;
			}
		}
		else if(a[i]=='H'){
			if(b[i]=='A'){
				sh[1]++;
			}
			else if(b[i]>=50 && b[i]<=57){
				sh[b[i]-'0']++;
			}
			else if(b[i]=='T'){
				sh[10]++;
			}
			else if(b[i]=='J'){
				sh[11]++;
			}
			else if(b[i]=='Q'){
				sh[12]++;
			}
			else{
				sh[13]++;
			}
		}
		else if(a[i]=='S'){
			if(b[i]=='A'){
				ss[1]++;
			}
			else if(b[i]>=50 && b[i]<=57){
				ss[b[i]-'0']++;
			}
			else if(b[i]=='T'){
				ss[10]++;
			}
			else if(b[i]=='J'){
				ss[11]++;
			}
			else if(b[i]=='Q'){
				ss[12]++;
			}
			else{
				ss[13]++;
			}
		}
	}
	for(int i=1;i<=13;i++){
		if(sd[i]){
			s++;
		}
		if(sc[i]){
			s++;
		}
		if(sh[i]){
			s++;
		}
		if(ss[i]){
			s++;
		}
	}
	cout<<52-s;
	return 0;
}
