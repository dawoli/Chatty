#include<bits/stdc++.h>
using namespace std;
int n,ans;
int d[20],c[20],h[20],s[20];
char hs,ds;
int my_change(char x){
	if('2'<=x&&x<='9'){
		return x-'0';
	}
	if(x=='A'){
		return 1;
	}
	if(x=='T'){
		return 10;
	}
	if(x=='J'){
		return 11;
	}
	if(x=='Q'){
		return 12;
	}
	return 13;
}
void cnt(int x[]){
	for(int i=1;i<=13;++i){
		if(x[i]==0)
		    ++ans;
	}
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>hs>>ds;
		if(hs=='D'){
			d[my_change(ds)]=1;
		}else if(hs=='C'){
			c[my_change(ds)]=1;
		}else if(hs=='H'){
			h[my_change(ds)]=1;
		}else{
			s[my_change(ds)]=1;
		}
	}
	cnt(d);
	cnt(c);
	cnt(h);
	cnt(s);
	cout<<ans;
} 
