// A program that generates five questions and, after a student correctly answers all of
// them, reports the number of correct answers.

// Five questions
// Count correct answers
// Return results

#include <random>
#include <iostream>
#include <print>

using namespace std;

// subtraction function
int subtract(int num1, int num2)
{
    int answer = num1 - num2;
    return answer;
}

int main()
{
    random_device rd;                       // non-deterministic generator
    mt19937 gen(rd());                      // to seed mersenne twister. Mersene twister is a pseudo random number generator
    uniform_int_distribution<> dist(0, 20); // Define a distribution

    int correct_answers = 0;

    for (int i = 0; i < 5; ++i)
    {
        int first_num = dist(gen);
        int second_num = dist(gen);

        cout << "What is " << first_num << "-" << second_num << "?\n"; //

        int user_answer = 0;
        int answer = 0;

        cin >> user_answer;
        answer = subtract(first_num, second_num);
        if (answer == user_answer)
        {
            // increment correct answer count
            ++correct_answers;
        }

        else
        {
            // Do nothing
        }
    }

    print("{}/{}\n", correct_answers, 5);
}

// Try 
// Randomize the mathematical operation, including square root, power operation, division, multiplication, increase numbers to three.
// The program should also display the time spent on the test. Ensure the first number is greater than the secod number.
// Indicate if the answer entered is correct or wrod for each user entry.