#include<bits/stdc++.h>
using namespace std;
long long d[500];
long long c[500];
long long h[500];
long long s[500];
long long m;
char a[100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a;
		if(a[0]=='S'){
			if(a[1]=='A'){
				s[1]=1;
			}
			else if(a[1]=='T'){
				s[10]=1;
			}
			else if(a[1]=='J'){
				s[11]=1;
			}
			else if(a[1]=='Q'){
				s[12]=1;
			}
			else if(a[1]=='K'){
				s[13]=1;
			}
			else{
				s[a[1]-'0']=1;
			}
		}
		if(a[0]=='D'){
			if(a[1]=='A'){
				d[1]=1;
			}
			else if(a[1]=='T'){
				d[10]=1;
			}
			else if(a[1]=='J'){
				d[11]=1;
			}
			else if(a[1]=='Q'){
				d[12]=1;
			}
			else if(a[1]=='K'){
				d[13]=1;
			}
			else{
				d[a[1]-'0']=1;
			}
		}
		if(a[0]=='C'){
			if(a[1]=='A'){
				c[1]=1;
			}
			else if(a[1]=='T'){
				c[10]=1;
			}
			else if(a[1]=='J'){
				c[11]=1;
			}
			else if(a[1]=='Q'){
				c[12]=1;
			}
			else if(a[1]=='K'){
				c[13]=1;
			}
			else{
				c[a[1]-'0']=1;
			}
		}
		if(a[0]=='H'){
			if(a[1]=='A'){
				h[1]=1;
			}
			else if(a[1]=='T'){
				h[10]=1;
			}
			else if(a[1]=='J'){
				h[11]=1;
			}
			else if(a[1]=='Q'){
				h[12]=1;
			}
			else if(a[1]=='K'){
				h[13]=1;
			}
			else{
				h[a[1]-'0']=1;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=13;i++){
		if(h[i]==0){
			cnt++;

		}
		if(d[i]==0){
			cnt++;

		}
		if(c[i]==0){
			cnt++;

		}
		if(s[i]==0){
			cnt++;

		}
	}
	
	cout<<cnt;
	return 0;
}
