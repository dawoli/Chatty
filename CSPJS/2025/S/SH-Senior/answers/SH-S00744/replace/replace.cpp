#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,q,l1,l2,ans=0;string s[maxn][2],t[maxn][2];
int sp[maxn][2],tp[maxn][2];
int judge(int qq,int nn){
	int s1=s[nn][0].length();
	int s2=t[qq][0].length();
	int cnt=0;bool bj;
	if(s1>s2) return 0;
	for(int i=0;i<s2-s1+1;i++){
		bj=true;
		for(int j=0;j<s2;j++){
			if(i<=j&&j<i+s1){
				bj=bj&&s[nn][0][j-i]==t[qq][0][j];
				bj=bj&&s[nn][1][j-i]==t[qq][1][j];
				if(!bj) break;
			}
			else{
				bj=bj&&t[qq][0][j]==t[qq][1][j];
				if(!bj) break;
			}
		}
		cnt+=bj;
	}
	return cnt;
}
int judge2(int qq,int nn){
	bool bj=true;
	int s1=s[nn][0].length();
	int s2=t[qq][0].length();
	bj=bj&&(tp[qq][1]-tp[qq][0]==sp[nn][1]-sp[nn][0]);
	bj=bj&&(sp[nn][0]<=tp[qq][0]);
	bj=bj&&(s1-sp[nn][0]<=s2-tp[qq][0]);
	return bj;
}
int place(string ss){
	for(int i=0;i<ss.length();i++){
		if(ss[i]=='b') return i;
	}
}
void solveBF(){
	for(int i=0;i<q;i++){
		ans=0;
		if(t[i][0].length()!=t[i][1].length()){
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<n;j++){
			ans+=judge(i,j);
		}
		cout<<ans<<endl;
	}
}
void solveA(){
	for(int i=0;i<n;i++){
		sp[i][0]=place(s[i][0]);
		sp[i][1]=place(s[i][1]);
	}
	for(int i=0;i<q;i++){
		tp[i][0]=place(t[i][0]);
		tp[i][1]=place(t[i][1]);
	}
	for(int i=0;i<q;i++){
		ans=0;
		if(t[i][0].length()!=t[i][1].length()){
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<n;j++){
			ans+=judge2(i,j);
		}
		cout<<ans<<endl;
	}
} 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
		l1+=s[i][0].length()+s[i][1].length();
	}
	for(int i=0;i<q;i++){
		cin>>t[i][0]>>t[i][1];
		l2+=t[i][0].length()+t[i][1].length();
	}
	if(l1<=2000&&l2<=2000) solveBF();
	else solveA();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
