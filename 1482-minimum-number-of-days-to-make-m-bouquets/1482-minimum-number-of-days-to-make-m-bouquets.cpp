class Solution {
public:


    bool possible(vector<int>& bloomDay,int days,int m,int k){

        int n = bloomDay.size();
        int counter = 0;
        int noofBuckets = 0;
        for(int i = 0; i < n; i++){
            if(bloomDay[i]<=days){
                counter++;
            }else{
                
                noofBuckets += (counter/k);
                counter = 0;
            }
        }
        noofBuckets += (counter/k);

        if(noofBuckets >= m) {
            return true;
        }else{
            
            return false;
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        long long val = m*1LL*k*1LL;
        if(val>n){
            return -1;
        }

        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = high;
        while(low <= high){
            int mid = low +(high - low)/2;

            if(possible(bloomDay,mid,m,k)){
                ans=mid;
                high = mid - 1;
            }else{
                low = mid+1;
            }
        }
    return ans;
    }
};