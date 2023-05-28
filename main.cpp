#include<bits/stdc++.h>
using namespace std;

class Question {
    public:
    string text;
    vector<string> options;
};

class Survey : public Question {
    public:
    string title;
    vector<Question> questions;
    friend void displaySurvey(const Survey& survey);
    friend void displayResponses(const Survey& survey, const vector<vector<int>>& responses);
    friend void takeSurvey(const Survey& survey, vector<vector<int>>& responses);
};

void displaySurvey(const Survey& survey) {
    cout << "Title: " << survey.title << endl;
    cout << "-----------------------" << endl;
    for (const auto& question : survey.questions) {
        cout << question.text << endl;
        for (size_t i = 0; i < question.options.size(); i++) {
            cout << i + 1 << ". " << question.options[i] << endl;
        }
        cout << endl;
    }
}

void takeSurvey(const Survey& survey, vector<vector<int>>& responses) {
    vector<int> response;
    cout << "Taking survey: " << survey.title << endl;
    cout << "-----------------------" << endl;
    for (const auto& question : survey.questions) {
        cout << question.text << endl;
        for (size_t i = 0; i < question.options.size(); i++) {
            cout << i + 1 << ". " << question.options[i] << endl;
        }
        int answer;
        cout << "Enter your choice: ";
        cin >> answer;
        response.push_back(answer);
    }
    responses.push_back(response);
    cout << "Thank you for taking the survey!" << endl;
}

void displayResponses(const Survey& survey, const vector<vector<int>>& responses) {
    cout << "Survey Responses: " << survey.title << endl;
    cout << "-----------------------" << endl;
    int respondent = 1;
    for (const auto& response : responses) {
        cout << "Respondent " << respondent << ":" << endl;
        for (size_t i = 0; i < response.size(); i++) {
            cout << survey.questions[i].text << ": ";
            int answerIndex = response[i] - 1;
            cout << survey.questions[i].options[answerIndex] << endl;
        }
        cout << endl;
        respondent++;
    }
}



class User {
private:
    string username;
    string password;

public:
    User(string _username, string _password) : username(_username), password(_password) {}

    string getUsername() {
        return username;
    }

    string getPassword() {
        return password;
    }
};

class UserManager {
private:
    vector<User> users;

public:
    void registerUser(string username, string password) {
        User newUser(username, password);
        users.push_back(newUser);
        cout << "Registration successful." << endl;
    }

    bool loginUser(string username, string password) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getUsername() == username && users[i].getPassword() == password) {
                cout << "Login successful." << endl;
                return true;
            }
        }
        cout << "Invalid username or password." << endl;
        return false;
    }
};





int main() {

     UserManager userManager;
    bool loggedIn = false;
    int choice;

    while (!loggedIn) {
        cout << "Welcome!" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        string username, password;

        switch (choice) {
            case 1:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                userManager.registerUser(username, password);
                break;
            case 2:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                loggedIn = userManager.loginUser(username, password);
                break;
            case 3:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }




    Survey survey;
    survey.title = "Customer Satisfaction Survey";

    // Adding questions to the survey
    Question question1;
    question1.text = "Are you satisfied with the teaching staff and their teaching methods?";
    question1.options = { "Very Satisfied", "Satisfied", "Neutral", "Dissatisfied", "Very Dissatisfied" };
    survey.questions.push_back(question1);

    Question question2;
    question2.text = "How satisfied are you with the facilities provided by the college?";
    question2.options = { "Very Satisfied", "Satisfied", "Neutral", "Dissatisfied", "Very Dissatisfied" };
    survey.questions.push_back(question2);

    Question question3;
    question3.text = "Was it easy to obtain the necessary resources from the college library?";
    question3.options = { "Yes", "No"};
    survey.questions.push_back(question3);

    Question question4;
    question4.text = "Do you feel it is easier to register for different courses within the college?";
    question4.options = { "Very Satisfied", "Satisfied", "Neutral", "Dissatisfied", "Very Dissatisfied" };
    survey.questions.push_back(question4);

    Question question5;
    question5.text = " How supportive were the faculty members?";
    question5.options = { "Extremely supportive", "Supportive", "Neutral", "Unsupportive", "Very Unsupportive" };
    survey.questions.push_back(question5);

    Question question6;
    question6.text = "What is the quality of meal in hall?";
    question6.options = { "Very Satisfied", "Satisfied", "Neutral", "Dissatisfied", "Very Dissatisfied" };
    survey.questions.push_back(question6);

    vector<vector<int>> responses;
    int choic;
    do {
        cout << "Online Survey Management\n";
        cout << "1. Display Survey\n";
        cout << "2. Take Survey\n";
        cout << "3. Display Responses\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choic;

        switch (choic) {
            case 1:
                displaySurvey(survey);
                break;
            case 2:
                takeSurvey(survey, responses);
                break;
            case 3:
                displayResponses(survey, responses);
                break;
            case 4:
                cout << "Thank you for using the Online Survey Management system!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choic != 4 && loggedIn==true );

    return 0;
}
