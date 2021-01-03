import java.util.Scanner;

/**
 * PRICECON
 */
public class PRICECON {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        while(test-->0){
            int N = scan.nextInt();
            int K = scan.nextInt();
            int items[] = new int [N];
            
            for(int i=0; i<N; i++){
                items[i] = scan.nextInt();
            }

            int loss = 0;

            for(int i=0; i<N; i++){
                if(items[i] > K){
                    loss = loss + (items[i] - K);
                }
            }
            System.out.println(loss);
        }
        scan.close();
    }
}