#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
int cnt[123];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')cnt[0]++;
		if(s[i]=='1')cnt[1]++;
		if(s[i]=='2')cnt[2]++;
		if(s[i]=='3')cnt[3]++;
		if(s[i]=='4')cnt[4]++;
		if(s[i]=='5')cnt[5]++;
		if(s[i]=='6')cnt[6]++;
		if(s[i]=='7')cnt[7]++;
		if(s[i]=='8')cnt[8]++;
		if(s[i]=='9')cnt[9]++;
	}
	for(int i=1;i<=cnt[9];i++)cout<<'9';
	for(int i=1;i<=cnt[8];i++)cout<<'8';
	for(int i=1;i<=cnt[7];i++)cout<<'7';
	for(int i=1;i<=cnt[6];i++)cout<<'6';
	for(int i=1;i<=cnt[5];i++)cout<<'5';
	for(int i=1;i<=cnt[4];i++)cout<<'4';
	for(int i=1;i<=cnt[3];i++)cout<<'3';
	for(int i=1;i<=cnt[2];i++)cout<<'2';
	for(int i=1;i<=cnt[1];i++)cout<<'1';
	for(int i=1;i<=cnt[0];i++)cout<<'0';
	return 0;
}
