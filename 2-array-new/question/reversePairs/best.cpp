
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        
        for (int i = low; i <= mid; i++) {
            
            /*while right is less than equal to high 
           and arr[i] is greater than 2 * arr[right] 
           then increment right by 1*/
            while (right <= high && arr[i] > 2 * arr[right]) right++;
            
            cnt += (right - (mid + 1));
        }
        //Return the count
        return cnt;
    }
  void merge(vector<int>& arr, int low, int mid, int high) {
        
        vector<int> temp; 
        int left = low;  
        int right = mid + 1; 

        // Merge and count reverse pairs
        while (left <= mid && right <= high) {
            
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } 
            else {
                temp.push_back(arr[right]);
                right++;
                
            }
        }

   
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

      
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

      
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
     int mergeSort(vector<int>& arr, int low, int high) {
        int cnt = 0;
        if(low >= high){
            return cnt;
        }
        int mid = low + (high - low) / 2;
            
        cnt += mergeSort(arr, low, mid); 
        cnt += mergeSort(arr, mid + 1, high);
        
        cnt += countPairs(arr, low, mid, high);
            
        merge(arr, low, mid, high); 
        
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
         return mergeSort(nums, 0, n - 1);
    }
};