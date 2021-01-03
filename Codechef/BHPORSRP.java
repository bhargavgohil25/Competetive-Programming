import java.io.*;
import java.util.*;
/*
* Author: Bhargav Gohil
*/

public class BHPORSRP {
    public static void main(String[] args){
        try{
            BufferedReader scan =new BufferedReader(new InputStreamReader(System.in));
            int test = Integer.parseInt(scan.readLine());
            while(test-->0){
                String normal  = scan.readLine();
                String lower = normal.toLowerCase();
                if(lower.contains("berhampore") && lower.contains("serampore")){
                    System.out.println("Both");
                }else if(lower.contains("serampore")){
                    System.out.println("GCETTS");
                }else if(lower.contains("berhampore")){
                    System.out.println("GCETTB");
                }else{
                    System.out.println("Others");
                }
            }
            scan.close();
        }
        catch(Exception E){
            //System.out.println(E);
        }
    }        
}