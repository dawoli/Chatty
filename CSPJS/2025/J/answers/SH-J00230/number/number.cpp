#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],len,cnt=1;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){ 
		if('0'<=s[i]&&'9'>=s[i]){
			int x=s[i]-'0'; 
			a[cnt++]=x;
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt-1;i++){
		cout<<a[i];
	}
} 

