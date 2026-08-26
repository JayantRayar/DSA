class Solution {
    public boolean isPalindrome(int x) {
        String s = Integer.toString(x);
        String pal="";
        for(int i=s.length()-1; i>=0; i--){
            pal=pal + s.charAt(i);
        }
        if(s.equals(pal)){
            return true;
        }
        else{
            return false;
        }
    }
}