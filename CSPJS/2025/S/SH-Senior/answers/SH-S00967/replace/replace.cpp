#include<bits/stdc++.h>
using namespace std;
struct x{
	int left1,left2,right1,right2,mov; 
}s[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s_a,s_b;
		cin>>s_a>>s_b;
		int a=-1,b=-1;
		for(int j=0;j<s_a.length();j++){
			if(s_a[j]=='b')a=j;
			if(s_b[j]=='b')b=j;
			if(a>=0&&b>=0)break;
		}
		s[i].left1=a;s[i].left2=b;
		s[i].right1=s_a.length()-a-1;
		s[i].right2=s_a.length()-b-1;
		s[i].mov=a-b;
	} 
	for(int i=1;i<=q;i++){
		int cnt=0;
		string t_a,t_b;
		cin>>t_a>>t_b;
		int a=-1,b=-1;
		for(int j=0;j<t_a.length();j++){
			if(t_a[j]=='b')a=j;
			if(t_b[j]=='b')b=j;
			if(a>=0&&b>=0)break;
		}
		int mov1=a-b;
		for(int j=1;j<=n;j++){
			if(s[j].left1<=a&&s[j].left2<=b&&s[j].right1<=t_a.length()-a-1&&s[j].right2<=t_a.length()-b-1&&s[j].mov==mov1){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	} 
	return 0;
}
