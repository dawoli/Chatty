#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int N = 1e6+10;
int n,m,c;
int a[N],cnt[N],color[N],ans,o;
int cc;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>n;
	while(n--){
		cc=0;
		o=0;
		memset(cnt, 0 ,sizeof cnt);
		ans=0;
		memset(a, 0 ,sizeof a);
		memset(color, 0 ,sizeof color);
			cin>>m;
			for(int i=1;i <= m;i ++){
				cin>>a[i];
	 			cnt[a[i]]++;
				if(cnt[a[i]]!=1)c=1;
			}
		if(!c){
		cout <<"0";
		continue;
	}
	for(int i=1;i <m-1;i++){
		cc+=1;
		cc%=2;
		for(int j=1;j<=m;j++){
			if(a[j]==a[j+i]){
				color[j]=color[j+1]=cc;
				o=1;
			}
		}
		if(!o){
			cc+=1;
			cc%=2;
		}
	}
	for(int i=1;i<=m;i++){
		if(color[i]){
			for(int j=i;j>=1;j--){
				if(color[j]==color[i]) {
					if(a[j]==a[i]){
						ans+=a[j];
					}
					break;
				}
			}
		}
	}
	cout <<ans;
	cout <<endl;
}

	return 0;
}
