import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * long4
 */
public class PTMSSNG {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        while(test-->0){
            int N = scan.nextInt();
            Set <Integer> X = new HashSet<>();
            Set <Integer> Y = new HashSet<>();

            for(int i=0; i<4*N-1; i++){
                int a = scan.nextInt();
                int b = scan.nextInt();

                //Check for every X-coordinate of each given point.
                if(X.contains(a)){
                    X.remove(a);
                }                
                else{
                    X.add(a);
                }

                //Check for every Y-coordinate of each given point.
                if(Y.contains(b)){
                    Y.remove(b);
                }
                else{
                    Y.add(b);
                }

            }

            //printing the point in X set and Y set
            X.forEach(System.out::print);
            System.out.print(" ");
            Y.forEach(System.out::print);
            System.out.println();
        }
        scan.close();
    }
}