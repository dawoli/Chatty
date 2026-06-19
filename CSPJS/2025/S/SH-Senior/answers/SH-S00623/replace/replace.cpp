#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+7;
long long n,q;
string s[N][3],as[N][3],t1,t2,at1,at2;
long long rs[N],re[N];
bool isB=1;
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		as[i][1]="",as[i][2]="";
		long long sl=s[i][1].size();
		rs[i]=2e9,re[i]=0;
		for(long long j=0;j<sl;j++){
			if(s[i][1][j]!=s[i][2][j]){
				rs[i]=min(rs[i],j);
				re[i]=j;
			}
		}
		for(long long j=rs[i];j<=re[i];j++){
			as[i][1]=as[i][1]+s[i][1][j];
			as[i][2]=as[i][2]+s[i][2][j];
		}
	}
	while(q--){
		long long ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		at1="",at2="";
		long long sl=t1.size(),st=2e9,en=0;
		for(long long j=0;j<sl;j++){
			if(t1[j]!=t2[j]){
				st=min(st,j);
				en=j;
			}
		}
		for(long long j=st;j<=en;j++){
			at1=at1+t1[j];
			at2=at2+t2[j];
		}
		for(long long i=1;i<=n;i++){
			if(as[i][1]!=at1||as[i][2]!=at2) continue;
			long long flag=1;
			long long posa=st-1,posb=rs[i]-1;
			while(posa>=0&&posb>=0&&s[i][1][posb]==t1[posa]) posa--,posb--;
//			cout<<posa<<" "<<posb<<endl;
			if(posb>=0) flag=0;
			posa=en+1,posb=re[i]+1;
			long long ssl=s[i][1].size();
			while(posa<sl&&posb<ssl&&s[i][1][posb]==t1[posa]) posa++,posb++;
//			cout<<posa<<" "<<posb<<endl;
			if(posb<ssl) flag=0;
			if(flag){
//				cout<<s[i][1]<<" "<<s[i][2]<<endl;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
//I've already found an AC solution, but there isn't enough space to write it down.
//If I don't know how to solve T4, I'll come back to make it better.
//Now, 50pts.

//I failed. I spent 30min to write a Trie, but it 3221225477-ed.
