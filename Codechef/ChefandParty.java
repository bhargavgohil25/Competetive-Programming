//package com.company;

import java.lang.String;
import java.lang.System;
import java.util.*;
class ChefandParty
{
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        while(test-->0){
            int N = scan.nextInt();
            int []a = new int [N];
            for(int i=0;i<N;i++){
                a[i] = scan.nextInt();
            }
            Arrays.sort(a);
            int count=0;
            for(int i=0;i<N;i++){
                if(count>=a[i]){
                    count++;
                }
            }
            System.out.println(count);
        }
        scan.close();
    }
}
