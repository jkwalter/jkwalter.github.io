/*
Compiling and Running in Microsoft Visual Studio:

 - Open Developer Command Prompt for Visual Studio
 - Navigate to the same directory as battle.cs
      cd "C:\Users\Josh Walter\Documents\Visual Studio 2017\Projects"
 - Type the following to compile battle.cs
      csc battle.cs
 - Type the following to run battle.cs
      battle
*/

class Character
{
	private int myHealth = 0;
	private int attackValue = 0;
	private int healValue = 0;

	public int Health
	{
		get
		{
			return myHealth;
		}
		set
		{
			myHealth = value;
		}
	}

	public int Attack
	{
		get
		{
			return attackValue;
		}
		set
		{
			attackValue = value;
		}
	}

	public int Heal
	{
		get
		{
			return healValue;
		}
		set
		{
			healValue = value;
		}
	}

	public static void Main()
	{
		Character Protagonist = new Character();
		Character Antagonist = new Character();
		System.ConsoleKey Choice;
		System.ConsoleKey Key;
		System.ConsoleKey Enter;
		int Coin = 0;
		int Option = 0;
		int FirstTurn = 0;
		int Dice1;
		int Dice2;
		System.Random Roll = new System.Random();
		System.Random AntagonistDecision = new System.Random();
		System.Random Toss = new System.Random();

		System.Console.Clear();

		Protagonist.Health = 50;
		Antagonist.Health = 50;

		Coin = Toss.Next(2);
		FirstTurn = Coin;

		do
		{
			if (Coin == 0)
			{
				if (Protagonist.Health != 0)
				{
					if (FirstTurn == 0)
					{
						System.Console.WriteLine("   PROTAGONIST HEALTH: {0}", Protagonist.Health);
						System.Console.WriteLine("    ANTAGONIST HEALTH: {0}", Antagonist.Health);
						System.Console.WriteLine();
						System.Console.Write("Enter any key to continue: ");
						Key = System.Console.ReadKey().Key;
						Enter = System.Console.ReadKey().Key;
						System.Console.WriteLine();
						System.Console.WriteLine();
					}
					do
					{
						System.Console.WriteLine("PROTAGONIST OPTIONS");
						System.Console.WriteLine();
						System.Console.WriteLine("   1: Attack");
						System.Console.WriteLine("   2: Heal");
						System.Console.WriteLine();
						System.Console.Write("Enter your option here (1 or 2): ");
						Choice = System.Console.ReadKey().Key;
						Enter = System.Console.ReadKey().Key;
						System.Console.WriteLine();
						System.Console.WriteLine();
					} while (Choice != System.ConsoleKey.D1 && Choice != System.ConsoleKey.D2);
					if (Choice == System.ConsoleKey.D1)
					{
						Option = 1;
					}
					if (Choice == System.ConsoleKey.D2)
					{
						Option = 2;
					}
					switch (Option)
					{
						case 1:
							Dice1 = Roll.Next(6) + 1;
							Dice2 = Roll.Next(6) + 1;
                            if (Dice1 + Dice2 == 2 || Dice1 + Dice2 == 12)
                            {
                                Protagonist.Attack = 20;
                            }
                            if (Dice1 + Dice2 == 3 || Dice1 + Dice2 == 11)
                            {
                                Protagonist.Attack = 14;
                            }
                            if (Dice1 + Dice2 == 4 || Dice1 + Dice2 == 10)
                            {
                                Protagonist.Attack = 10;
                            }
                            if (Dice1 + Dice2 == 5 || Dice1 + Dice2 == 9)
                            {
                                Protagonist.Attack = 6;
                            }
                            if (Dice1 + Dice2 == 6 || Dice1 + Dice2 == 8)
                            {
                                Protagonist.Attack = 6;
                            }
                            if (Dice1 + Dice2 == 7)
                            {
                                Protagonist.Attack = 10;
                            }
                            if (Antagonist.Health < Protagonist.Attack)
                            {
                                Antagonist.Health = 0;
                            }
                            else
                            {
                                Antagonist.Health = Antagonist.Health - Protagonist.Attack;
                            }
                            System.Console.WriteLine("Protagonist deals {0} damage.", Protagonist.Attack);
                            break;
                        case 2:
                            Dice1 = Roll.Next(6) + 1;
                            Dice2 = Roll.Next(6) + 1;
                            if (Dice1 + Dice2 == 2 || Dice1 + Dice2 == 12)
                            {
                                Protagonist.Heal = 20;
                            }
                            if (Dice1 + Dice2 == 3 || Dice1 + Dice2 == 11)
                            {
                                Protagonist.Heal = 14;
                            }
                            if (Dice1 + Dice2 == 4 || Dice1 + Dice2 == 10)
                            {
                                Protagonist.Heal = 10;
                            }
                            if (Dice1 + Dice2 == 5 || Dice1 + Dice2 == 9)
                            {
                                Protagonist.Heal = 6;
                            }
                            if (Dice1 + Dice2 == 6 || Dice1 + Dice2 == 8)
                            {
                                Protagonist.Heal = 6;
                            }
                            if (Dice1 + Dice2 == 7)
                            {
                                Protagonist.Heal = 10;
                            }
                            if (Protagonist.Health + Protagonist.Heal > 50)
                            {
                                Protagonist.Health = 50;
                            }
                            else
                            {
                                Protagonist.Health = Protagonist.Health + Protagonist.Heal;
                            }
                            System.Console.WriteLine("Protagonist restores {0} health.", Protagonist.Heal);
                            break;
                    }
                    System.Console.WriteLine();
                    System.Console.Write("Enter any key to continue: ");
                    Key = System.Console.ReadKey().Key;
                    Enter = System.Console.ReadKey().Key;
                    System.Console.WriteLine();
                    System.Console.WriteLine();
                    Coin = 1;
                }
            }
            if (Coin == 1)
            {
                if (Antagonist.Health != 0)
                {
                    if (FirstTurn == 1)
                    {
                        System.Console.WriteLine("   PROTAGONIST HEALTH: {0}", Protagonist.Health);
                        System.Console.WriteLine("    ANTAGONIST HEALTH: {0}", Antagonist.Health);
                        System.Console.WriteLine();
                        System.Console.Write("Enter any key to continue: ");
                        Key = System.Console.ReadKey().Key;
                        Enter = System.Console.ReadKey().Key;
                        System.Console.WriteLine();
                        System.Console.WriteLine();
                    }
                    if (Antagonist.Health < 20)
                    {
                        Option = AntagonistDecision.Next(10);
                        if (Option < 4)
                        {
                            Option = 1;
                        }
                        else
                        {
                            Option = 2;
                        }
                    }
                    else
                    {
                        Option = AntagonistDecision.Next(10);
                        if (Option < 3)
                        {
                            Option = 2;
                        }
                        else
                        {
                            Option = 1;
                        }
                    }
                    switch (Option)
                    {
                        case 1:
                            Dice1 = Roll.Next(6) + 1;
                            Dice2 = Roll.Next(6) + 1;
                            if (Dice1 + Dice2 == 2 || Dice1 + Dice2 == 12)
                            {
                                Antagonist.Attack = 20;
                            }
                            if (Dice1 + Dice2 == 3 || Dice1 + Dice2 == 11)
                            {
                                Antagonist.Attack = 14;
                            }
                            if (Dice1 + Dice2 == 4 || Dice1 + Dice2 == 10)
                            {
                                Antagonist.Attack = 10;
                            }
                            if (Dice1 + Dice2 == 5 || Dice1 + Dice2 == 9)
                            {
                                Antagonist.Attack = 6;
                            }
                            if (Dice1 + Dice2 == 6 || Dice1 + Dice2 == 8)
                            {
                                Antagonist.Attack = 6;
                            }
                            if (Dice1 + Dice2 == 7)
                            {
                                Antagonist.Attack = 10;
                            }
                            if (Protagonist.Health < Antagonist.Attack)
                            {
                                Protagonist.Health = 0;
                            }
                            else
                            {
                                Protagonist.Health = Protagonist.Health - Antagonist.Attack;
                            }
                            System.Console.WriteLine("Antagonist deals {0} damage.", Antagonist.Attack);
                            break;
                        case 2:
                            Dice1 = Roll.Next(6) + 1;
                            Dice2 = Roll.Next(6) + 1;
                            if (Dice1 + Dice2 == 2 || Dice1 + Dice2 == 12)
                            {
                                Antagonist.Heal = 20;
                            }
                            if (Dice1 + Dice2 == 3 || Dice1 + Dice2 == 11)
                            {
                                Antagonist.Heal = 14;
                            }
                            if (Dice1 + Dice2 == 4 || Dice1 + Dice2 == 10)
                            {
                                Antagonist.Heal = 10;
                            }
                            if (Dice1 + Dice2 == 5 || Dice1 + Dice2 == 9)
                            {
                                Antagonist.Heal = 6;
                            }
                            if (Dice1 + Dice2 == 6 || Dice1 + Dice2 == 8)
                            {
                                Antagonist.Heal = 6;
                            }
                            if (Dice1 + Dice2 == 7)
                            {
                                Antagonist.Heal = 10;
                            }
                            if (Antagonist.Health + Antagonist.Heal > 50)
                            {
                                Antagonist.Health = 50;
                            }
                            else
                            {
                                Antagonist.Health = Antagonist.Health + Antagonist.Heal;
                            }
                            System.Console.WriteLine("Antagonist restores {0} health.", Antagonist.Heal);
                            break;
                    }
                    System.Console.WriteLine();
                    System.Console.Write("Enter any key to continue: ");
                    Key = System.Console.ReadKey().Key;
                    Enter = System.Console.ReadKey().Key;
                    System.Console.WriteLine();
                    System.Console.WriteLine();
                    Coin = 0;
				}
			}
		} while (Protagonist.Health != 0 && Antagonist.Health != 0);

		if (Antagonist.Health == 0)
		{
			System.Console.WriteLine("VICTORY!");
		}
		if (Protagonist.Health == 0)
		{
			System.Console.WriteLine("DEFEAT!");
		}

		System.Console.WriteLine();
		System.Console.WriteLine("   PROTAGONIST HEALTH: {0}", Protagonist.Health);
		System.Console.WriteLine("    ANTAGONIST HEALTH: {0}", Antagonist.Health);
	}
}
