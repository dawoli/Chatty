#include<bits/stdc++.h>
using namespace std;
int a[55][55],n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char ch[3];
		int p=0,q=0;
		cin>>ch;
		if(ch[0]=='D'){
			p=1;
		}else if(ch[0]=='C'){
			p=2;
		}else if(ch[0]=='H'){
			p=3;
		}else if(ch[0]=='S'){
			p=4;
		}
		if(ch[1]=='T'){
			q=10;
		}else if(ch[1]=='J'){
			q=11;
		}else if(ch[1]=='Q'){
			q=12;
		}else if(ch[1]=='K'){
			q=13;
		}else if(ch[1]=='A'){
			q=1;
		}else{
			q=int(ch[1]-'0');
		}
		a[p][q]=1;
	}
	int cnt=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(a[i][j]==1) cnt++;
		}
	}
	cout<<52-cnt;
	return 0;
}
