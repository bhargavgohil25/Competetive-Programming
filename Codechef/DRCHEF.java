import java.util.*;

//import java.util.*;
/**
 * DRCHEF
 */
//Author: Bhargav Gohil

public class DRCHEF {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        
        while(test-->0){
            int minDays = 0;
            int N = scan.nextInt();
            int X = scan.nextInt();
            //int []arr = new int [N];
            ArrayList <Integer> arr = new ArrayList<Integer>();
            for(int i=0; i<N; i++){
                //arr[i] = scan.nextInt();
                int t = scan.nextInt();
                arr.add(t);
            }
            Collections.sort(arr);
            for(int i=0; i<N; i++){
                if(X >= arr.get(i)){
                    minDays++;
                    X = Math.max(X, 2 * arr.get(i));
                    continue;
                }
                int temp = arr.get(i);

                while(temp > 0){
                    minDays++;
                    temp = Math.min(temp, 2 * (temp - X));
                    X = X * 2;
                }
                X = 2 * arr.get(i);
            }

            System.out.println(minDays);
            
        }
        scan.close();
    }
}