#include "selection_sort.h"


namespace SORT{
    namespace SELECTION_SORT{
    /*The selection sort algorithm sorts an array by repeatedly find the minimum elemments(considering ascending order)
    from unsorted part and putting it at the beging. The algorithm maintains two subarrays in a given array:
    1) The subarray which is already sorted.
    2) Remaining subarray which is unsorted.
    */
    template<typename T>
    void unstableSelectionSortKernel(T arr[], unsigned int n){
        unsigned int i,j,min_ele_idx;
        // a[0]...a[i-1] is the sorted subarray
        for(i = 0; i < n-1; i++){
            min_ele_idx = i;
            // a[i]...a[n-1] is the unsorted subarray
            for( j = i+1; j < n; j++){
                // find the minimum element from the unsorted subarray
                if(arr[j] < arr[min_ele_idx]){
                    min_ele_idx = j;
                }
            }
            // append the minimum element of the unsorted subarray to the sorted subarray
            // NOTE: this swap operation makes selection sort algorithm unstable
            SORT::UTILS::swap<T>(&arr[i],&arr[min_ele_idx]);

        }
    }
    template<typename T>
    void stableSelectionSortKernel(T arr[], unsigned int n){
        unsigned int i,j,min_ele_idx;
        // a[0]...a[i-1] is the sorted subarray
        for(i = 0; i < n-1; i++){
            min_ele_idx = i;
            // a[i]...a[n-1] is the unsorted subarray
            for( j = i+1; j < n; j++){
                // find the minimum element from the unsorted subarray
                if(arr[j] < arr[min_ele_idx]){
                    min_ele_idx = j;
                }
                // append the minimum element of the unsorted subarray to the sorted subarray
//                if(min_ele_idx != i){
//                    // NOTE: this swap operation makes selection sort algorithm unstable
//                    SORT::UTILS::swap<T>(&arr[i],&arr[min_ele_idx]);
//                }
            }
            // if want selection sort be stable, should move elements i,i+1,....,min_ele_idx-1,sequencely
            // but this need more move operation
            T min_ele = arr[min_ele_idx];
            while(min_ele_idx > i){
                arr[min_ele_idx] = arr[min_ele_idx-1];
                min_ele_idx--;
            }
            arr[i] = min_ele;
        }
    }

    template<typename T>
    void selectionSortKernel(T arr[], unsigned int n){
        unstableSelectionSortKernel(arr, n);
    }
    template  void selectionSortKernel<short>(short arr[], unsigned int n);
    template  void selectionSortKernel<unsigned short>(unsigned short arr[], unsigned int n);

    template  void selectionSortKernel<int>(int arr[], unsigned int n);
    template  void selectionSortKernel<unsigned int>(unsigned int arr[], unsigned int n);

    template  void selectionSortKernel<long>(long arr[], unsigned int n);
    template  void selectionSortKernel<unsigned long>(unsigned long arr[], unsigned int n);

    template  void selectionSortKernel<long long>(long long arr[], unsigned int n);
    template  void selectionSortKernel<unsigned long long>(unsigned long long arr[], unsigned int n);

    template  void selectionSortKernel<float>(float arr[], unsigned int n);
    template  void selectionSortKernel<double>(double arr[], unsigned int n);
    }
}

