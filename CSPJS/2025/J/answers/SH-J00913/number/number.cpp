#include<bits/stdc++.h>
using namespace std;
string s;
int k[1000005];
int sk;
bool r(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			k[sk]=int(s[i]-'0');
			sk++;
		}
	}
	sort(k,k+sk,r);
	for(int i=0;i<sk;i++)cout<<k[i];
	return 0;
} 
