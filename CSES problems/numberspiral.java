//import java.io.*;
import java.util.*;
/*
* Author: Bhargav Gohil
*/

public class numberspiral {
    public static void main(String[] args){
        try{
            Scanner scan = new Scanner(System.in);
            
            long test = scan.nextLong();
            while(test-->0){
                long y = scan.nextLong();
                long x = scan.nextLong();
                
                if(y > x){
                    if(y%2 == 0){
                        System.out.println((y*y) - (x-1));
                    }else{
                        //long temp = (((y-1)*(y-1)) + 1);
                        System.out.println((((y-1)*(y-1))) + (x)); 
                    }
                }else if(x > y){
                    if(x%2 != 0){
                        System.out.println((x*x) - (y-1));
                    }else{
                        //long temp = ;
                        System.out.println(((x-1)*(x-1) ) + (y));
                    }
                }
            }
            
            scan.close();
        }
        catch(Exception E){
            //System.out.println(E);
        }
    }        
}