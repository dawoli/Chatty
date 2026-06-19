#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
string s;
int a[N],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
		cout<<a[i];		
	return 0;
} 
