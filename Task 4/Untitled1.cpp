#include <iostream>
#include <string>

using namespace std;

int main() {
    string userInput;

    cout << "Chatbot: Hello! I am a simple chatbot. Type 'bye' to exit.\n";

    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        if (userInput == "bye") {
            cout << "Chatbot: Goodbye! Have a nice day.\n";
            break;
        } 
        else if (userInput == "hello" || userInput == "hi") {
            cout << "Chatbot: Hello! How can I help you?\n";
        } 
        else if (userInput == "how are you?") {
            cout << "Chatbot: I'm just a chatbot, but I'm doing fine! Thanks for asking.\n";
        } 
        else if (userInput == "what is your name?") {
            cout << "Chatbot: I am a simple chatbot created in C++.\n";
        } 
        else {
            cout << "Chatbot: I'm not sure how to respond to that.\n";
        }
    }

    return 0;
}
