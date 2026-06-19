#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[10000]={0};
	int t=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(int(s[i])<65){
			a[t]=int(s[i])-48;
			t++;
		}
	}sort(a,a+t,cmp);
	for(int i=0;i<t;i++){
		cout<<a[i];
	}
	return 0;
} 
