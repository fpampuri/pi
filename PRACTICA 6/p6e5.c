#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "getnum.h"

int noRepeat(const int vec[], int dim, int vecNuevo[])
{
    int dimNueva=0;
    if ( dim > 0) {
        vecNuevo[0]=vec[0];
        for (int i=1, dimNueva=1 ; i < dim ; i++) {
            if ( vec[i] != vec[i-1])
                vecNuevo[dimNueva++]=vec[i];
        }
    }
    return dimNueva;      
}
/* int
noRepeat( const int original[], int dimOrig, int resultado[]) {
	int dimResult = 0;
	int i;
	
	if (dimOrig > 0) {
		resultado[0] = original[0];
		for (i = 1, dimResult = 1; i < dimOrig; i++)
			if (original[i] != original[i-1])
				resultado[dimResult++] = original[i];
	}
	return dimResult;
}
 */
int main(void) {
  int v[] = { -3, -3, -1, 0, 1, 2, 2, 2, 3, 3, 3};
  int res[20];
  int dimRes;

  dimRes = noRepeat(v, 0, res);
  assert(dimRes==0);

  dimRes = noRepeat(v, 1, res);
  assert(dimRes==1);
  assert(res[0]==-3);

  dimRes = noRepeat(v, 2, res);
  assert(dimRes==1);
  assert(res[0]==-3);

  dimRes = noRepeat(v, 11, res);
  assert(dimRes==6);
  assert(res[0]==-3);
  assert(res[1]==-1);
  assert(res[2]==0);
  assert(res[3]==1);
  assert(res[4]==2);
  assert(res[5]==3);


  int n=80000;
  int v2[n];
  int res2[n];
  for (int i=0; i < n; i++)
     v2[i] = 100;
  dimRes = noRepeat(v2, n, res2);
  assert(dimRes==1);
  assert(res2[0]==100);

  for (int i=0; i < n; i++)
     v2[i] =i;
  dimRes = noRepeat(v2, n, res2);
  assert(dimRes==n);
  for (int i=0; i < n; i++)
    assert(res2[i]==i);

  puts("OK!");
  return 0;
}

