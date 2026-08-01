class Solution {
public:


    int solve(vector<int>& A, vector<int>& B,int k, int astart, int aend, int bstart, int bend ){

        if(aend < astart){
            return B[k - astart];
        }
        if(bend < bstart){
            return A[k-bstart];
        }

        int aindex  = (astart + aend) / 2, bindex = (bstart + bend)/2;
        int avalue = A[aindex] , bvalue = B[bindex];

        if(aindex + bindex < k){
            if(avalue > bvalue){
                return solve(A,B,k,astart,aend,bindex+1,bend);
            }else{
                return solve(A,B,k,aindex + 1,aend,bstart,bend);
            }
        }

        else{
            if(avalue > bvalue){
                return solve(A,B,k,astart,aindex-1,bstart,bend);
            }else{
                return solve(A,B,k,astart,aend,bstart,bindex-1);
            }
        }
        return -1;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int la = int(nums1.size()), lb = int(nums2.size());

        int n = la + lb;

        if(n%2){
            return solve(nums1,nums2,n/2,0,la-1,0,lb-1);
        }else{

            return 1.0 * (solve(nums1,nums2,n/2-1,0,la-1,0,lb-1)+
                          solve(nums1,nums2,n/2,0,la-1,0,lb-1)) / 2;
        }
    }
};