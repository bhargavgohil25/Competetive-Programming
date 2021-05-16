import java.io.*;
import java.util.*;
/*
* Author: Bhargav Gohil
*/

public class CLLCM {
    public static void main(String[] args){
        try{
            Scanner scan = new Scanner(System.in);
            int test = scan.nextInt();
            while(test-->0){
                boolean check = true;
                int n = scan.nextInt();
                for(int i=0; i<n; i++){
                    int temp = scan.nextInt();
                    if(temp % 2 == 0){
                        check = false;
                    }
                }
                
                System.out.println((check == false) ? "NO" : "YES");

            }
            scan.close();
        }
        catch(Exception E){
            //System.out.println(E);
        }
    }        
}