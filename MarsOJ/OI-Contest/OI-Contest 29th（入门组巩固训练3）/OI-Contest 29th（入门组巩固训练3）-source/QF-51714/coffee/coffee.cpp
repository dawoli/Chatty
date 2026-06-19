#include<bits/stdc++.h>
using namespace std;
int T,n,m,cnt[5];
string s[10][10];
int main()
{
	freopen("coffee.in",r,stdin);
	freopen("coffee.out",w,stdout);
	cin>>T;
	while(T--){
		cnt[1]=cnt[2]=cnt[3]=cnt[4]=cnt[5]=0;
		for(int i=1;i<=5;i++){
			for(int j=1;j<=8;j++){
				cin>>s[i][j];
				if(s[i][j]=="math")cnt[i]++;
			}
		}
		cin>>n>>m;
		if(n%7==0){
			int week=n/7;
			cout<<(cnt[1]+cnt[2]+cnt[3]+cnt[4]+cnt[5])*week<<endl;
			continue;
		}
		if(cnt[1]==cnt[2]&&cnt[3]==cnt[2]&&cnt[3]==cnt[4]&&cnt[4]==cnt[5]){
			if(m==6||m==7)n=n+m-8;
			int wd=(n-n%7)/7*5+n%7;
			if(n%7==6)wd--;
			cout<<cnt[1]*wd<<endl;
			continue;
		}
	}
	return 0;
}
