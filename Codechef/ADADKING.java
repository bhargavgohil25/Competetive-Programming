import java.util.*;
//import java.lang.*;
//import java.io.*;

/**
 * long3
 */
//Author Bhargav
class ADAKING {

    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        //int [][] A = new int [9][9];
        while(test-->0){
            int N = scan.nextInt();
            for(int i=0; i<64; i++){
                if(i%8 == 0 && i!=0){
                    System.out.println();
                }
                if(i == 0){
                    System.out.print("O");
                }else if(i<N){
                    System.out.print(".");
                }else{
                    System.out.print("X");
                }
            }
            System.out.println();
        }
        scan.close();
    }
}
