import java.util.Scanner;

/**
 * EVENM
 */
public class EVENM {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        while (test-->0) {
            int N = scan.nextInt();
            int count = 1;
            for(int i=1; i<=N; i++){
                if(i%2!=0){
                    if(i!=1){
                        count += N + 1;
                    }
                    for(int j=1; j<=N; j++){
                        System.out.print(count+" ");
                        count++;
                    }
                    System.out.print("\n");
                }
                else{
                    count+=N-1;
                    for(int j=N; j>=1; j--){
                        System.out.println(count+" ");
                        count--;
                    }
                    System.out.print("\n");
                }
            }

        }
        scan.close();
    }
}