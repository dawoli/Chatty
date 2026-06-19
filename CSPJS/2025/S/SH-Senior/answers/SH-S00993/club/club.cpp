#include<bits/stdc++.h>
using namespace std;

int n,T;
int arr[100005][4],tol[100005],yx[100005],chs1[100005],chs2[100005],chs3[100005],cnt1=0,cnt2=0,cnt3=0,ans=0;

inline int mymax(int a,int b,int c){
	return max(max(a,b),c);
}
inline int mymin(int a,int b,int c){
	return min(min(a,b),c);
}
inline int mymid(int a,int b,int c){
	return a+b+c-mymax(a,b,c)-mymin(a,b,c);
}
inline int cs(int j){
	if(arr[j][1]==mymax(arr[j][1],arr[j][2],arr[j][3])){
		return 1;
	}
	if(arr[j][2]==mymax(arr[j][1],arr[j][2],arr[j][3])){
		return 2;
	}
	if(arr[j][3]==mymax(arr[j][1],arr[j][2],arr[j][3])){
		return 3;
	}
	return 1;
}
bool cmp(int a,int b){
	return tol[a]<tol[b];
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cnt1=cnt2=cnt3=ans=0;
		for(int i=1;i<=n;i++){
			arr[i][1]=arr[i][2]=arr[i][3]=0;
			tol[i]=yx[i]=chs1[i]=chs2[i]=chs3[i]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
			tol[i]=mymax(arr[i][1],arr[i][2],arr[i][3])-mymid(arr[i][1],arr[i][2],arr[i][3]);
			yx[i]=cs(i);
			ans+=arr[i][yx[i]];
		}
		for(int i=1;i<=n;i++){
			if(yx[i]==1){
				chs1[++cnt1]=i;
			}
			if(yx[i]==2){
				chs2[++cnt2]=i;
			}
			if(yx[i]==3){
				chs3[++cnt3]=i;
			}
		}
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			cout<<ans<<'\n';
			continue;
		}else{
			if(cnt1>n/2){
				sort(chs1+1,chs1+1+cnt1,cmp);
				for(int k=1;k<=cnt1-(n/2);k++){
					ans-=tol[chs1[k]];
				}
			}
			if(cnt2>n/2){
				sort(chs2+1,chs2+1+cnt2,cmp);
				for(int k=1;k<=cnt2-(n/2);k++){
					ans-=tol[chs2[k]];
				}
			}
			if(cnt3>n/2){
				sort(chs3+1,chs3+1+cnt3,cmp);
				for(int k=1;k<=cnt3-(n/2);k++){
					ans-=tol[chs3[k]];
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}

