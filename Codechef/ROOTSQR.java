import java.io.*;
import java.util.*;
/*
* Author: Bhargav Gohil
*/

public class ROOTSQR {
    public static void main(String[] args){
        try{
            Scanner scan = new Scanner(System.in);
            int test = scan.nextInt();
            int X = scan.nextInt();
            while(test-->0){
                long n = scan.nextLong();
                if(n < 0){
                    System.out.println("no");
                    continue;
                }
                long squareRoot = (int)Math.sqrt(n);
                squareRoot = squareRoot * squareRoot;
                long diff = n - squareRoot;
                long per = (X * n)/100;
                System.out.println(diff<=per ? "yes" : "no");
            }
            scan.close();
        }
        catch(Exception E){
            //System.out.println(E);
        }
    }        
}