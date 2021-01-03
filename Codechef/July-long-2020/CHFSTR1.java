import java.util.Scanner;

/**
 * long1
 */

//Author Bhargav Gohil
public class CHFSTR1 {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        while(test-->0){
            int N = scan.nextInt();
            int []arr = new int [N];
            for(int i=0; i<N; i++){
                arr[i] = scan.nextInt();
            }
            long count = 0;
            for(int i=0; i<N - 1; i++){
                count = count + Math.abs(arr[i] - arr[i+1]) - 1;
            }
            System.out.println(count);
        }
        scan.close();
    }
}