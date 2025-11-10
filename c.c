#include <stdio.h>
#include <time.h>
#include <stdlib.h>



float integral(float a,float b){
    float r=0;
    while(a<=b){
        r+=(4*a*a+7*a-5);
        a+=0.0001;
    }
    return r*0.0001;
}

int  main(){
    clock_t start, end;
    float cpu_time_used;
    float a,b;
    scanf("%f %f",&a,&b);
    start = clock();
    printf("I = %.2f\n",integral(a,b));
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", cpu_time_used);

}