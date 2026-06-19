#include<bits/stdc++.h>
using namespace std;
bool a[60]; 
int work(char x, char y){
	int x_, y_;
	switch(x){
		case 'D': x_=0; break;
		case 'C': x_=1; break;
		case 'H': x_=2; break;
		case 'S': x_=3; break;
	}
	switch(y){
		case 'T': y_=10; break;
		case 'J': y_=11; break;
		case 'Q': y_=12; break;
		case 'K': y_=13; break;
		case 'A': y_=1; break;
		default: y_=y-'0'; break;
	}
	return y_+13*x_;
}
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		string s;
		cin>>s;
		a[work(s[0],  s[1])]=true;
	}
	int ans=0;
	for(int i=1; i<=52; i++){
		if(!a[i]) ans++;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
