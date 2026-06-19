#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N]; 
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=0;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]<97 || s[i]>122){
			n++;
			a[n]=int(s[i])-48;
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
