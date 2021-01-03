import java.util.*;

class WALKFAST{

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        while(test-->0){
            int N=scan.nextInt();
            int A=scan.nextInt();
            int B=scan.nextInt();
            int C=scan.nextInt();
            int D=scan.nextInt();
            int P=scan.nextInt();
            int Q=scan.nextInt();
            int Y=scan.nextInt();
            int [] X = new int [N+1];
            for(int i=1;i<=N;i++){
                X[i]=scan.nextInt();
            }
            int A_B=Math.abs(((X[A]-X[B])*P));
            int A_C=Math.abs(((X[A]-X[C])*P));
            int C_D=Math.abs(((X[C]-X[D])*Q));
            int D_B=Math.abs(((X[D]-X[B])*P));
            int res=0;
            if(Y>=A_C){
                res=Y+C_D+D_B;
                if(res>A_B){
                    res=A_B;
                }
            }
            else{
                res=A_B;
            }
            System.out.println(res);
        }
        scan.close();
    }
}
