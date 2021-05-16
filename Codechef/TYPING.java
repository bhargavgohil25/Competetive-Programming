// Nice Question 




//package com.company;

import java.util.ArrayList;
import java.util.Scanner;

class TYPING
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        ArrayList<String> collectionOfWords = new ArrayList<>();
        while(test-->0){
            int numWords = scan.nextInt();
            collectionOfWords.clear();
            int []count = new int [numWords];
            for(int i=0;i<numWords;++i){
                String newWord = scan.next();
                if(collectionOfWords.contains(newWord)){
                    count[i]=count[i]+count[collectionOfWords.indexOf(newWord)];
                    collectionOfWords.add(newWord);
                }
                else{
                    collectionOfWords.add(newWord);
                    count[i]+=2;
                    for(int j=1;j<collectionOfWords.get(i).length();++j){
                        count[i]+=2;
                        if((collectionOfWords.get(i).charAt(j)=='d' || collectionOfWords.get(i).charAt(j)=='f')
                                && (collectionOfWords.get(i).charAt(j-1)=='d' ||  collectionOfWords.get(i).charAt(j-1)=='f')){

                            count[i]+=2;
                        }
                        else if((collectionOfWords.get(i).charAt(j)=='j' || collectionOfWords.get(i).charAt(j)=='k')
                                && (collectionOfWords.get(i).charAt(j-1)=='j' ||  collectionOfWords.get(i).charAt(j-1)=='k')){

                            count[i]+=2;
                        }
                    }
                }
            }
            int sum=0;
            for(int i=0;i<numWords;i++){
                sum=sum+count[i];
            }
            System.out.println(sum);
        }
        scan.close();
    }
}
