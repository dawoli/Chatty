#include<bits/stdc++.h>
using namespace std;
string p[200];
int n;
int d[15],c[15],h[15],s[15];
int q;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		string x=p[i];
		if(x[0]=='D'){
			if(x[1]==1) d[1]++;
			else if(x[1]==2) d[2]++;
			else if(x[1]==3) d[3]++;
			else if(x[1]==4) d[4]++;
			else if(x[1]==5) d[5]++;
			else if(x[1]==6) d[6]++;
			else if(x[1]==7) d[7]++;
			else if(x[1]==8) d[8]++;
			else if(x[1]==9) d[9]++;
			else if(x[1]=='T') d[10]++;
			else if(x[1]=='J') d[11]++;
			else if(x[1]=='Q') d[12]++;
			else if(x[1]=='K') d[13]++;
		}
		else if(x[0]=='C'){
			if(x[1]==1) c[1]++;
			else if(x[1]==2) c[2]++;
			else if(x[1]==3) c[3]++;
			else if(x[1]==4) c[4]++;
			else if(x[1]==5) c[5]++;
			else if(x[1]==6) c[6]++;
			else if(x[1]==7) c[7]++;
			else if(x[1]==8) c[8]++;
			else if(x[1]==9) c[9]++;
			else if(x[1]=='T') c[10]++;
			else if(x[1]=='J') c[11]++;
			else if(x[1]=='Q') c[12]++;
			else if(x[1]=='K') c[13]++;
		} 
		else if(x[0]=='H'){
			if(x[1]==1) h[1]++;
			else if(x[1]==2) h[2]++;
			else if(x[1]==3) h[3]++;
			else if(x[1]==4) h[4]++;
			else if(x[1]==5) h[5]++;
			else if(x[1]==6) h[6]++;
			else if(x[1]==7) h[7]++;
			else if(x[1]==8) h[8]++;
			else if(x[1]==9) h[9]++;
			else if(x[1]=='T') h[10]++;
			else if(x[1]=='J') h[11]++;
			else if(x[1]=='Q') h[12]++;
			else if(x[1]=='K') h[13]++;
		}
		else if(x[0]=='S'){
			if(x[1]==1) s[1]++;
			else if(x[1]==2) s[2]++;
			else if(x[1]==3) s[3]++;
			else if(x[1]==4) s[4]++;
			else if(x[1]==5) s[5]++;
			else if(x[1]==6) s[6]++;
			else if(x[1]==7) s[7]++;
			else if(x[1]==8) s[8]++;
			else if(x[1]==9) s[9]++;
			else if(x[1]=='T') s[10]++;
			else if(x[1]=='J') s[11]++;
			else if(x[1]=='Q') s[12]++;
			else if(x[1]=='K') s[13]++;
		}
		
	}
	for(int i=1;i<=13;i++){
		if(d[i]==0) q++;
		if(c[i]==0) q++;
		if(h[i]==0) q++;
		if(s[i]==0) q++;		 
	}
	cout<<q-1;
	return 0;
} 
