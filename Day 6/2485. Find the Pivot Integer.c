int pivotInteger(int n) {
    for(int i = n; i>0; i--) {
        //printf("current i is %d\n", i);
        //check if current i is the pivot
        int sumAfterPivot = 0;
        int sumBeforePivot = 0;
        for(int j = 1; j <= i; j++) {
            sumBeforePivot += j; 
        }
        //printf("Sum before %d is %d\n",i,sumBeforePivot);
        for(int k = i; k <= n; k++) {
            sumAfterPivot += k; 
        }
        //printf("Sum after %d is %d\n",i,sumAfterPivot);
        if(sumBeforePivot == sumAfterPivot) {
            return i;
        }
    }
    return -1;
}