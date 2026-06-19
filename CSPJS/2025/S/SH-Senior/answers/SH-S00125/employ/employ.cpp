#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,c[500],ans=0;
bool book[500];
void dfsa(int re,int ac,int day){
	if(day==n+1){
		if(ac>=m) ans++;
		//printf("find a way to accept%d\n",ac);
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(book[i]) continue;
		book[i]=1;
		if(re>=c[i]){
			//printf("day%d,refuse%d,accept%d\n",day,re,ac);
			dfsa(re+1,ac,day+1);
			
		}
		else{
			if(s[day-1]=='1'){
				//printf("day%d,refuse%d,accept%d\n",day,re,ac);
				dfsa(re,ac+1,day+1);
			}
			else{
				//printf("day%d,refuse%d,accept%d\n",day,re,ac);
				dfsa(re+1,ac,day+1);
				
			}
		}
		book[i]=0;
	}
	
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	
	dfsa(0,0,1);
		
	cout<<ans%998244353;
}
