//the hangman game

#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

int word_chooser(string data[3]);
bool check(char window_data[], int size,  char character, string word);
bool end_check(char data[], int size);
bool end_check(char data[], int size);

int main()
{
    srand((unsigned) 2) ;
    string main_data[] = {"hello", "clock", "car"};

    //main loop for the game : 
    bool play = true; 
    while (play)
    {
        string game_word = main_data[word_chooser(main_data)];
        int hearts = 5 , len = game_word.length();
        char player_guess, answer;
        char player_data[len];
        cout << "HEARTS : " << hearts << endl;
        for (int i = 0; i < len; i++)
        {
            player_data[i] = '_';
        }
        do
        {
            cout << "Enter a word for guess : " << endl;
            cin >> player_guess;
    
            if (check(player_data , len , player_guess , game_word) == true)
            {
                cout << "succed : ";
                for (int i = 0; i < len; i++)
                {
                    cout << player_data[i];
                }
                 cout << endl;
            }
            else
            {
                hearts--;
                cout << "sorry" << endl 
                << "HEARTS : " << hearts << endl;
         }
            if (end_check(player_data , len) == true)
            {
                // cout << "you have won !!!!!";
                break;
            }
        } while ( hearts != 0);
        cout << "wanna play agian ? (Y/N) : ";
        
        if (hearts > 0)
        {
            cout << "you have won!!!!!!!!" << endl;
        }
        else
        {
            cout << "you have lost!!!!!!!" << endl;
        }

        cin >> answer;
        if (answer == 'N' || answer == 'n')
        {
            play = false;
        }
        
    }

}

int word_chooser(string data[3])
{

    int random = rand() % 3;
    string word = data[random];
    for (int i = 0; i < size(word); i++)
    {
        cout << "_";
    }
    cout << endl;

    //returning the choosen word index in the main array : 
    return random;
}

bool check(char window_data[], int size, char character, string word)
{
    // تابع مورد نظر جهت چک کردن حرف ورودی کاربر با کلمه اصلی است در صورتی بودن یا نبودن حرف در کلمه اصلی 
    // true یا false
    // برگرداند
    // window_data : ارایه ای که در صفحه به کاربر نشان داده میشود (باید هر دفعه ریست شود)
    // size : اندازه ارایه اصلی
    // character : کاراکتر وارد شده توسط کاربر
    // word : کلمه انتخاب شده توسط برنامه
    // کد خود را اینحا بنویسید
}

bool end_check(char data[], int size)
{
    // تابع مورد نظر برای چک کردن ان است که ایا تمام حروف حدس زده شده یا خیر
    // data : ارایه ای شامل تمام حروف حدس زده شده
    // size : اندازه ارایه
    // کد خود را اینجا بنویسید
}
