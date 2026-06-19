#include<bits/stdc++.h>
using namespace std;
void init() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
}
#define group(i,j) ((i)*m+(j))
#define access(i,j) d[group(i,j)]
#define likely(x) __builtin_expect(x,1)
#define unlikely(x) __builtin_expect(x,0)
class bcs {
		vector<int> data;
		vector<int> list;
		vector<int> size;
	public:
		bcs(int l) : data(l),list(l),size(l) {
			for(int i=0; i<l; i++) {
				data[i]=i;
				list[i]=1;
				size[i]=1;
			}
		}
		int operator[](int x) {
			if(unlikely(data[x]==x)) {
				return x;
			} else {
				return data[x]=operator[](data[x]);
			}
		}
		void operator()(int x,int y) {
			x=operator[](x);
			y=operator[](y);
			if(unlikely(list[x]<list[y])) {
				data[y]=x;
				list[x]++;
				size[x]+=size[y];
			} else {
				data[x]=y;
				list[y]++;
				size[y]+=size[x];
			}
		}
		int getSize(int x) {
			return size[operator[](x)];
		}
};
void explore() {
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int x0,y0,d0;
	scanf("%d %d %d",&x0,&y0,&d0);
	x0--;
	y0--;
	vector<bool> d(n*m);
	for(int i=0; i<n; i++) {
		char s[m+10];
		scanf("%s",s);
		for(int j=0; j<m; j++) {
			access(i,j) = (s[i]=='x');
		}
	}
	bcs image(n*m);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(likely(!access(i,j))) {
				if(likely(i+1<n)) {
					if(likely(!access(i+1,j))) {
						image(group(i,j),group(i+1,j));
					}
				}
				if(likely(j+1<m)) {
					if(likely(!access(i,j+1))) {
						image(group(i,j),group(i,j+1));
					}
				}
			}
		}
	}
	int g0 = image[group(x0,y0)];
	int ans=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			int step=abs(i-x0)+abs(j-y0);
			if((step^k)&1) {
				continue;
			}
			if(unlikely(step>k)) {
				continue;
			}
			if(image[group(i,j)]==g0) {
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}
int main() {
	init();
	int k;
	cin>>k;
	for(int i=0; i<k; i++) {
		explore();
	}
}
