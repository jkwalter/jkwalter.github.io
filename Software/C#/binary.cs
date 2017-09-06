/*
Compiling and Running in Microsoft Visual Studio:

 - Open Developer Command Prompt for Visual Studio
 - Navigate to the same directory as binary.cs
      cd "C:\Users\Josh Walter\Documents\Visual Studio 2017\Projects"
 - Type the following to compile binary.cs
      csc binary.cs
 - Type the following to run binary.cs
      binary
*/

class binary
{
	public static void Main()
	{
        int decimal_number;
        System.Collections.Generic.List<int> binary_number = new System.Collections.Generic.List<int>();

        do
        {
            System.Console.Write("Enter a number greater than 0: ");
            decimal_number = int.Parse(System.Console.ReadLine());
        } while (decimal_number < 1);

        System.Console.WriteLine();

        System.Console.WriteLine("Decimal Number: {0}", decimal_number);

        while (decimal_number != 0)
        {
            binary_number.Add(decimal_number % 2);
            decimal_number = decimal_number / 2;
        }

        System.Console.Write("Binary Representation: ");

        binary_number.Reverse();

        foreach(int digit in binary_number)
        {
            System.Console.Write(digit);
        }

        System.Console.WriteLine();

        binary_number.Clear();
	}
}
