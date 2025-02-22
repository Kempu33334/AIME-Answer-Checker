#include <bits/stdc++.h>

using namespace std;

// Function to load answers from a file into a vector
vector<string> loadAnswers(const string &filename) {
    vector<string> answers;
    ifstream file(filename);
    string line;
    
    if (!file) {
        cerr << "Error: Could not open the answer file!" << endl;
        exit(1);
    }

    while (getline(file, line)) {
        answers.push_back(line);
    }

    file.close();
    return answers;
}

// Function to check if the answer is correct
void checkAnswer(int problemNumber, const string &userAnswer, const vector<string> &answers) {
    if (problemNumber < 1 || problemNumber > answers.size()) {
        cout << "Invalid problem number." << endl;
        return;
    }

    if (userAnswer == answers[problemNumber - 1]) {
        cout << "Correct!" << endl;
    } else {
        cout << "Incorrect. Try again." << endl;
    }
}

int main() {
    string contestYear;
    string contest1or2;
    cout << "Type the year you are checking: ";
    cin >> contestYear;
    cout << "Type the type of contest (AIME I or II) by typing 1 or 2: ";
    cin >> contest1or2;
    string answerFile = contestYear+"_"+contest1or2+".txt";  // File containing the correct answers
    vector<string> answers = loadAnswers(answerFile);
    string userAnswer;

    while (true) {
        int problemNumber;
        cout << "Enter problem number (or 0 to exit): ";
        cin >> problemNumber;
        if (problemNumber == 0) {
            break;
        }

        cout << "Enter your answer: ";
        cin >> userAnswer;
        if ((contestYear == "2022" && contest1or2 == "2") && (problemNumber==8)) {
            if (userAnswer == "081" || userAnswer == "080") {
                cout << "Correct!" << endl;
                break;
            }
        }
        checkAnswer(problemNumber, userAnswer, answers);
    }
}