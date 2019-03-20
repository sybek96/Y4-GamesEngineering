#include <thread>
#include <iostream>
#include <array>

std::array<int, 3> in = { 0,0,0 };
std::array<int, 3> last = { 0,0,0 };
int n = 3;

void CS(int i)
{
	while (true)
	{
		for (int j = 0; j < n; j++)
		{
			//entry protocol
			//remember process i is in stage j and is last
			in[i] = j;
			last[j] = i;
			for (int k = 0; k < n; k++)
			{
				if (i != k)
				{
					//wait if process k is in higher numbered stage and process i was the last to enter stage j
					while (in[k] >= in[i] && last[j] == i)
					{
						continue;
					}
				}
			}

		}
		std::cout << i << std::endl;
		in[i] = 0;
		//exit protocol
	}

}


int main()
{
	std::thread process1(CS, 0);
	std::thread process2(CS, 1);
	std::thread process3(CS, 2);

	process1.join();
	process2.join();
	process3.join();
}