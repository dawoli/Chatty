#include<iostream>
#include<cstdio>
using namespace std;

bool d[15],h[15],c[15],s[15];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	string k;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		if(k[0]=='D'){
			if(k[1]=='T') d[10]=true;
			else if(k[1]=='A') d[1]=true;
			else if(k[1]=='J') d[11]=true;
			else if(k[1]=='Q') d[12]=true;
			else if(k[1]=='K') d[13]=true;
			else d[k[1]-'0']=true;
		}
		else if(k[0]=='H'){
			if(k[1]=='T') h[10]=true;
			else if(k[1]=='A') h[1]=true;
			else if(k[1]=='J') h[11]=true;
			else if(k[1]=='Q') h[12]=true;
			else if(k[1]=='K') h[13]=true;
			else h[k[1]-'0']=true;
		}
		else if(k[0]=='C'){
			if(k[1]=='T') c[10]=true;
			else if(k[1]=='A') c[1]=true;
			else if(k[1]=='J') c[11]=true;
			else if(k[1]=='Q') c[12]=true;
			else if(k[1]=='K') c[13]=true;
			else c[k[1]-'0']=true;
		}
		else{
			if(k[1]=='T') s[10]=true;
			else if(k[1]=='A') s[1]=true;
			else if(k[1]=='J') s[11]=true;
			else if(k[1]=='Q') s[12]=true;
			else if(k[1]=='K') s[13]=true;
			else s[k[1]-'0']=true;
		}
	}
	int cnt=0;
	for(int i=1;i<=13;i++){
		if(d[i]==false) cnt++;
		if(h[i]==false) cnt++;
		if(s[i]==false) cnt++;
		if(c[i]==false) cnt++;

	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
