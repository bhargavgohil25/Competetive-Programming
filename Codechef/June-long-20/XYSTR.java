import java.util.Scanner;

/**
 * XYSTR
 */
public class XYSTR {

    static int solve(String S){
        //String S = scan.next();
        int count = 0;
        if(S.length() <= 1){
            //System.out.println("0");
            return 0;
        }
        /*
        else if(S.length() == 2){

            if(S.charAt(0) == S.charAt(1)){
                //System.out.println("0");
                return 0;
            }else{
                //System.out.println("1");
                return 1;
            }
        }
        */

        for(int i=0; i<S.length()-1;){
            if(S.charAt(i) != S.charAt(i+1)){
                count++;
                i+=2;
            }
            else {
                i++;
            }
        }
        //System.out.println(count);
        return count;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int test = scan.nextInt();
        while(test-->0){
            String S = scan.next();
            System.out.println(solve(S));
        }
        scan.close();
    }
}