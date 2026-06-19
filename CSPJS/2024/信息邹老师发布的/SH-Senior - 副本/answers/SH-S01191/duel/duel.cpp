#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
int n,a[MAXN],ans,cnt[MAXN],tot[MAXN];
bool flag1[MAXN];//flag1是存活，flag2是能力 

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tot[a[i]]++;
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)	cout<<a[i]<<" ";
	for(int i=1;i<=n;i++){
		if(flag1[i]==0){
			int tmp=upper_bound(a+1,a+n+1,a[i])-a;
			if(tmp==n+1)	continue;
			while(cnt[a[tmp]]==tot[a[tmp]]&&cnt[a[tmp]]!=0){
				tmp+=cnt[a[tmp]];
			}
			tmp+=cnt[a[tmp]];
	//		cout<<tmp<<endl;
			if(tmp!=n+1){
				flag1[i]=1;
				cnt[a[tmp]]++;			
			}
		}
		else	continue; 
	}
	for(int i=1;i<=n;i++){
		if(flag1[i]==0)	ans++;
	}
	cout<<ans<<endl;
	return 0;
}
