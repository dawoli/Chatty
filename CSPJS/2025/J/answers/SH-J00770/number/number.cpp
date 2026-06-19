#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	string s;
	cin>>s;
	int a[s.length()];
	int q=0;
	for(int i = 0;i<s.length();i++){
		if(s[i]<=60){
			a[q]=int(s[i])-48;
//			cout<<a[q]<<" ";
			q++;
		}
	}
	sort(a,a+q);
	for(int i = q-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 

