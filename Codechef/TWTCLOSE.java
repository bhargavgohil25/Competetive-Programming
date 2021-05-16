

import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;

class TWTCLOSE {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int N = scan.nextInt();
        int K = scan.nextInt();
        scan.nextLine();
        String[] clicks = new String[K];
        for (int i = 0; i < clicks.length; i++) {
            clicks[i] = scan.nextLine();
        }
        System.out.print(solve(N, clicks));

        scan.close();
    }

    static String solve(int N, String[] clicks) {
        boolean[] opens = new boolean[N + 1];
        int count = 0; 
        int[] result = new int[clicks.length];
        for (int i = 0; i < result.length; i++) {
            if (clicks[i].equals("CLOSEALL")) {
                count = 0;
                Arrays.fill(opens, false);
            } else {
                int num = Integer.parseInt(clicks[i].split(" ")[1]); 

                if (opens[num]) {
                    count--;
                } else {
                    count++;
                }

                opens[num] =!opens[num];
            }

            result[i] = count;
        }

        return Arrays.stream(result).mapToObj(String::valueOf).collect(Collectors.joining("\n"));
    }
}
