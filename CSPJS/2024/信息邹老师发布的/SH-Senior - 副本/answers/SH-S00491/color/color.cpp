#include<bits/stdc++.h>
#define N 200009
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+(ch-'0');
		ch=getchar();
	}
	return s*w;
}
int LSB(int num){
	return num&(-num);
}

int T;
int n,a[N];
bool col[N];

int score(int state){
	for(int i=1;i<=n;i++)
		col[i]=false;
	for(int i=1;i<=n;i++){
		if(state%2==1)
			col[i]=true;
		state>>=1;
	}
	int p=0,ans=0;
	bool flag;
	for(int i=1;i<=n;i++){
		flag=false;
		for(p=i-1;p>=1;p--)
			if(col[p]==col[i]){
				flag=true;
				break;
			}
		if(flag==false)
			continue;
		if(a[i]==a[p])
			ans+=a[i];
	}
	return ans;
}

void solveN15(){
	int nBF=(1<<(n+1))-1;
	int ans=0;
	for(int i=0;i<=nBF;i++){
		ans=max(ans,score(i));
	}
	cout<<ans<<endl;
}
void solve(){
	cout<<"0"<<endl;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
		//数据分流
		if(n<=15)
			solveN15();
		else
			solve();
	}
	return 0;
}
