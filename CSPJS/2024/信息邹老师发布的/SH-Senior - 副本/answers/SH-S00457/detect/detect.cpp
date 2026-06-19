#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct kar{
	int d,v,a;
};
kar che[100005];
int ce[100005];
int panduan_sqian[1000005];
int panduan_hou[1000005];
int ce_tong[1000005];
int t[1000005];
int main(int argc, char** argv) {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
//	double a=8.0/3;
//	cout << a;
	int ttt;
	scanf("%d",&ttt);
//	ttt=2;
	for(int tt=1;tt<=ttt;tt++){
		int ans1=0;
		memset(ce,0,sizeof(ce));
		memset(panduan_sqian,0,sizeof(panduan_sqian));
		memset(panduan_hou,0,sizeof(panduan_hou));
		memset(ce_tong,0,sizeof(ce_tong));
//		memset(panduan_sqian,0,memset(panduan_sqian));
//		cout << "fdsa";
		//¶à²áÇå¿Õ£¡£¡£¡£¡£¡£¡ 
		int n,m,l,V;
		scanf("%d %d %d %d",&n,&m,&l,&V);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&che[i].d,&che[i].v,&che[i].a);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&ce[i]);
			ce_tong[ce[i]]++;
		}
		sort(ce+1,ce+m+1);
//		int rr=0;
		int r=1;
//									cout <<"fsdag"; 
		for(int i=1;i<=l;i++){
			if(i==ce[r]){
				r++;
				
			}
			panduan_sqian[i]=r-1;
			panduan_hou[i]=m-panduan_sqian[i];
		}
//		for(int i=1;i<=l;i++){
//			cout << panduan_sqian[i] <<" ";
//		}
//		cout << endl;
//		for(int i=1;i<=l;i++){
//			cout << ce_tong[i] <<" ";
//		}
////														cout << "Fsdafd";
		for(int i=1;i<=n;i++){
//													cout << "FFFFF";
			int V0=che[i].v;
//			V=at;
//			if()
			if(che[i].a==0){
				if(V0>V){
					if(panduan_hou[che[i].d]>0 or ce_tong[che[i].d]>0){
						ans1++;
//						for(int i=1)
					}
					
				}
				continue;
			}
			
			else if(che[i].a>0){
				if(che[i].v>V){
					if(panduan_hou[che[i].d]>0 or ce_tong[che[i].d]>0 ){
						ans1++;
					}
					
					continue;
				}
				if(che[i].v==V){
					if(panduan_hou[che[i].d]>0){
						ans1++;
					}
					
					continue;
				}
			}
			else{
				if(che[i].v<=V)continue;
			}
//														cout << "JMQQQQQQQ";
			if(che[i].a>0){
				double t=1.0*abs(V-V0)/abs(che[i].a);
				double s=1.0*V0*t+0.5*che[i].a*t*t;
				if (s>l){
					s=l+1;
				}
				int ss=s;
				if(abs(s-ss-1)<=0.000001){
					ss+=1;
				} 
				if(ss>l)ss=l+2;
//				cout << t << " " << s << " " << che[i].d << " " << ss << endl;
				ss+=che[i].d;
				if(ss>l)ss=l+2;
//				ss+=1;
				if(panduan_hou[ss]>0 or ce_tong[ss]>0){
					ans1++;
				}
				
			}
																		
			else if(che[i].a<0){
//													cout <<"fdsa";
//				cout << i << endl;
				double t=1.0*abs(V-V0)/abs(che[i].a);
				double s=1.0*V0*t+0.5*che[i].a*t*t;
				//d~s
//				cout << "fasd";
//				if(s>l){
//					s=l+1;
//				}
//				int ss=s+che[i].d;
//				if(ss>l)ss=l+2;
				if (s>l){
					s=l+1;
				}
				int ss=s;
				if(abs(s-ss-1)<=0.000001){
					ss+=1;
				} 
				if(ss>l)ss=l+2;
//				cout << t << " " << s << " " << che[i].d << " " << ss << endl;
				ss+=che[i].d;
				if(ss>l)ss=l+2;
//				cout << t << " " << s << " " << che[i].d << " " << ss << endl;
//				if(panduan_sqian[ss]-panduan_sqian[che[i].d-1]>0){
//					ans1++;
//				}
				if(panduan_hou[che[i].d-1]-panduan_hou[ss]>0){
					ans1++;
				}
			}
//			cout << ans1 << endl;
//								cout << "finish";
//			double t=abs(V-V0)/abs(a);
//			double s=v0t+0.5*V*t*t
		}
//		cout << endl;
	
		printf("%d %d\n",ans1,m-1);
	
		
	} 
	return 0;
}
/*
1
10 10 175391 226
31181 234 -546
32757 670 -9
43723 775 -3
78541 862 -4
26626 961 -13
54690 759 -998
56165 659 -3
56531 776 -34
32860 950 -6
86709 145 47
31182 33025 46753 52673 57685 60635 99569 124240 162898 170704

1
9 10 175391 226
31181 234 -546
32757 670 -9
43723 775 -3
78541 862 -4
26626 961 -13
54690 759 -998
56165 659 -3
56531 776 -34
32860 950 -6
31182 33025 46753 52673 57685 60635 99569 124240 162898 170704

1
9 10 114934 719
62115 915 -6
44976 920 -17
21788 877 -1
38609 839 -3
44828 982 -8
9713 1000 -109
61421 860 -922
16064 918 -2
33522 989 -11
13230 19868 37544 44774 45209 54175 61486 62595 87581 101248
*/
