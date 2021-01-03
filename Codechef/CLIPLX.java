import java.util.Scanner;

class CLIPLX {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int Test = scan.nextInt();
		for (int i = 0; i < Test; i++) {
			int X = scan.nextInt();
			int Y = scan.nextInt();

			System.out.println(solve(X, Y));
		}

		scan.close();
	}

	static int solve(int X, int Y) {
		return Math.max(0, X - Y);
	}
}
