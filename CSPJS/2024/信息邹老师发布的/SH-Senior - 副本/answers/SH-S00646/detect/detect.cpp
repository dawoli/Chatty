#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int T, n, m, L, V, d[100010], v[100010], a[100010], p[100010];
int cntOveSpe, cntPLef;
int rigNeaP[1000010], rigNeaPId[1000010];
int cntSeg, segL[100010], segR[100010], segIdx[100010];
int fenWicTre[100010];
bool cmp(int idOne, int idTwo) {
	if(segR[idOne] != segR[idTwo]) 
        return segR[idOne] < segR[idTwo];
	return idOne < idTwo; 
}
int lowbit(int x) {
	return x & -x;
}
void ins(int x) {
	for(int id = x; id <= m; id += lowbit(id))
		fenWicTre[id]++;
}
int fid(int x) {
	int ret = 0;
	for(int id = x; id; id -= lowbit(id))
		ret += fenWicTre[id];
	return ret;
}
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d %d", &n, &m, &L, &V);
		for(int i = 1; i <= n; i++) {
			scanf("%d %d %d", &d[i], &v[i], &a[i]);
		}
		for(int i = 1; i <= m; i++) {
			scanf("%d", &p[i]);
            fenWicTre[i] = 0;
        }
		cntOveSpe = cntSeg = cntPLef = 0 ;
        int pPoi = 1;
        for(int i = 0; i <= L; i++) {
            if(p[pPoi] < i && pPoi <= m) 
                pPoi++;
            rigNeaP[i] = (pPoi == m + 1 ? -1 : p[pPoi]);
            rigNeaPId[i] = pPoi;
        }
        int pMin = 1;
        for(int i = 1; i <= n; i++) {
            if(a[i] > 0) {
                if(p[m] >= d[i] && 1ll * v[i] * v[i] + 1ll * a[i] * (p[m] - d[i]) * 2 > 1ll * V * V) {
                    cntOveSpe++;
                    int tmpL = rigNeaPId[d[i]], tmpR = m, mid;
                    while(tmpL < tmpR) {
                        mid = (tmpL + tmpR) / 2;
                        if(1ll * v[i] * v[i] + 1ll * a[i] * (p[mid] - d[i]) * 2 > 1ll * V * V)
                            tmpR = mid;
                        else
                            tmpL = mid + 1;
                    } 
                    pMin = max(pMin, tmpR);
                }
            } else if(a[i] < 0) {
                if(rigNeaP[d[i]] != -1 && 1ll * v[i] * v[i] + 1ll * a[i] * (rigNeaP[d[i]] - d[i]) * 2 > 1ll * V * V) {
                    cntOveSpe++;
                    cntSeg++;
                    segL[cntSeg] = rigNeaPId[d[i]];
                    int tmpL = segL[cntSeg], tmpR = m, mid;
                    while(tmpL < tmpR) {
                        mid = (tmpL + tmpR + 1) / 2;
                        if(1ll * v[i] * v[i] + 1ll * a[i] * (p[mid] - d[i]) * 2 > 1ll * V * V)
                            tmpL = mid;
                        else
                            tmpR = mid - 1;
                    } 
                    segR[cntSeg] = tmpL;
                    segIdx[cntSeg] = cntSeg;
                }
            } else {
                if(v[i] > V && d[i] <= p[m]) {
                    cntOveSpe++;
                    pMin = max(pMin, rigNeaPId[d[i]]);
                }
            }
        }
        if(cntOveSpe) {
        	cntSeg++;
	        segL[cntSeg] = pMin;
	        segR[cntSeg] = m;
	        segIdx[cntSeg] = cntSeg;
	        sort(segIdx + 1, segIdx + cntSeg + 1, cmp);
	        for(int i = 1; i <= cntSeg; i++) {
	            int id = segIdx[i];
	            if(fid(segR[id]) - fid(segL[id] - 1) == 0) {
	                ins(segR[id]);
	                cntPLef++;
	            }
	        }
		}
        printf("%d %d\n", cntOveSpe, m - cntPLef);
	} 
    return 0;
}
