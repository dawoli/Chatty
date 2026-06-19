#include<bits/stdc++.h>
using namespace std;

int a[]={6,2,5,5,4,5,6,3,7,6};
int b[]={0,0,1,7,4,2,6,8};
int c[]={0,0,1,7,4,2,0,8};
struct nm{
	string s;
	int len;
	bool operator <(const nm &b) const{
		if(len!=b.len) return len<b.len;
		for(int i=0;i<len;++i){
			if(s[i]!=b.s[i]) return s[i]<b.s[i];
		}
	} 
};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n==1){
			cout<<-1<<'\n';
			continue;
		}
		if(n%7==0){
			for(int i=1;i<=n/7;++i){
				cout<<'8';
			}
			cout<<'\n';
			continue;
		} 
		nm q8;//全8
		q8.len=0;
		q8.s=""; 
		if(n%7==1) q8.len=2000000000;
		int s8=n/7;
		if(n%7!=0) q8.s.push_back(b[n%7]+'0'),q8.len++;
		for(int i=1;i<=s8;++i){
			q8.s.push_back('8'),q8.len++;
		}
		nm b8;//最后是8
		b8.len=0;
		b8.s="";
		int sb8=n/7-1;
		int tmp=n-sb8*7;
		if(tmp<=9){
			b8.s.push_back('1');
			b8.s.push_back(c[tmp-2]+'0');
			b8.len+=2; 
		}
		else if(tmp<=12){
			b8.s.push_back('2');
			b8.s.push_back(c[tmp-5]+'0');
			b8.len+=2;
		}
		else{
			b8.s.push_back('6');
			b8.s.push_back(c[tmp-6]+'0');
			b8.len+=2;
		}
		for(int i=1;i<=sb8;++i){
			b8.s.push_back('8'),b8.len++;
		}
		if(b8<q8){
			cout<<b8.s<<'\n';
		}
		else{
			cout<<q8.s<<'\n';
		}
	}
	return 0;
} 
