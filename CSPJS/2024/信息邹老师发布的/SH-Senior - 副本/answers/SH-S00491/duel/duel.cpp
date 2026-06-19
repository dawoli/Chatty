#include<bits/stdc++.h>
#define N 100009
using namespace std;

inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+(ch-'0');
		ch=getchar();
	}
	return s*w;
}

int n,r[N];
bool ok[N];

bool isConditionR2(){
	for(int i=1;i<=n;i++)
		if(r[i]>2)
			return false;
	return true;
}

void solveR2(){
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		if(r[i]==1) cnt1++;
		else cnt2++;
	}
	int ans=max(cnt1-cnt2,0)+cnt2;
	cout<<ans<<endl;
}
void solve(){
	int ans=n,p=0;
	bool flag=false;
	sort(r+1,r+n+1);
//	for(int i=1;i<=n+10;i++)
//		cout<<r[i]<<" ";
//	cout<<endl;
	for(int i=1;i<=n;i++){
		flag=false;
		for(;p<=n;p++)
			if(!ok[p]&&r[p]>r[i]){
				flag=true;
				break;
			}
		if(flag==false)
			continue;
		ok[p]=true;
		ans--;
	}
	cout<<ans<<endl;
}

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		r[i]=read();
	if(isConditionR2()) solveR2();
	else solve();
	return 0;
}
