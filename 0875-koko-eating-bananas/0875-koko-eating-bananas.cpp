class Solution {
public:


    long long counthours(vector<int>& arr,int hourly){
        long totalhours = 0;
        int n = arr.size();
        for(int i = 0; i < n ; i++){
            totalhours += ceil((double)arr[i]/(double)hourly);
        }

        return totalhours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low <= high){
            int mid = low + (high - low)/2;


            long long takenhours = counthours(piles,mid);
            if(takenhours <= h){
                high = mid-1;
            }else {
                
                low = mid + 1;
            }
        }

        return low;
    }
};