#include "myge.h"


int32_t gaussian_elimination( int32_t n, int32_t *pA, int32_t *py, int32_t **px ){

	if(n<=0) return -1;
	if(pA == NULL || py == NULL) return -1;
	
	long double **arr = calloc( n,sizeof(long double *));
	for(int i=0;i<n;i++){
		arr[i] = calloc(n+1,sizeof(long double));
		for(int j=0;j<n;j++)arr[i][j] = *(pA + i *n + j);
		arr[i][n] = *(py+i);
	}

	for(int i=0;i<n;i++){
		if(arr[i][i]==0){
			for(int j=i+1;j<n;j++){
				if(arr[j][i]!=0){
					for(int cc = 0; cc<n+1;cc++){
						long double temp = arr[i][cc];
						arr[i][cc] = arr[j][cc];
						arr[j][cc] = temp;
					}
					break;
				}
			}
		}
		if(!arr[i][i])continue;
		long double chen = arr[i][i];
		for(int j =i;j<n+1;j++)arr[i][j] /= chen;
		for(int j=i+1;j<n;j++){
			if(arr[j][i]){
				chen = arr[j][i];
				for(int k=i;k<n+1;k++) arr[j][k] -= arr[i][k] * chen;
			}
		}

	}


	if(!arr[n-1][n-1]){
		if(arr[n-1][n]) return 0;
		int count = 0;
		for(int i=0;i<n+1;i++)count += arr[n-1][i] == 0 ? 1 : 0;
		if(count==n+1) return 2;
	}
	for(int i=n-1;i>=0;i--){
		if((int)arr[i][n]%(int)arr[i][i]!=0)return 0;
		arr[i][n] = arr[i][n]/arr[i][i];

		//if((int)arr[i][n] != arr[i][n]) return 0;
		for(int j =i-1;j>=0;j--)arr[j][n] -= arr[j][i] * arr[i][n];

	}
	*px = malloc(n*sizeof(int32_t));
	for(int i=0;i<n;i++){
		*(*px+i) = (float)arr[i][n];
		//printf("%LF",arr[i][n]);
	}
	return 1;


}