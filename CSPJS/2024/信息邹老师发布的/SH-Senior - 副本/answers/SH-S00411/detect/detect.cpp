#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("detect.in");
ofstream fout("detect.out");
int T;
int n,m,L,V;
struct car{
	long long dis,vel,acc;
	void input(){
		fin>>dis>>vel>>acc;
	}
}c[100005];
int p[100005];
int cnt=0;
struct segment{
	int lef,rig;
	bool operator <(const segment b)const{
		return lef==b.lef?rig<b.rig:lef<b.lef;
	}
}per[100005];
int BS1(long long pos,long long multi){//finds first perimeter that is bigger than or equal to pos
	int l=-1,r=m,mid;
	while(l+1<r){
		mid=(l+r)>>1;
		if(p[mid]*multi<pos)l=mid;
		else r=mid;
	}
	return r;
}
int BS2(long long pos,long long multi){//finds first perimeter that is bigger than pos
	int l=-1,r=m,mid;
	while(l+1<r){
		mid=(l+r)>>1;
		if(p[mid]*multi<=pos)l=mid;
		else r=mid;
	}
	return r;
}
int templ,tempr;
int now;
segment queue[100005];
int front=0,rear=0;
int minper=0;
int main(){
	fin>>T;
	for(int testcaseid=0;testcaseid<T;testcaseid++){
		fin>>n>>m>>L>>V;
		for(int i=0;i<n;i++)c[i].input();
		for(int i=0;i<m;i++)fin>>p[i];
		cnt=0;
		for(int i=0;i<n;i++){
			if(c[i].acc>0){
				if(c[i].vel>V)templ=BS1(c[i].dis,1),tempr=m-1;
				else templ=BS2(V*V-c[i].vel*c[i].vel+c[i].dis*2*c[i].acc,2*c[i].acc),tempr=m-1;
			}
			else if(c[i].acc==0){
				if(c[i].vel>V)templ=BS1(c[i].dis,1),tempr=m-1;
				else templ=m,tempr=m-1;
			}
			else{
				if(c[i].vel<=V)templ=m,tempr=m-1;
				else templ=BS1(c[i].dis,1),tempr=BS1(c[i].dis*2*(-c[i].acc)+c[i].vel*c[i].vel-V*V,2*(-c[i].acc))-1;
			}
			if(templ>tempr)continue;
			else{
				per[cnt].lef=templ,per[cnt].rig=tempr;
				cnt++;
			}
		}
		sort(per,per+cnt);
		front=0,rear=0;
		minper=0;
		for(int i=0;i<cnt;i++){
			while(front<rear && queue[rear-1].rig>=per[i].rig)rear--;
			queue[rear++]=per[i];
		}
		while(front<rear){
			now=queue[front].rig;
			minper++;
			while(front<rear && queue[front].lef<=now)front++;
		}
		fout<<cnt<<" "<<m-minper<<endl;
	}
	return 0;
}
