#include<bits/stdc++.h> 
using namespace std;
char s[1000010];
int num[1000010];
int l,cnt;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<1000010;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[cnt]=int(s[i]-'0');
			cnt++;
		}
	}
	sort(num,num+cnt+1,cmp);
	for(int i=0;i<cnt;i++) cout<<num[i];
	return 0;
}
