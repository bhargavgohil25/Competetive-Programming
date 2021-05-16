//import java.io.*;
import java.util.*;
/*
* Author: Bhargav Gohil
*/

public class missing {
    public static void main(String[] args){
        try{
            Scanner scan = new Scanner(System.in);
            int N = scan.nextInt();
            int []arr = new int [(N - 1)];
            int []freq = new int [200001];
            Arrays.fill(freq, 0);
            for(int i=0; i<N-1; i++){
                arr[i] = scan.nextInt();
                freq[arr[i]]++;
            }

            Arrays.sort(arr);

            for (int i = 1; i < 200001; i++) {
                if(freq[i] == 0){
                    System.out.print(i);
                    break;
                }
                
            }
            scan.close();
        }
        catch(Exception E){
            //System.out.println(E);
        }
    }        
}