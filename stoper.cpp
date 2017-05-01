#include <iostream>
#include <ctime>
#include <ratio>
#include <thread>
#include <chrono>
#include <iomanip>

int main ()
{
using namespace std::chrono;
steady_clock::time_point start = steady_clock::now();
steady_clock::time_point teraz;
while(true)
	{
	teraz = steady_clock::now();
	duration<int> sekundy = duration_cast<duration<int>>(teraz - start);
	minutes minuty = duration_cast<minutes>(sekundy);
	hours godziny = duration_cast<hours>(minuty);
	std::cout << std::setfill('0') << std::setw(2) << godziny.count() % 60 << ":" << std::setfill('0') << std::setw(2) << minuty.count() % 60 << ":"  << std::setfill('0') << std::setw(2) << sekundy.count() % 60 << "\r";
	std::this_thread::sleep_for (milliseconds(300));
	}
return 0;
}