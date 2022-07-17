#include <time.h>
#include <windows.h>
#include <iostream>
#include <chrono>
using namespace std;
string timeToString(chrono::system_clock::time_point t) {
  time_t time = chrono::system_clock::to_time_t(t);
  string time_str = ctime(&time);
  //time_str.resize(time_str.size() - 1);
  return time_str;
}
int main() {
  cerr << "Starting time: " << timeToString(chrono::system_clock::now());
  for (int i = 1; true; ++i) {
    Sleep((20 * 60 - 30) * CLOCKS_PER_SEC);
    time_t a = clock();
    cerr << "Turning off the screen at " <<
      timeToString(chrono::system_clock::now());
    while (clock() - a < 25 * CLOCKS_PER_SEC) {
      system("%systemroot%\\system32\\scrnsave.scr /s");
    }
    cerr << "Have done " << i << " row" << (i > 0 ? "s" : "") <<
      ", which means you have use the computer for " << i * 20 << " minutes." << endl;
  }
  return 0;
}
