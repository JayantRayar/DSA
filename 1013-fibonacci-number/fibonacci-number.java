class Solution {
    public int fib(int n) {
        if(n==0){
            return 0;
        }else if(n==1){
            return 1;
        }
        int F_one = 0;
        int F_two = 1;

        for(int i=0; i<n; i++){
            int F_three = F_one + F_two;
            F_one = F_two;
            F_two = F_three;
        } 
        return F_one;
    }
}