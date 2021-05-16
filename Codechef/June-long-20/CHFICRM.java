import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 * CHFICMR
 */
public class CHFICRM {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        while(test-->0){
            int n = scan.nextInt();
            //cin>>n;


            int arr[] = new int [n+9];
            int c5=0,c10=0,c15=0;

            for(int i=0; i<n; i++){
                arr[i] = scan.nextInt();
            }
            for(int i=0; i<n; i++){
                if(arr[i]==5) c5++;
                if(arr[i]==10){
                    if(c5>0){ c5--; c10++; continue; }
                    else{ System.out.println("NO"); return;  } 
                }
                if(arr[i]==15){
                    if(c10>0){ c10--; c15++; continue; }
                    if(c5>=2){ c5--; c5--; c15++; continue; }
                    else{ System.out.println("NO"); return;  }
            }
        }
        System.out.println("YES");
        
        }
        scan.close();
    }
        
}
