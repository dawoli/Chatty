#include<bits/stdc++.h>
using namespace std;
const int N = 1e4;
int n;
int a[N];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	int ans = 52;
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		int p = 0;
		if(s[0]=='C'){
			p+=100;
		}if(s[0]=='H'){
			p+=200;
		}if(s[0]=='S'){
			p+=300;
		}
		if(s[1]>='A'){
			int t = s[1];
			p+=t;
		}else{
			p+=s[1]-48;
		}
		a[p]++;
	}for(int i = 0;i<1000;i++){
		if(a[i]){
			ans--;
		}
	}
	cout<<ans;
	return 0;
} 
