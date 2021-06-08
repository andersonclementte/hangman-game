#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;
string secret_word;
map<char, bool> guessed;
vector<char> wrong_letters;


bool check_letter(char letter){
    //OLD STYLE
    // for (int i = 0; i < word.size() - 1; i++){
    //     if (letter == word[i]) return true;
    // }

    for(char l : secret_word){ //C++11
        if (letter == l) return true;
    }
    return false;
}

bool not_hit(){
    for (char l: secret_word){
        if (!guessed[l]){
            return true;
        }
    }
    return false;
}

bool not_hanged(){
    return wrong_letters.size() < 5;
}

void print_erros(){
    cout << "Chutes errados: ";
        for (char ll: wrong_letters){
            cout << ll << " ";
        }
        cout << endl;
}

void print_word(){
    for (char l : secret_word){
            if (guessed[l]){
                cout << l << " ";
            }
            else{
                cout << "_ ";
            }
        }

        cout << endl;
}

void make_guess(){
    cout << "Chute uma letra ";
        char guess;
        cin >> guess;

        guessed[guess] = true;

        if(check_letter(guess)) cout << "Você acertou! O chute está na palavra" << endl;
        else {
            wrong_letters.push_back(guess);
            cout << "Errroooouuuuuu" << endl;
        }
        cout << endl;
}

vector<string> read_file(){
   ifstream file; 
   file.open("words.txt");

   int word_amount;
   file >> word_amount;
   //cout << "Quantidade de palavras: " << word_amount << endl;

   vector<string> files_words;

   for (int i = 0; i < word_amount; i++){
       string read_word;
       file >> read_word;
       //cout << "Linha " << i << " Palavra: " << read_word << "; " << endl;
       files_words.push_back(read_word);
   }
   return files_words;
}

void pick_word(){
    vector<string> words = read_file();

    srand(time(NULL));
    int raffled_index = rand() % words.size();

    secret_word = words[raffled_index];
}


int main(){

    //read_file();
    pick_word();
    // string secret_word;
    // cout << "Digite a palavra secreta: " << endl;
    // cin >> secret_word;
    //cout << secret_word << endl;
    while (not_hit() && not_hanged()){
        print_erros();
        print_word();
        make_guess();        
    }
    cout << "Fim de jogo" << endl;
    if (not_hit()){
        cout <<"Você perdeu, tente novamente." << endl;
    }
    else{
        cout << "Você acertou a palavra secreta." << endl;
    }
    cout << "A palavra secreta era " << secret_word << endl;
}