
import java.util.*;


class PSHOT{

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        while(test-->0){
            int n = scan.nextInt();
            String score = scan.next();
            int chanceA=n,chanceB=n;
            int countA=0,countB=0;
            for(int i=0;i<2*n;i++){
                if(i%2==0){
                    if(score.charAt(i)=='1'){
                        countA++;
                    }
                    chanceA--;
                }
                else{
                    if(score.charAt(i)=='1'){
                        countB++;
                    }
                    chanceB--;
                }
              if((countA)>countB+chanceB){
                  System.out.println(i+1);
                  break;
              }
              else if((countB)>countA+chanceA){
                  System.out.println(i+1);
                  break;
              }
              else if(countA==countB && i==2*n-1){
                  System.out.println(i+1);
                  break;
              }
            }
        }
        scan.close();
    }
}
