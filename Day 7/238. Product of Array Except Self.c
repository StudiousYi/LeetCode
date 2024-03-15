/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*) malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    if(numsSize == 2) {
        ans[0] = nums[1];
        ans[1] = nums[0];
        return ans;
    }
    else if(numsSize == 3) {
        ans[0] = nums[1]*nums[2];
        ans[1] = nums[0]*nums[2];
        ans[2] = nums[0]*nums[1];
        return ans;
    }
    int* storeLeft = (int*) malloc(numsSize * sizeof(int));
    int* storeRight = (int*) malloc(numsSize * sizeof(int));
    for(int i=0; i<numsSize; i++) {
        if(i == 0 || i == 1) {
            storeLeft[i] = nums[i];
            printf("storeLeft is %d\n",storeLeft[i]);
        }
        else if(i == 2) {
            storeLeft[i] = nums[0] * nums[1];
            printf("storeLeft is %d\n",storeLeft[i]);
        }
        else{
            storeLeft[i] = storeLeft[i-1] * nums[i-1];
            printf("storeLeft is %d\n",storeLeft[i]);        
        }

    }
    for(int j=numsSize-1; j>=0; j--) {
        if(j==numsSize-1) {
            ans[j] = storeLeft[j];
        }
        else if(j==numsSize-2) {
            storeRight[j] = nums[j+1];
            ans[j] = storeLeft[j] * storeRight[j];
        }
        else {
            storeRight[j] = nums[j+1] * storeRight[j+1];
            if(j==1) {
                ans[j] = nums[j-1] * storeRight[j];
            }
            else if(j==0) {
                ans[j] = storeRight[j];
            }
            else {
                ans[j] = storeLeft[j] * storeRight[j];
            }
            
        }
    }
    return ans;
}