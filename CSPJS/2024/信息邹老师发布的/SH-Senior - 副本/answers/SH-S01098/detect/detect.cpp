#include<iostream>
using namespace std;

inline int lowbit(int anumber){
	return anumber&(-anumber);
}

inline int read(){
	int xnum=0,fuhao=1;
	char c = getchar();
	while ((c<'0'||c>'9')&&(c!='-')) c = getchar();
	if (c=='-'){
		fuhao = -1;
		c = getchar();
	}
	while (c>='0'&&c<='9'){
		xnum = xnum*10+c-'0';
		c = getchar();
	}
	return xnum*fuhao;
}

const int MAXN = 100050;
const int MAXL = 1000050;
const int MANV = 1050;
int T;
int n,m,Len,Vmax;
int dis[MAXN],v[MAXN],a[MAXN];
int place[MAXN];

int lleft[MAXN],rright[MAXN];
int szsz[MAXN];
bool gget[MAXN];


struct node{
	int l;
	int r;
} llist[MAXN];
int rsum;
node mids[MAXN];
void sorrt(int l,int r){
	if (l==r) return;
	int mid = (l+r)>>1;
	sorrt(l,mid);
	sorrt(mid+1,r);
	int i=l,j=mid+1,k=l;
	while (i<=mid&&j<=r){
		if (llist[i].l<=llist[j].l) mids[k++] = llist[i++];
		else mids[k++] = llist[j++];
	}
	while (i<=mid) mids[k++] = llist[i++];
	while (j<=r) mids[k++] = llist[j++];
	for (int h=l;h<=r;h++){
		llist[h] = mids[h];
	}
	return;
}

inline bool goodjudge(int carnum,int point){
	if (v[carnum]*v[carnum]+2*a[carnum]*(point-dis[carnum])<=Vmax*Vmax){
		return true;
	}else{
		return false;
	}
}
int erfena(int carnum,int l,int r){
	if (l==r) return l;
	int mid = (l+r)>>1;
	if (goodjudge(carnum,mid)) return erfena(carnum,l,mid);
	else return erfena(carnum,mid+1,r);
}
int erfenb(int carnum,int l,int r){
	if (l==r) return l;
	int mid = ((l+r-1)>>1)+1;
	if (goodjudge(carnum,mid)) return erfenb(carnum,mid,r);
	else return erfenb(carnum,l,mid-1);
}

inline void szsz_update(int xx){
	while (xx<=n){
		szsz[xx]++;
		xx += lowbit(xx);
	}
	return;
}
inline int szsz_sum(int yy){
	if (yy<=0) return 0;
	int szszres = 0;
	while (yy){
		szszres += szsz[yy];
		yy -= lowbit(yy);
	}
	return szszres; 
}

int erfenc(int l,int r){
	if (l==r) return l;
	int mid = ((l+r-1)>>1)+1;
	if (szsz_sum(mid)-szsz_sum(l-1) > 0){
		return erfenc(mid,r);
	}else{
		return erfenc(l,mid-1);
	}
}

void reset(){
	for (int i=1;i<=n;i++){
		szsz[i] = 0;
		gget[i] = false;
	}
}

int main(){
	
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	T = read();
	
	while (T--){
		reset();
		
		n = read();
		m = read();
		Len = read();
		Vmax = read();
		
		for (int i=1;i<=n;i++){
			
			
			dis[i] = read();
			v[i] = read();
			a[i] = read();
			
			//cout<<dis[i]<<' '<<v[i]<<' '<<a[i]<<endl;
			
			if (a[i]==0){
				//cout<<'a'<<endl;
				
				if (v[i]>Vmax){
					lleft[i] = dis[i];
					rright[i] = Len;
				}else{
					lleft[i] = -1;
					rright[i] = -1;
				}
			}else if (a[i]<0){
				
				//cout<<'b'<<endl;
				
				if (v[i]<=Vmax){
					
					//cout<<'!'<<endl;
					lleft[i] = -1;
					rright[i] = -1;
				}else{
					rright[i] = erfena(i,dis[i],Len)-1;
					lleft[i] = dis[i];
				}
			}else{
				
				//cout<<'c'<<endl;
				
				if (goodjudge(i,Len)){
					lleft[i] = -1;
					rright[i] = -1;
				}else{
					lleft[i] = erfenb(i,dis[i],Len)+1;
					rright[i] = Len;
				}
			}
			
		}
		for (int i=1;i<=m;i++){
			place[i] = read();
			szsz_update(place[i]);
		}
		/*
		for (int i=1;i<=n;i++){
			cout<<lleft[i]<<' '<<rright[i]<<endl;
		}
		*/
		int calc=0;
		for (int i=1;i<=n;i++){
			//cout<<1;
			if (szsz_sum(rright[i])-szsz_sum(lleft[i]-1)){
				//cout<<2;
				calc++;
				gget[i] = true;
			}
		}
		cout<<calc<<' ';
		
		for (int i=1;i<=n;i++){
			if (gget[i] == true){
				llist[++rsum].l = lleft[i];
				llist[rsum].r = rright[i];
			}
		}
		sorrt(1,rsum);
		int firstm = MAXN;
		int minr = MAXN;
		int leftend = 0;
		calc = 0;
		for (int i=1;i<=rsum;i++){
			if (leftend == 0){
				leftend = llist[i].l;
			}
			if (llist[i].l>firstm){
				++calc;
				leftend = llist[i].l;
				firstm = erfenc(leftend,llist[i].r);
				minr = llist[i].r;
				continue;
			}
			leftend = llist[i].l;
			if (llist[i].r<minr){
				minr = llist[i].r;
				firstm = erfenc(leftend,minr);
			}
			
		}
		calc++;
		cout<<calc<<endl;
		
	}
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}



