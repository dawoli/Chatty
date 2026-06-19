#include<iostream>
using namespace std; 
int a[10];
string str;
int main(){ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>str;
	for(char s:str){
		if(s>='0'&&s<='9') a[s-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
