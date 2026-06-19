#include<bits/stdc++.h>

using namespace std;
string str;
int a[1000007];
int cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	int len=str.size();
	for(int i=0;i<len;i++){
		if(isdigit(str[i])){
			a[++cnt]=(int)(str[i]-48);
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
} 
