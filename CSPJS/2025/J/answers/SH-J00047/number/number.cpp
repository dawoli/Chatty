#include<iostream>
#include<algorithm>
using namespace std;
int a[1000010],n=0;
bool cmp(int x,int y){
	return x>y;
}
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
		a[++n]=s[i]-'0';
			
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	fclose(stdin);fclose(stdout);
}
