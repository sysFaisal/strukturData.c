#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 50

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

int binarysearch(int arr[], int low, int high, int x){
	
	while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == x){
        	return mid;
		}

        if(arr[mid] < x){
        	low = mid + 1;
		} else {
			high = mid - 1;
		}
    }

    return -1;
	
}


int fibonacciSearch(int arr[], int n, int target) {
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm1 + fibMMm2;

    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm1 + fibMMm2;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);

        if (arr[i] < target) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arr[i] > target) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
            return i;
    }

    if (fibMMm1 && arr[offset + 1] == target)
        return offset + 1;

    return -1;
}

int exponentialSearch(int arr[], int n, int target) {
    if (arr[0] == target)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= target)
        i = i * 2;

    return binarysearch(arr, i/2, (i < n ? i : n - 1), target);
}

int interpolationSearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {

        int pos = low + ((target - arr[low]) * (high - low)) /
                         (arr[high] - arr[low]);

        if (arr[pos] == target)
            return pos;

        if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}


int jumpSearch(int arr[], int length, int x){
	int step = sqrt(length);
    int prev = 0;
	int i = 0;
	
    while(arr[(step < length ? step : length)-1] < x) {
        prev = step;
        step += sqrt(length);
        if(prev >= length)
            return -1;
    }

    for(i = prev; i < (step < length ? step : length); i++) {
        if(arr[i] == x)
            return i;
    }

    return -1;
}

int linearsearch(int arr[], int length, int x){
	int i;
	for (i = 0; i < length; i++){
		if (arr[i] == x){
			return i;
		}		
	}
	return -1;
}

int main (){
	int arr[] = {
	1,2,3,4,5,6,7,8,9,10,
	11,12,13,14,15,16,17,18,19,20,
	21,22,23,24,25,26,27,28,29,30,
	31,32,33,34,35,36,37,38,39,40,
	41,42,43,44,45,46,47,48,49,50,
	51,52,53,54,55
	};
	int length  = sizeof(arr) / sizeof(arr[0]);
	int target = 20;
	
	
	
	int ls = linearsearch(arr, length, target);
	int bs = binarysearch(arr, 0, length, target);
	int js = jumpSearch(arr, length, target);
	int is = interpolationSearch(arr, length, target);
	int fs = fibonacciSearch(arr, length, target);
	int es = exponentialSearch(arr, length, target);
	
	printf("Target : %d\n", target);
    printf("\n");
	printf("%-22s : %3d | Memory: %p\n", "Linear Search", ls, &ls);
	printf("%-22s : %3d | Memory: %p\n", "Binary Search", bs, &bs);
	printf("%-22s : %3d | Memory: %p\n", "Jump Search", js, &js);
	printf("%-22s : %3d | Memory: %p\n", "Interpolation Search", is, &is);
	printf("%-22s : %3d | Memory: %p\n", "Fibonacci Search", fs, &fs);
	printf("%-22s : %3d | Memory: %p\n", "Exponential Search", es, &es);
	
    getchar();
    getchar();
}

