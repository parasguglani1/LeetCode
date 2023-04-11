class Solution {
    public String removeStars(String s) {
        String ans="";
        int n= s.length();
        int count=0;
        for(int i=n-1; i>=0; i--){
            if(s.charAt(i)=='*'){
                count++;
            }
            else{
                if(count==0){
                    ans=  s.charAt(i)+ ans;
                }
                else{
                 count--;
                }
            }
        }
        return ans;
    }
}
