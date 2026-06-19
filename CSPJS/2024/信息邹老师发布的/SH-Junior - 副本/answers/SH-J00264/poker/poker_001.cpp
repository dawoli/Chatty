#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

typedef long long ll;

ll n,cnt,d[15],c[15],h[15],s[15];

string a;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		char vx=a[0];
		char vxy=a[1];
		int vy=0;
		if(vxy=='A'){
			vy=1;
		}
		else if(vxy=='T'){
			vy=10;
		}
		else if(vxy=='J'){
			vy=11;
		}
		else if(vxy=='Q'){
			vy=12;
		}
		else if(vxy=='K'){
			vy=13;
		}
		else{
			vy=vxy-'0';
		}
		if(vx=='D'){
			d[vy]=1;
		}
		else if(vx=='C'){
			c[vy]=1;
		}
		else if(vx=='H'){
			h[vy]=1;
		}
		else if(vx=='S'){
			s[vy]=1;
		}
	}
	for(int i=1;i<=13;i++){
		cnt+=d[i];
	}
	for(int i=1;i<=13;i++){
		cnt+=c[i];
	}
	for(int i=1;i<=13;i++){
		cnt+=h[i];
	}
	for(int i=1;i<=13;i++){
		cnt+=s[i];
	}
	cout<<52-cnt<<endl;
	return 0;
} 
