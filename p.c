#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int n=30000;
// int a[n];


int generateInt() {
    return rand()%100 ;
}


// int findSmalest(int index,int len){
//     int smalestIndex = index;

//     for(int i=index+1;i<len;i++){
//         if(a[i]<a[smalestIndex]){
//             smalestIndex=i;
//         }
//     }
    
//     return smalestIndex;
// }


int r(void const *a, void const * b){
    return *(int*)a - *(int*)b; 
}
int main() {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int a[n];
    
    
    srand(time(NULL));

    for(int i = 0; i < n; i++) {
        int k=generateInt();
        a[i] = k;
    }

    for(int i = 0; i < n; i++) {
        printf("%d, ", a[i]);
    }
    printf("\n\n");
    start = clock();
    //////Selecttion
    // for(int i = 0; i < n-0; i++) {
    //     int k=findSmalest(i,n);
    //     if(k!=i){
    //         int tmp=a[i];
    //         a[i]=a[k];
    //         a[k]=tmp;
    //     }
    // }
    // //insertion
    // for(int i=1;i<n;i++){
    //     int k=a[i];
    //     int j=i-1;
    //     while(j>=0&&a[j]>k){
    //         a[j+1]=a[j];
    //         j--;
    //     }
    //     a[j + 1] = k;
    // }
    // ////

    qsort(&a,n,sizeof(int),r);
    end = clock();
    for(int i = 0; i < n; i++) {
        printf("%d, ", a[i]);
    }
    printf("\n\n");
    

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", cpu_time_used);

    return 0;
}
