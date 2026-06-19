#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
string s;
const int MAXN=1e6+5;
short n[MAXN];
int tmp=1;
bool cmp(int a,int b){
	if(a>=b)
		return 1;
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	cout<<s;
	int b=s.size(); 
	for(int i=0;i<b;i++){
		if((s[i]>='0')&&(s[i]<='9')){
			n[tmp]=s[i]-48;
			tmp++;
		}
	}
	sort(n+1,n+tmp,cmp);
	for(int i=1;i<tmp;i++)
		printf("%d",n[i]);
	return 0;
}
