#include<bits/stdc++.h>
#define CSPAK return 0;
#define ll long long
#define WLF LieQi
using namespace std;
int fc[100009];
struct member{
	int a1,a2,a3,max,max2,m,m2,fn;
}cy[100009];
bool cmp(member a,member b){
	if(a.max==b.max) return (a.max2>b.max2);
	return (a.max>b.max);
}
int solve(){
	int n,tmp1=0,tmp2=0,tmp3=0,tmp=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cy[i].a1>>cy[i].a2>>cy[i].a3;
		cy[i].max=max(cy[i].a1,max(cy[i].a2,cy[i].a3));
		if(cy[i].max==cy[i].a1){
			cy[i].m=1;
			if(cy[i].a2>cy[i].a3){
				cy[i].m2=2;
				cy[i].max2=cy[i].a2;}
			else {
				cy[i].m2=3;
				cy[i].max2=cy[i].a3;}
		}
		else if(cy[i].max==cy[i].a2){
			cy[i].m=2;
			if(cy[i].a1>cy[i].a3){
				cy[i].m2=1;
				cy[i].max2=cy[i].a1;}
			else {
				cy[i].m2=3;
				cy[i].max2=cy[i].a3;}
		}
		else if(cy[i].max==cy[i].a3){
			cy[i].m=3;
			if(cy[i].a2>cy[i].a1){
				cy[i].m2=2;
				cy[i].max2=cy[i].a2;}
			else {
				cy[i].m2=1;
				cy[i].max2=cy[i].a1;}
		}
	}
	sort(cy+1,cy+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(cy[i].m==1&&tmp1<n/2){
			tmp1++;
			fc[i]=cy[i].max;
			cy[i].fn=1;
		}
		else if(cy[i].m==2&&tmp2<n/2){
			tmp2++;
			fc[i]=cy[i].max;
			cy[i].fn=2;
		}
		else if(cy[i].m==3&&tmp3<n/2){
			tmp3++;
			fc[i]=cy[i].max;
			cy[i].fn=3;
		}
		
		else{
			fc[i]=cy[i].max2;
			if(cy[i].m2=1&&tmp1<n/2){
				tmp1++;
				cy[i].fn=1;
			}
			if(cy[i].m2=2&&tmp2<n/2){
				tmp2++;
				cy[i].fn=2;
			}
			if(cy[i].m2=3&&tmp3<n/2){
				tmp3++;
				cy[i].fn=3;
			}
		}
	}
	if(n<=1000){
		for(int i=2;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(fc[i]+fc[j]<cy[i].max+cy[j].max&&tmp1<n/2&&tmp2<n/2&&tmp3<n/2){
					fc[i]=cy[i].max;
					fc[j]=cy[j].max;
				}
				if(fc[i]+fc[j]<cy[i].max2+cy[j].max&&tmp1<n/2&&tmp2<n/2&&tmp3<n/2){
					fc[i]=cy[i].max2;
					fc[j]=cy[j].max;
				}
				if(fc[i]+fc[j]<cy[i].max+cy[j].max2&&tmp1<n/2&&tmp2<n/2&&tmp3<n/2){
					fc[i]=cy[i].max;
					fc[j]=cy[j].max2;
				}
				if(fc[i]+fc[j]<cy[i].max2+cy[j].max2&&tmp1<n/2&&tmp2<n/2&&tmp3<n/2){
					fc[i]=cy[i].max2;
					fc[j]=cy[j].max2;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) tmp+=fc[i];
	return tmp;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)	cout<<solve()<<endl;
	CSPAK
}
