#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
map<char, bool> guessed;
vector<char> wrong_letters;


bool check_letter(char letter, string word){
    //OLD STYLE
    // for (int i = 0; i < word.size() - 1; i++){
    //     if (letter == word[i]) return true;
    // }

    for(char l : word){ //C++11
        if (letter == l) return true;
    }
    return false;
}

bool not_hit(string word){
    for (char l: word){
        if (!guessed[l]){
            return true;
        }
    }
    cout << "Fim de jogo" << endl;
    return false;
}

bool not_hanged(){
    return wrong_letters.size() < 5;
}


int main(){
    string SECRET_WORD;
    cout << "Digite a palavra secreta: " << endl;
    cin >> SECRET_WORD;
    //cout << SECRET_WORD << endl;
    while (not_hit(SECRET_WORD) && not_hanged()){

        cout << "Chutes errados: ";
        for (char ll: wrong_letters){
            cout << ll << " ";
        }
        cout << endl;

        for (char l : SECRET_WORD){
            if (guessed[l]){
                cout << l << " ";
            }
            else{
                cout << "_ ";
            }
        }

        cout << endl;

        cout << "Chute uma letra ";
        char guess;
        cin >> guess;

        guessed[guess] = true;

        if(check_letter(guess, SECRET_WORD)) cout << "Você acertou! O chute está na palavra" << endl;
        else {
            wrong_letters.push_back(guess);
            cout << "Errroooouuuuuu" << endl;
        }
        cout << endl;
    }
}