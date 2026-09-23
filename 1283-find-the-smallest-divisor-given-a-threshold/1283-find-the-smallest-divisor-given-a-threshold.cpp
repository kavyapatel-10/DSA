class Solution {
public:


    int sumofdivisors(vector<int>& arr,int divisor){
        int sum = 0;
        int n = arr.size();
        for(int i =0;i<n;i++){
            sum += ceil((double)(arr[i])/(double)(divisor));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());

        while(low <= high){
            int mid = low + (high - low )/2;

            if(sumofdivisors(nums,mid) <= threshold){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};