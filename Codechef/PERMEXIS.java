import java.lang.Math;
import java.lang.String;
import java.lang.System;
import java.util.Arrays;
import java.util.Scanner;
//EASY PROBLEM
class PERMEXIS
{
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        while(test-->0){
            int N = scan.nextInt();
            int [] A = new int [N];
            for(int i=0;i<N;i++){
                A[i] = scan.nextInt();
            }
            boolean trigger = true;
            Arrays.sort(A);
            for(int i=0;i<N-1;i++){
                if(Math.abs(A[i+1]-A[i])>1){
                    trigger = false;
                    break;
                }
            }
            if(trigger==true){
                System.out.println("YES");
            }
            else{
                System.out.println("NO");
            }
            scan.close();

        }
    }
}
