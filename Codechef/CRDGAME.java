import java.util.Scanner;

/**
 * long2
 */
//Author Bhargav Gohil
public class CRDGAME {

    static int solve(int N) {
        int sum = 0;
        while(N != 0){
            sum = (sum + N % 10);
            N = N/10;
        }
        return sum;
    } 

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        while(test-->0){
            int N = scan.nextInt();
            int M = 0;
            int C = 0;
            while(N-->0){
                int A = scan.nextInt();
                int B = scan.nextInt();
                A = solve(A);
                B = solve(B);
                if(A>B){
                    C++;
                }else if(B>A){
                    M++;
                }else{
                    C++;
                    M++;
                }
            }
            if(C>M){
                System.out.println("0 "+ C);
            }else if(M>C){
                System.out.println("1 "+ M);
            }else{
                System.out.println("2 "+ M);
            }
            
        }
        scan.close();
    }
}