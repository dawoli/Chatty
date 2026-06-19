#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200005],b[200005],c[200005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//  /7............................(/
	//  ./7..........................(/.
	//  ../7........................(/..
	//  .../7......................(/...
	//  ..../7....................(/....
	//	...../7..................(/.....
	//	....../7................(/......
	//	......./7..............(/.......
	//	......../7............(/........
	//	........./7..........(/.........
	//	........../7........(/..........
	//	.........../7......(/...........
	//	............/7....(/............
	//	............./7..(/.............
	//	..............|()|..............
	//	............./(../7.............
	//	............/(..../7............
	//	.........../(....../7...........
	//	........../(......../7..........
	//	........./(........../7.........
	//	......../(............/7........
	//	......./(............../7.......
	//	....../(................/7......
	//	...../(................../7.....
	//	..../(..................../7....
	//	.../(....................../7...
	//	../(......................../7..
	//	./(........................../7.
	//  /(............................/7
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		if(n==2){
			cin>>a[1]>>b[1]>>c[1];
			cin>>a[2]>>b[2]>>c[2];
			cout<<max(a[1]+b[2],max(a[1]+c[2],max(a[2]+b[1],max(a[2]+c[1],max(b[2]+c[1],b[1]+c[2])))))<<endl;
		}
		else if(n==4){
			cin>>a[1]>>b[1]>>c[1];
			cin>>a[2]>>b[2]>>c[2];
			cin>>a[3]>>b[3]>>c[3];
			cin>>a[4]>>b[4]>>c[4];
			cout<<max(a[1]+a[2]+b[3]+b[4],max(a[1]+a[2]+c[3]+c[4],max(a[1]+a[2]+b[3]+c[4],max(a[1]+a[2]+c[3]+b[4],max(a[1]+b[2]+a[3]+c[4],
			max(a[1]+b[2]+c[3]+c[4],max(a[1]+b[2]+c[3]+a[4],max(a[1]+b[2]+b[3]+a[4],
			max(a[1]+b[2]+a[3]+b[4],max(a[1]+b[2]+b[3]+c[4],max(b[1]+b[2]+a[3]+c[4],
			max(b[1]+b[2]+c[3]+c[4],max(b[1]+b[2]+c[3]+a[4],max(b[1]+c[2]+b[3]+c[4],
			max(b[1]+c[2]+c[3]+b[4],max(b[1]+c[2]+a[3]+b[4],
			max(b[1]+c[2]+b[3]+a[4],max(b[1]+c[2]+c[3]+a[4],max(b[1]+c[2]+a[3]+c[4],
			max(b[1]+c[2]+a[3]+a[4],max(c[1]+c[2]+b[3]+a[4],
			max(c[1]+c[2]+a[3]+b[4],max(c[1]+c[2]+a[3]+a[4],max(c[1]+c[2]+b[3]+b[4],
			max(c[1]+a[2]+c[3]+a[4],max(c[1]+a[2]+a[3]+c[4],
			max(c[1]+a[2]+b[3]+c[4],max(c[1]+a[2]+b[3]+b[4],max(c[1]+a[2]+b[3]+a[4],
			max(c[1]+a[2]+c[3]+b[4],max(c[1]+a[2]+a[3]+b[4],
			max(c[1]+b[2]+c[3]+a[4],max(c[1]+b[2]+a[3]+c[4],max(c[1]+b[2]+b[3]+c[4],
			max(c[1]+b[2]+a[3]+a[4],max(c[1]+b[2]+b[3]+a[4],max(c[1]+b[2]+c[3]+b[4],
			max(c[1]+b[2]+a[3]+b[4],max(a[1]+b[2]+c[3]+b[4],
			max(a[1]+c[2]+a[3]+b[4],max(a[1]+c[2]+a[3]+c[4],
			max(a[1]+c[2]+b[3]+b[4],max(a[1]+c[2]+b[3]+c[4],max(a[1]+c[2]+c[3]+b[4],
			max(a[1]+c[2]+c[3]+a[4],max(a[1]+c[2]+b[3]+a[4],
			max(b[1]+a[2]+b[3]+c[4],max(b[1]+a[2]+c[3]+b[4],
			max(b[1]+a[2]+a[3]+b[4],max(b[1]+a[2]+b[3]+a[4],max(b[1]+a[2]+c[3]+a[4],
			max(b[1]+a[2]+a[3]+c[4],max(b[1]+a[2]+c[3]+c[4],b[1]+b[2]+a[3]+a[4]
			)))))))))))))))))))))))))))))))))))))))))))))))))))))<<endl;
		}
		else{
			long long cnt=0,ccf=0,fu=0,ck=0;
			for(int j=1;j<=n;j++){
				cin>>a[j]>>b[j]>>c[j];
				if(b[j]!=0 && c[j]!=0) ccf=1;
				if(a[j]!=0 && c[j]!=0) fu=1;
				if(a[j]!=0 && b[j]!=0) ck=1;
				cnt+=max(a[j],max(b[j],c[j]));
			}
			if(ccf==0){
				cnt=0;
				sort(a+1,a+n+1);
				for(int i=n;i>=n/2;i++) cnt+=a[i];
			}
			if(fu==0){
				cnt=0;
				sort(b+1,b+n+1);
				for(int i=n;i>=n/2;i++) cnt+=b[i];
			}
			if(ck==0){
				cnt=0;
				sort(c+1,c+n+1);
				for(int i=n;i>=n/2;i++) cnt+=c[i];
			}
			if(ccf==0 && fu==0 && ck==0){
				cout<<0<<endl;
				continue;
				//i f c k f c c u QwQ
			}
			cout<<cnt<<endl;
		}
	}
	//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf//ccf///ÎÒ°®´ò±íawa
	//                                                                    luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang luoguluogu
	return 0;
}
