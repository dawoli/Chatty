#include<iostream>
using namespace std;
int n,ans;
char c[20],s[20],d[20],h[20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<51;
		return 0;
	}
	for(int i=0;i<n;i++){
		char a,b;
		cin>>a>>b;
		int x;
		if(b=='A'){
			x=1;
		}else if(b=='T'){
			x=10;
		}else if(b=='J'){
			x=11;
		}else if(b=='Q'){
			x=12;
		}else if(b=='K'){
			x=13;
		}else if('2'<=b&&b<='9'){
			x=b-'0';
		}
		if(a=='S'&&s[x]==0){
			s[x]++;
			ans++;
		}else if(a=='D'&&d[x]==0){
			d[x]++;
			ans++;
		}else if(a=='C'&&c[x]==0){
			c[x]++;
			ans++;
		}else if(a=='H'&&h[x]==0){
			h[x]++;
			ans++;
		}
	}
	cout<<52-ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
