import java.util.Scanner;

/**
 * EOEO
 */
public class EOEO {
    public static void main(final String[] args) {
        final Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        while(test-->0){
            long t = scan.nextLong();
            if(t%2 == 1){
                System.out.println((t-1)/2);
            }else{
                while(t%2 == 0){
                    t = t/2;
                }
                System.out.println((long)t/2);
            }
        }
        scan.close();
    }
}