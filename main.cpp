//***************************************************************************
//
// Sajjad Haq
// H00803115
// CSC 122 COMPUTER SCIENCE II (62339)
//
// I certify that this is my own work and where appropriate an extension of the
// starter code provided for the assignment.
//
//***************************************************************************

#include <chrono>
#include <ctime>
#include <iostream>
using namespace std;

class StopWatch {
public:
  StopWatch(bool autoStart = false) {
    isRunning = autoStart;
    if (autoStart) {
      start();
    }
  }

  void start() {
    startTime = chrono::system_clock::now();
    isRunning = true;
  }

  void stop() {
    if (isRunning) {
      endTime = chrono::system_clock::now();
      isRunning = false;
    }
  }

  int elapsed() const {
    if (isRunning) {
      return chrono::duration_cast<chrono::seconds>(
                 chrono::system_clock::now() - startTime)
          .count();
    } else {
      return chrono::duration_cast<chrono::seconds>(endTime - startTime)
          .count();
    }
  }

  StopWatch add(const StopWatch &other) const {
    StopWatch result;
    result.endTime =
        endTime + (other.endTime - other.startTime) + (startTime - endTime);
    result.startTime = startTime;
    return result;
  }

  StopWatch subtract(const StopWatch &other) const {
    StopWatch result;
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(
        endTime - other.endTime);
    result.endTime = endTime - elapsed;
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(
        startTime - other.startTime);
    result.startTime = startTime - elapsed;
    return result;
  }

  string toString() const { return to_string(elapsed()) + " sec"; }

private:
  chrono::time_point<chrono::system_clock> startTime;
  chrono::time_point<chrono::system_clock> endTime;
  bool isRunning;
};

int main() {
  char choice = 'y';

  cout << "Auto-start is on..." << endl;
  StopWatch timer1(true);

  while (choice == 'y' || choice == 'Y') {
    cout << "The timer has started." << endl;

    // Print current date and time
    time_t now = time(nullptr);
    cout << "Current Date and Time: " << ctime(&now) << endl;

    cout << "We will now test the timer... Please wait a couple seconds then "
            "hit the ENTER key."
         << endl;
    string input;
    getline(cin, input);
    // cin.ignore();

    timer1.stop();
    cout << "Timer 1: " << input << endl;
    cout << "The timer has stopped." << endl;
    cout << "It took you " << timer1.elapsed() << " second(s) to stop the timer"
         << endl;

    StopWatch timer2;
    cout << "The timer was never started." << endl;

    StopWatch timer3 = timer1.add(timer2);
    cout << "Elapsed times added: " << timer3.elapsed() << " secs" << endl;

    StopWatch timer4 = timer1.subtract(timer2);
    cout << "Elapsed times subtracted: " << timer4.elapsed() << " secs" << endl;

    cout << "Would you like to test the program again? y/n: ";
    cin >> choice;
    cin.ignore();
    if (choice == 'n' || choice == 'N') {
      break;
    }
    if (choice == 'y' || choice == 'Y') {
      timer1.start();
    }
  }

  return 0;
}
