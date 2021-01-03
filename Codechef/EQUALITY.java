//package com.company;
import java.lang.String;
import java.lang.System;
import java.util.*;
//Easy Problem
class EQUALITY
{
    public static void main(String args[]) throws java.lang.Exception
    {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        while(test-->0){
            int N = scan.nextInt();
            long []constants = new long [N];
            long sumOfArray =0;
            for(int i=0;i<N;i++){
                constants[i]=scan.nextLong();
                sumOfArray=sumOfArray+constants[i];
            }
            long part = (sumOfArray)/(N-1);
            for(int i=0;i<N;i++){
                long x = part-constants[i];
                System.out.print(x+" ");
            }
            System.out.println();
        }
        scan.close();
    }
}
