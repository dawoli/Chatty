#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
int ans;
int main(){
	
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		m[s]++;
	}
	for(int i=1;i<=4;i++){
		string a,b;
		if(i==1)
			a="D";
		if(i==2)
			a="C";
		if(i==3)
			a="H";
		if(i==4)
			a="S";
		string ab=a+"A";
		if(m[ab]==0) ans++;
		for(int j=2;j<=9;j+=1){
			if(j==2)
				b="2";
			if(j==3)
				b="3";
			if(j==4)
				b="4";
			if(j==5)
				b="5";
			if(j==6)
				b="6";
			if(j==7)
				b="7";
			if(j==8)
				b="8";
			if(j==9)
				b="9";
			string ab=a+b;
			if(m[ab]==0) ans++;
		}
		for(int j=10;j<=13;j++){
			if(j==10)
				b="T";
			if(j==11)
				b="J";
			if(j==12)
				b="Q";
			if(j==13)
				b="K";	
			string ab=a+b;
			if(m[ab]==0) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}


