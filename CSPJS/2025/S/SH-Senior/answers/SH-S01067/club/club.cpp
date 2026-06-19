#include<bits/stdc++.h>
using namespace std;
int n,t,a[100005][4][3];
struct she{
	int maxa,sum,id;
}s[100005];
bool cmp(she a,she b){
	if(a.maxa==b.maxa){
		return a.sum<=b.sum;
	}
	return a.maxa>b.maxa;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][1][2] >> a[i][2][2] >> a[i][3][2];
			a[i][1][1]=1,a[i][2][1]=2,a[i][3][1]=3;
			if(a[i][1][2]<a[i][2][2]) swap(a[i][1],a[i][2]);
			if(a[i][2][2]<a[i][3][2]) swap(a[i][2],a[i][3]);
			if(a[i][1][2]<a[i][2][2]) swap(a[i][1],a[i][2]);
			s[i].id=i;
			s[i].maxa=a[i][1][2];
			s[i].sum=a[i][1][2]+a[i][2][2]+a[i][3][2];
		}
//		for(int i=1;i<=n;i++){
//			cout << '(' << a[i][1][1] << ',' << a[i][1][2] << ')' << " " << '(' << a[i][2][1] << ',' << a[i][2][2] << ')' << " " << '(' << a[i][3][1] << ',' << a[i][3][2] << ')' << endl;
//		}
		sort(s+1,s+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			cout << s[i].id << " " << s[i].maxa <<" " << s[i].sum << endl;
//		}
		int fs[4]={0},ans=0,cnt=0;
		int she1,she2;
		for(int i=1;i<=3;i++){
			if(fs[a[s[1].id][i][1]]==n/2) continue;
			for(int j=1;j<=3;j++){
				if(fs[a[s[2].id][j][1]]==n/2 || (n==2 && i==j)) continue;
				if(a[s[1].id][i][2]+a[s[2].id][j][2]>cnt){
					cnt=a[s[1].id][i][2]+a[s[2].id][j][2];
					she1=a[s[1].id][i][1],she2=a[s[2].id][j][1];
				}
			}
		}
		ans+=cnt;
//		cout << ans << endl;
		fs[she1]++,fs[she2]++;
		for(int i=3;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(fs[a[s[i].id][j][1]]==n/2) continue;
				else{
					ans+=a[s[i].id][j][2];
					fs[a[s[i].id][j][1]]++;
					break;
				}
			}
		}
		cout << ans << endl;
	}
} 
