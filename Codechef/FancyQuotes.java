import java.util.Arrays;
import java.util.Scanner;

public class FancyQuotes {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		sc.nextLine();
		for (int tc = 0; tc < T; tc++) {
			String S = sc.nextLine();

			System.out.println((Arrays.stream(S.split(" ")).anyMatch(word -> word.equals("not"))) ? "Real Fancy" : "regularly fancy");
		}

		sc.close();
	}
}
