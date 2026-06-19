#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int LEN=1e6;
char s[LEN+1];
int i;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr); 
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	cin>>s;
	sort(s,s+strlen(s),cmp);
	while(s[i]<'0'||s[i]>'9')i++;
	cout<<s+i;
	return 0;
} 
