#include <bits/stdc++.h>
using namespace std;
int a[100050][5],b[100050],s[10],c[100050];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n,ans=0,m;
		s[1]=0;s[2]=0;s[3]=0;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			m=max(max(a[i][1],a[i][2]),a[i][3]);
			ans+=m;
			for(int j=1;j<=3;j++){
				if(a[i][j]==m){
					b[i]=j;
					s[j]++;
					break;
				}
			}
		}
		int t=-1,tc=0;
		for(int i=1;i<=3;i++){
			if(s[i]>n/2){
				t=i;
			}
		}
		if(t!=-1){
			for(int i=0;i<n;i++){
				if(b[i]==t){
					if(t==1){
						c[tc]=a[i][1]-max(a[i][2],a[i][3]);
					}else if(t==2){
						c[tc]=a[i][2]-max(a[i][1],a[i][3]);
					}else{
						c[tc]=a[i][3]-max(a[i][1],a[i][2]);
					}
					tc++;
				}
			}
			//cout << "tc" << tc << endl;
			//cout << "s" << s[1] << ' ' << s[2] << ' ' << s[3] << ' ' << endl;
			sort(c,c+tc);
			for(int i=0;i<s[t]-n/2;i++){
				ans-=c[i];
				//cout << "c" << c[i] << endl;
			} 
		}
		cout << ans << endl;
	}
	return 0;
}
