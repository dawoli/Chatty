#include <bits/stdc++.h>
using namespace std;
int a[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,x;
	string s;
	cin>>n;
	for(int i=1;i<=52;i++){
		a[i]=0;
	}
	for(int i=1;i<=n;i++){
		x=0;
		cin>>s;
		if(s[0]=='C'){
			x+=13;
		}else if(s[0]=='H'){
			x+=26;
		}else if(s[0]=='S'){
			x+=39;
		}
		if(s[1]=='A'){
			x+=1;
		}else if(s[1]=='2'){
			x+=2;
		}else if(s[1]=='3'){
			x+=3;
		}else if(s[1]=='4'){
			x+=4;
		}else if(s[1]=='5'){
			x+=5;
		}else if(s[1]=='6'){
			x+=6;
		}else if(s[1]=='7'){
			x+=7;
		}else if(s[1]=='8'){
			x+=8;
		}else if(s[1]=='9'){
			x+=9;
		}else if(s[1]=='T'){
			x+=10;
		}else if(s[1]=='J'){
			x+=11;
		}else if(s[1]=='Q'){
			x+=12;
		}else if(s[1]=='K'){
			x+=13;
		}
		a[x]=1;
	}
	int ans=0;
	for(int i=1;i<=52;i++){
		if(a[i]==0){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
