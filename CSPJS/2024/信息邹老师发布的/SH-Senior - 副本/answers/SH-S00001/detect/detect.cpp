#include <iostream>
using namespace std;
bool flag;
bool sats[100005];
int t,n,m,l,vmx,cnt,mx,ans,curdet;
int p[100005],d[100005],v[100005],a[100005],ints[100005][2],det[100005];

//for the array ints, the first number, it represents that the car
//will start overspeeding at that interval
//for the 2nd number, it represents that the car will end overspeeding at
//that interval
//if any of the numbers are negative, that means the car will never overspeed

void cal(int cn){ //determine where the car will be over-speed, cn is car-num
	if(v[cn]<vmx and a[cn]<=0){
		ints[cn][0]=-1;
		ints[cn][1]=-1;
	}
	if(v[cn]<vmx and a[cn]>0){
		ints[cn][0]=(vmx*vmx-v[cn]*v[cn])/(2*a[cn]);
		ints[cn][1]=l;
	}
	if(v[cn]>=vmx){
		ints[cn][0]=d[cn];
		if(a[cn]>=0){
			ints[cn][1]=l;
		}
		else{
			ints[cn][1]=(vmx*vmx-v[cn]*v[cn])/(2*a[cn]);
		}
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int z=0;z<t;z++){
		cin>>n>>m>>l>>vmx;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&p[i]);
		}
		if(n<21 and m<21){
			for(int i=0;i<n;i++){
				cal(i); 
			}
			for(int i=0;i<n;i++){
				flag=0;
				for(int j=0;j<m;j++){
					if(p[j]>=ints[i][0] and p[j]<=ints[i][1] and flag==0){
						det[cnt]=i;
						cnt++;
						flag=1;
					}
				}
			}
			cout<<cnt<<" ";
			for(int i=1;i<(1<<m);i++){
				while(curdet!=m){
					 if(i%2==1){
					 	for(int j=0;j<cnt;j++){
					 		if(ints[det[j]][0]<p[curdet] and p[curdet]<ints[det[j]][1] and sats[j]!=1){
					 			sats[j]=1;
					 			ans++;
							 }
						 }
					 }
					 curdet++;
					 i/=2;
				}
				curdet=0;
				if(mx<ans) mx=ans;
				ans=0;
			}
			cout<<mx<<endl;
			for(int i=0;i<100003;i++){
				sats[i]=0;
			}
		}
		else if(n>20 or m>20){
//			if(a[0]>0)
//			if(a[0]<0)
			if(a[0]==0){
				for(int i=0;i<m;i++){
					if(mx<p[i]) mx=p[i];
				}
				for(int i=0;i<n;i++){
					if(d[i]<mx) cnt++; 
				}
				cout<<cnt<<" "<<1<<endl;
			}
		}
		
		flag=0;
		cnt=0;
		mx=0;
	}
	return 0;
}
