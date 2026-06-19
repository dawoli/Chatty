#include<bits\stdc++.h>
using namespace std;
char s[100010],a[100010];
int num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;++i){
		if(s[i]>='0'&&s[i]<='9'){
			a[num]=s[i];
			num++;
		}
	}
	for(int i=0;i<=len+1;++i){
		if(a[i]=='9')
			cout<<a[i];
		}
	for(int i=0;i<=len+1;++i){
		if(a[i]=='8')
			cout<<a[i];
		}
	for(int i=0;i<=len+1;++i){
		if(a[i]=='7')
			cout<<a[i];
		}
	for(int i=0;i<=len+1;++i){
		if(a[i]=='6')
			cout<<a[i];
		}
	for(int i=0;i<=len+1;++i){
		if(a[i]=='5')
			cout<<a[i];
		}
	for(int i=0;i<=len+1;++i){
		if(a[i]=='4')
			cout<<a[i];
		}
	for(int i=0;i<=len+1;++i){
		if(a[i]=='3')
			cout<<a[i];
		}
	for(int i=0;i<=len+1;++i){
		if(a[i]=='2')
			cout<<a[i];
		}
	for(int i=0;i<=len+1;++i){
		if(a[i]=='1')
			cout<<a[i];
		}
	for(int i=0;i<=len+1;++i){
		if(a[i]=='0')
			cout<<a[i];
		}
	return 0;
} 
