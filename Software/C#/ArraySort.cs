/*
Compiling and Running in Microsoft Visual Studio:

 - Open Developer Command Prompt for Visual Studio
 - Navigate to the same directory as ArraySort.cs
      cd "C:\Users\Josh Walter\source\repos\jkwalter.github.io\Software\C#"
 - Type the following to compile ArraySort.cs
      csc ArraySort.cs
 - Type the following to run ArraySort.cs
      ArraySort
*/

using System;

public class ArraySort
{
	public static void Main()
	{
        int i;
        int[] list = new int[25];
        Random number = new Random();

        for (i = 0; i < 25; i++)
        {
            list[i] = number.Next(10);
        }

        foreach (int value in list)
        {
            Console.Write(value + " ");
        }

        Console.WriteLine();

        Array.Sort(list);

        foreach (int value in list)
        {
            Console.Write(value + " ");
        }

        Console.WriteLine();
	}
}