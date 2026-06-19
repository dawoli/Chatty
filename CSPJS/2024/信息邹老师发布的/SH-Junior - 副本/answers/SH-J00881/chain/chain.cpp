#include<bits/stdc++.h>
using namespace std;
constexpr int BITSET_MAX = 1e9+7;
class Bitset3D {
		mutable bitset<BITSET_MAX> mData;
		mutable int x,y,z;
	public:
		int reset(int d0,int d1,int d2) const {
			mData.reset();
			x=d0;
			y=d1;
			z=d2;
		}
		bitset<BITSET_MAX>::reference access(int i,int j,int k) const {
			return mData[i*y*z+j*z+k];
		}
} dp;
class VectorArray {
		mutable vector<int> data;
		mutable vector<int> indexStart;
	public:
		VectorArray() {
			indexStart.push_back(0);
		}
		__attribute__((const))
		int* operator[](int i) const {
			return &data[indexStart[i]];
		}
		int* allocate(int n) const {
			data.resize(data.size()+n);
			indexStart.push_back(indexStart[indexStart.size()-1]+n);
			return &data[indexStart[indexStart.size()-2]];
		}
		int size() const {
			return indexStart.size()-1;
		}
		int capacity() const {
			return data.size();
		}
		__attribute__((const))
		int size(int i) const {
			return indexStart[i+1]-indexStart[i];
		}
};
int lastAppear[200005];
bool ddddpppp(int n,VectorArray& va,int maxSize) {
	for(int j=0; j<n; j++) {
		memset(lastAppear,0,sizeof(lastAppear));
		int* vaj=va[j];
		for(int k=0; k<va.size(j); k++) {
			lastAppear[vaj[k]]=max(lastAppear[vaj[k]],k);
		}
		for(int i=0; i<n; i++) {
			int* vai=va[i];
			for(int k=0; k<va.size(i); k++) {
				dp.access(i,j,k)=lastAppear[vai[k]]>k;
			}
		}
	}
	for(int k=0; k<n; k++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				for(int m=0; m<maxSize; m++) {
					dp.access(i,j,m)=dp.access(i,j,m)||(dp.access(i,k,m)&&dp.access(k,j,m));
				}
			}
		}
	}
}
void processOnce() {
	int n,k,q;
	cin>>n>>k>>q;
	VectorArray va;
	int maxSize = 0;
	for(int i=0; i<n; i++) {
		int li;
		scanf("%d",&li);
		int* si = va.allocate(li);
		maxSize=max(maxSize,li);
		for(int j=0; j<li; j++) {
			scanf("%d",si+j);
		}
	}
	dp.reset(n,n,maxSize);
	ddddpppp(n,va,maxSize);
	for(int i=0; i<q; i++) {
		int rj,cj;
		scanf("%d %d",&cj,&rj);
		printf("%d\n",(int)dp.access(cj-rj-1,cj-1,k));
	}
}
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0; i<T; i++) {
		processOnce();
	}
}
