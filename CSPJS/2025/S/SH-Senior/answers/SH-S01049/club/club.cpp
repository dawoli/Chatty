#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,inf=1e12+10;
int T,n;
struct{
	int d1,d2,d3,cha;
}a[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		int sum=0,cnt1=0,cnt2=0,cnt3=0,chamin1[N],chamin2[N],chamin3[N],chai1=1,chai2=1,chai3=1;
		memset(chamin1,0x7f,sizeof(chamin1));
		memset(chamin2,0x7f,sizeof(chamin2));
		memset(chamin3,0x7f,sizeof(chamin3));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			//cout<<abs(a[i].d3-a[i].d1)<<" ";
		}
		for(int i=1;i<=n;i++){
			//cout<<sum<<"/";
			if(a[i].d1>=a[i].d2&&a[i].d1>=a[i].d3){
				a[i].cha=min(abs(a[i].d1-a[i].d2),abs(a[i].d1-a[i].d3));
				chamin1[chai1]=a[i].cha;
				chai1++;
				sum+=a[i].d1;
				if(cnt1<n/2){
					cnt1++;
				}else{
					sort(chamin1+1,chamin1+chai1+1);//wr?
					sum-=chamin1[1];
					chamin1[1]=inf;
					//sort(chamin1+1,chamin1+chai1);
				}
			}else if(a[i].d2>=a[i].d1&&a[i].d2>=a[i].d3){
				a[i].cha=min(abs(a[i].d2-a[i].d1),abs(a[i].d2-a[i].d3));
				chamin2[chai2]=a[i].cha;
				chai2++;
				sum+=a[i].d2;
				if(cnt2<n/2){
					cnt2++;
				}else{
					sort(chamin2+1,chamin2+chai2+1);//wr?
					sum-=chamin2[1];
					chamin2[1]=inf;
					//sort(chamin2+1,chamin2+chai2);
				}
			}else if(a[i].d3>=a[i].d2&&a[i].d3>=a[i].d1){
				a[i].cha=min(abs(a[i].d3-a[i].d1),abs(a[i].d3-a[i].d2));
				//cout<<abs(a[i].d3-a[i].d1);
				chamin3[chai3]=a[i].cha;
				chai3++;
				//cout<<"*"<<chamin3[chai3-1]<<"*";
				sum+=a[i].d3;
				if(cnt3<n/2){
					cnt3++;
				}else{
					
					sort(chamin3+1,chamin3+chai3+1);//wr?
					sum-=chamin3[1];
					chamin3[1]=inf;
					//sort(chamin3+1,chamin3+chai3);
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


比亚迪T1
调了我 90min 


74行达芬代码这一块 
*/
