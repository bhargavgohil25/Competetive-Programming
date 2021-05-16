package Hackerrank;

import java.io.*;
import java.util.*;
/*
* Author: Bhargav Gohil
*/

public class ArraySum {
    public static void main(String[] args){
        try{
            Scanner scan = new Scanner(System.in);
            int test = 1;
            while(test-->0){
                int n = scan.nextInt();
                int m = scan.nextInt();
                int arr [] = new int [n];
                for(int i=0;i<n;i++){
                    arr[i] = i+1;
                }
                //Arrays.sort(arr);
                for(int i=0;i<m;i++){
                    int num = scan.nextInt();
                    if(Arrays.binarySearch(arr, num) != -1){
                        int temp = arr[0];
                        arr[0] = arr[n-1];
                        arr[n-1] = temp;
                    }else{
                        arr[n-1] = num;
                    }
                    int sum = Arrays.stream(arr).sum();
                    System.out.println(sum);
                }

            }
            scan.close();
        }
        catch(Exception E){
            //System.out.println(E);
        }
    }        
}