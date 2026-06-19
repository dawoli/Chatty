#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct happied_level{
	int m[4];
	int mm1,mm2;
}hl[N];
int n,cnt;
int cb1[N],cb2[N],cb3[N],c1,c2,c3;
int cvm[N],vc[N],gv[N],cv,useless_changeable_value;
void init(){
	memset(cb1,0,sizeof(cb1));
	memset(cb2,0,sizeof(cb2));
	memset(cb3,0,sizeof(cb3));
	memset(cvm,0,sizeof(cvm));
	memset(vc,0,sizeof(vc));
	memset(gv,0,sizeof(gv));
	memset(hl,0,sizeof(hl));
	c1=0;
	c2=0;
	c3=0;
	cv=0;
	useless_changeable_value=useless_changeable_value;
	cnt=0;
}
bool cmp1(int a,int b){
	return hl[a].mm1>hl[b].mm1;
}
bool cmp2(int a,int b){
	return hl[a].mm1-hl[a].mm2<hl[b].mm1-hl[b].mm2;
}
bool cmp3(int a,int b){
	return hl[a].mm1-hl[a].mm2>hl[b].mm1-hl[b].mm2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		init();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>hl[i].m[1]>>hl[i].m[2]>>hl[i].m[3];
			if(hl[i].m[1]>=hl[i].m[2]){
				if(hl[i].m[1]>=hl[i].m[3]){
					cb1[++c1]=i;
					cnt+=hl[i].m[1];
					hl[i].mm1=hl[i].m[1];
					if(hl[i].m[2]>hl[i].m[3]){
						hl[i].mm2=hl[i].m[2];
					}else{
						hl[i].mm2=hl[i].m[3];
					}
				}else{
					cb3[++c3]=i;
					cnt+=hl[i].m[3];
					hl[i].mm1=hl[i].m[3];
					hl[i].mm2=hl[i].m[1];
				}
			}else{
				if(hl[i].m[2]>=hl[i].m[3]){
					cb2[++c2]=i;
					cnt+=hl[i].m[2];
					hl[i].mm1=hl[i].m[2];
					if(hl[i].m[1]>hl[i].m[3]){
						hl[i].mm2=hl[i].m[1];
					}else{
						hl[i].mm2=hl[i].m[3];
					}
				}else{
					cb3[++c3]=i;
					cnt+=hl[i].m[3];
					hl[i].mm1=hl[i].m[3];
					hl[i].mm2=hl[i].m[2];
				}
			}
		}
		if(c1>(n>>1)){
			cv=c1;
			for(int i=1;i<=c1;i++){
				cvm[i]=cb1[i];
			}
		}else if(c2>(n>>1)){
			cv=c2;
			for(int i=1;i<=c2;i++){
				cvm[i]=cb2[i];
			}
		}else if(c3>(n>>1)){
			cv=c3;
			for(int i=1;i<=c3;i++){
				cvm[i]=cb3[i];
			}
		}else{
			cout<<cnt<<'\n';
			continue;
		}
		sort(cvm+1,cvm+1+cv,cmp1);
		int half_of_n=n>>1;
		int cv_minus_half_of_n=cv-half_of_n;
		for(int i=1;i<=half_of_n;i++){
			vc[i]=cvm[i];
		}
		for(int i=half_of_n+1,j=1;i<=cv;i++,j++){
			gv[j]=cvm[i];
			cnt=cnt+hl[gv[j]].mm2-hl[gv[j]].mm1;
		}
		sort(vc+1,vc+1+half_of_n,cmp2);
		sort(gv+1,gv+1+cv_minus_half_of_n,cmp3);
		for(int i=1,j=1;i<=half_of_n&&j<=cv_minus_half_of_n;i++,j++){
			if(hl[vc[i]].mm1-hl[vc[i]].mm2<hl[gv[j]].mm1-hl[gv[j]].mm2){
				cnt+=(hl[gv[j]].mm1-hl[gv[j]].mm2+hl[vc[i]].mm2-hl[vc[i]].mm1);
			}else{
				break;
			}
		}
		cout<<cnt<<'\n';
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
