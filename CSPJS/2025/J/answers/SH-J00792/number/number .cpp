#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int cnt=1;
int b[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			b[cnt++]=0;
		}
		else if(s[i]=='1'){
			b[cnt++]=1;
		}
		else if(s[i]=='2'){
			b[cnt++]=2;
		}
		else if(s[i]=='3'){
			b[cnt++]=3;
		}
		else if(s[i]=='4'){
			b[cnt++]=4;
		}
		else if(s[i]=='5'){
			b[cnt++]=5;
		}
		else if(s[i]=='6'){
			b[cnt++]=6;
		}
		else if(s[i]=='7'){
			b[cnt++]=7;
		}
		else if(s[i]=='8'){
			b[cnt++]=8;
		}
		else if(s[i]=='9'){
			b[cnt++]=9;
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<b[i];
	}
	return 0;
} 
