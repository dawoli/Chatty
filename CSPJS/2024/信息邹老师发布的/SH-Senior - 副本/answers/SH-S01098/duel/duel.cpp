#include<iostream>
using namespace std;

inline int read(){
	int xnum=0;
	char c = getchar();
	while (c<'0'||c>'9') c = getchar();
	while (c>='0'&&c<='9'){
		xnum = xnum*10+c-'0';
		c = getchar();
	}
	return xnum;
}

const int MAXN = 100050;
int n;
int a[MAXN];
int tong[MAXN];
int mids[MAXN];

void sorrt(int l,int r){
	
	if (l==r) return;
	int mid = (l+r)>>1;
	sorrt(l,mid);
	sorrt(mid+1,r);
	int i=l,j=mid+1,k=l;
	while (i<=mid&&j<=r){
		if (a[i]<a[j]) mids[k++] = a[i++];
		else mids[k++] = a[j++];
	}
	while (i<=mid) mids[k++] = a[i++];
	while (j<=r) mids[k++] = a[j++];
	for (int h=l;h<=r;h++){
		a[h] = mids[h];
	}
	return;
}

int main(){
	
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	
	n = read();
	for (int i=1;i<=n;i++){
		a[i] = read();
	}
	
	sorrt(1,n);
	/*
	for (int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}cout<<endl;
	*/
	
	int place=1;
	int ans=n;
	for (int i=1;i<=n;i++){
		++place;
		while (a[place]<=a[i] && place<=n) ++place;
		if (place>n) break;
		ans--;
	}
	cout<<ans<<endl;
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}


/*
5
1 2 3 1 2
*/


