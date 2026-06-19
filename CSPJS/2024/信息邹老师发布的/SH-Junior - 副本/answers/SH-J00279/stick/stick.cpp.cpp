#include<bits/stdc++.h>
using namespace std;
struct ads{
	int id;
	int num;
};
ads a[10];
int n;
bool cmp(ads a,ads b){
	if(a.num!=b.num ) return a.num>b.num;
	return a.id<b.id;
}
int t;
string s1;
string s2="";
void dfs(int k,int d){
	if(d==k){
		int num=0;
		for(int i=0;i<k;i++){
			num+=s1[i]-'0';
		} 
		if(s1<s2 && num==n && s1[0]!='0'){
			s2=s1;
		}
		return ;
		
	}
	for(int i=0;i<10;i++){
		s1[i]=('0'+a[i].id);
		dfs(k,d+1);
		s1[i]=0;
	}
}
int main(){
	for(int i=0;i<10;i++){
		a[i].id=i;
	}
	a[0].num=6;
	a[1].num=2;
	a[2].num=5;
	a[3].num=5;
	a[4].num=4;
	a[5].num=5;
	a[6].num=6;
	a[7].num=3;
	a[8].num=7;
	a[9].num=6;
	sort(a,a+10,cmp);
	cin>>t;
	while(t--){
		s1="";
		cin>>n;
		for(int i=0;i<=n;i++){
			s2+="7";
		}
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		int k=n/7;
		if(n%7!=0){
			k++;
		}
		dfs(k,0);
		cout<<s1<<endl;
	} 
	return 0;
}
