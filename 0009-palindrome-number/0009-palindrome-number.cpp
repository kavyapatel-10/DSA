class Solution {
public:
    bool isPalindrome(int x) {
        
        
        long long revnum = 0;
        int dup = x;
        while(x>0){

          int ld = x % 10;
         
          revnum = revnum * 10 + ld;  

           x = x/10;
        }

        if(revnum == dup){
            return true;
        }else{
            return false;
        }
    }
};