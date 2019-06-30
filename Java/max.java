import java.util.Random;

public class max
{
	public static void main(String[] args)
	{
		int[] A = new int[10];
		int i;
		int max = 0;
		Random rand = new Random();

		for (i = 0; i < 10; i++)
		{
			A[i] = rand.nextInt(15);
			if (A[i] > max)
			{
				max = A[i];
			}
			System.out.print(A[i] + " ");
		}

		System.out.println();
		System.out.println("Max: " + max);
	}
}
