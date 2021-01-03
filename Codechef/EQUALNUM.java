import java.io.*;
import java.util.*;
/*
* Author: Bhargav Gohil
*/

public class EQUALNUM {
    public static void main(String[] args){
        try{
            Scanner scan = new Scanner(System.in);
            int test = scan.nextInt();
            while(test-->0){
                String world = scan.next();
                String india = scan.next();
                world = world.replace(",","");
                india = india.replace(",","");
                System.out.println(world.equals(india) ? "equal" : "different");
            }
            scan.close();
        }
        catch(Exception E){
            //System.out.println(E);
        }
    }        
}