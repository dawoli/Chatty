#include<bits/stdc++.h>
using namespace std;
int v[10];
bool cmp(int a,int b){
	return a>b;
}
int s=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string st;
	cin>>st;
	for(int i=0;i<st.length();i++){
		char a=st[i];
		if('0'<=a&&a<='9'){
			v[a-'0']++;
			s++; 
		}
	}
	for(int i=9;i>=0;i--)
		for(int j=1;j<=v[i];j++)
			cout<<i;
	cout<<endl;
	return 0;
} 
