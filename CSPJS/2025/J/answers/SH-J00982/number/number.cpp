#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int a[maxn],cnt=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt++]=s[i]-'0';
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
} 
