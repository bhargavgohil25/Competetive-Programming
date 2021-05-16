//package com.company;

//easy problem 
import java.util.*;

class CHF {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        while(test-->0){
            int minimum = Integer.MAX_VALUE;
            int n = scan.nextInt();
            int [] a = new int [n];
            for(int i=0;i<n;i++){
                a[i]=scan.nextInt();
                if(minimum>a[i]){
                    minimum=a[i];
                }
            }
            System.out.println(minimum);
        }
        scan.close();
    }
}
