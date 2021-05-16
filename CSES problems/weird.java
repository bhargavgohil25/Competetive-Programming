//import java.io.*;
import java.util.*;
/*
* Author: Bhargav Gohil
*/

public class weird {
    public static void main(String[] args){
        try{
            Scanner scan = new Scanner(System.in);
            long N = scan.nextLong();
            System.out.print(N+" ");
            while(N != 1){
                if(N%2 == 0){
                    N = N/2;
                }else{
                    N = N * 3;
                    N++;
                }
                System.out.print(N+" ");
            }
            scan.close();
        }
        catch(Exception E){
            //System.out.println(E);
        }
    }        
}