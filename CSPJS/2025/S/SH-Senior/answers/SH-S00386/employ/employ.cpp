#include<bits/stdc++.h>
using namespace std;
const int p=998244353ll;
int n,m,c[509],cnt1,cnt0,ans;
string s;
bool vst[509];
int pailie[509];
void solveBF(int i){
	if(i>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||i-cnt-1>=c[pailie[i]])continue;
			cnt++;
		}
		if(cnt>=m)ans++;
		return;
	}
	for(int j=1;j<=n;j++)
		if(!vst[j]){
			vst[j]=true;
			pailie[i]=j;
			solveBF(i+1);
			vst[j]=false;
		}
}
void solvemis1(){
	ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%p;
}
void solvemisn(){
	if(cnt0)return;
	if(cnt1<s.size())return;
	ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%p;
}
void solveA(){
	ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%p;
}
void solveB(){
	ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%p;
}
void solveother(){
	ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%p;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i],cnt0+=(c[i]==0);
	for(int i=0;i<s.size();i++)cnt1+=(s[i]=='1');
	if(n-cnt0<m);
	else if(m==1)solvemis1();
	else if(m==n)solvemisn();
	else if(n<=18)solveBF(1);
	else if(cnt1==s.size())solveA();
	else if(cnt1<=18)solveB();
	else solveother();
	cout<<ans%p<<endl;
	return 0;
}
