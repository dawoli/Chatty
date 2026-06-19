#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000002],cnt=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(long long i=1;i<=cnt;i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
} 
