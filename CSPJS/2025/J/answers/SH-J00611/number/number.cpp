#include<bits/stdc++.h>
using namespace std;
string str;
char c[1000010];
int k=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for (int i=0;i<str.size();i++){
		c[i]=str[i];
	}sort(c,c+str.size());
	while(c[k]<58 && k<str.size()){
		k++;
	}
	for (int i=k-1;i>-1;i--){
		cout<<c[i];
	}return 0;
} 
