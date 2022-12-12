using System;
class HelloWorld {
	static void Main() {
		int k;
		int j = 0;
		string ks;
		Console.WriteLine("k => ");
		ks = Console.ReadLine();
		k = Convert.ToInt32(ks);
		switch (k)
		{
		case 1: case 2: j = 2 * k - 1; break;
		case 3: case 5: j = 3 * k + 1; break;
		case 4: j = 4 * k - 1; break;
		case 6: case 7: case 8: j = k - 2; break;
		default: Console.WriteLine("No case in switch, k = " + k); return;
		}
		Console.WriteLine("j =" + j);
	}
}