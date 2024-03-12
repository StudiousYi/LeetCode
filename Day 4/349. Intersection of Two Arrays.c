/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int* xp, int* yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of 
    // unsorted subarray 
    for (i = 0; i < n - 1; i++) { 
        // Find the minimum element in 
        // unsorted array 
        min_idx = i; 
        for (j = i + 1; j < n; j++) 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
  
        // Swap the found minimum element 
        // with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
}

// Function to print an array 
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    //sort the 2 given arrays in ascending order
    selectionSort(nums1, nums1Size);
    selectionSort(nums2, nums2Size);
    printArray(nums1, nums1Size);
    printArray(nums2, nums2Size); 

    int* ans = (int*) malloc (nums1Size * sizeof(int) );
    int index = 0;

    if(nums1Size > nums2Size) {
        for (int i=0; i< nums2Size; i++) {
            for(int j=0 ; j<nums1Size; j++) {
                if (nums1[j] == nums2[i] ) {
                    int found = 0;
                    for(int k=0; k < index; k++) {
                        if(ans[k] == nums1[j] ) {
                            found = 1;
                            break;
                        }
                    }
                    if(found == 0) {
                        ans[index++] = nums1[j];
                    }
                    break;
                }
            }
        }
    }
    else {
        for (int i=0; i< nums1Size; i++) {
            for(int j=0 ; j<nums2Size; j++) {
                if (nums1[i] == nums2[j] ) {
                    int found = 0;
                    for(int k=0; k < index; k++) {
                        if(ans[k] == nums1[i] ) {
                            found = 1;
                            break;
                        }
                    }
                    if(found == 0) {
                        ans[index++] = nums1[i];
                    }
                    break;
                }
            }
        }
    }

    *returnSize = index;
    ans = (int*) realloc ( ans, index * sizeof(int) );
    return ans;
}