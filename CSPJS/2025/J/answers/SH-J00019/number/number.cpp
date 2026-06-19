#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100009;
int d;
int a[N];
string s;
int sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	    if(s[i]>='0'&&s[i]<='9') a[++d]=s[i]-'0';
    sort(a+1,a+d+1);
    for(int i=d;i>=1;i--)
        cout<<a[i];
	cout<<endl;
	return 0;
} 
