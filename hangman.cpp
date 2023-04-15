//the hangman game

// وارد کردن کتابخانه های مورد نیاز
#include <iostream>
#include <string.h> // برای استفاده از توابع مربوط به رشته
#include <cstdlib> // برای استفاده از توابع مربوط به تولید اعداد تصادفی

using namespace std;

//امضای توابع مورد استفاده
int word_chooser(string dict[], int n);
bool check(char window_data[], int size, char character, string word);
bool end_check(char window_data[], int size);

int main()
{
    srand((unsigned) 2); // برای اماده سازی تابع رندوم

    // تعریف ارایه کلمات
    string main_dict[] = {"hello", "clock", "car"};
    int main_data_size = 3;

    // متغیر بولین جهت خروج یا ادامه بازی
    bool play = true;
    
    // حلقه اصلی برای اجرا بازی
    while (play)
    {
        // تعریف متغیر های مورد نیاز

        // برای انتخاب کلمه تصادفی از ارایه اصلی
        int word_index = word_chooser(main_dict , main_data_size);
        string game_word = main_dict[word_index];

        int hearts = 5; //میزان فرصت های مانده برای حدس زدن
        int len = game_word.length(); //طول کبمه انتخاب شده
        char player_guess; //حرف حدس زده شده توسط کاربر
        char answer; //ایا کاربر میخواهد دوباره بازی کند یا خیر
        char player_data[len]; //ارایه جهت نشان دادن وضعیت کلمه حدس زده شده به کاربر

        cout << "HEARTS : " << hearts << endl; //نشان دادن فرصت های باقی مانده به کاربر
        
        // این حلقه جهت نشان دادن خط برای اولین بازی کاربر است
        for (int i = 0; i < len; i++)
        {
            player_data[i] = '_';
        }

        // حلقه برای عملیات اصلی بازی
        do
        {
            cout << "Enter a word for guess : " << endl;
            cin >> player_guess; //دریافت حرف حدس زده شده توسط کاربر

            // بررسی حرف ورودی با کلمه انتخاب شده
            if (check(player_data , len , player_guess , game_word) == true)
            {
                cout << "succed : ";
                for (int i = 0; i < len; i++)
                {
                    cout << player_data[i]; //باید حرف حدس زده شده در جای مناسب خود قرار گیرد و به کاربر نمایش داده شود
                }
                 cout << endl;
            }
            // در صورت اشتباه بودن حرف حدس زده شده
            else
            {
                hearts--; //از فرصت های کاربر یک فرصت کم میشود
                cout << "sorry" << endl 
                << "HEARTS : " << hearts << endl; //نشان دادن فرصت های باقی مانده به کاربر
            }
            // بررسی انکه ایا کلمه کامل حدس زده شده یا خیر
            if (end_check(player_data , len) == true)
            {
                // cout << "you have won !!!!!";
                break; // از حلقه خارج میشود
            }
        } while ( hearts != 0); //شرط حلقه عملیات اصلی بازی
        
        if (hearts > 0)
        {
            cout << "you have won!!!!!!!!" << endl;
        }
        else
        {
            cout << "you have lost!!!!!!!" << endl;
        }

        cout << "wanna play agian ? (Y/N) : "; //ایا کاربر میخواهد دوباره بازی کند یا خیر
        cin >> answer;
        if (answer == 'N' || answer == 'n')
        {
            play = false;
        }
    }

}

int word_chooser(string data[], int n)
{
    int random = rand() % n;
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
    /*
    تابع مورد نظر جهت چک کردن حرف ورودی کاربر با کلمه اصلی است در صورت بودن یا نبودن حرف در کلمه اصلی 
    true یا false
    برگرداند
    window_data : ارایه ای که در صفحه به کاربر نشان داده میشود
    size : اندازه ارایه کلمه انتخابی
    character : کاراکتر وارد شده توسط کاربر
    word : کلمه انتخاب شده توسط برنامه
    */

    // کد خود را اینجا بنویسید
}

bool end_check(char window_data[], int size)
{
    /*
    تابع مورد نظر برای چک کردن ان است که ایا تمام حروف حدس زده شده یا خیر
    window_data : ارایه ای شامل تمام حروف حدس زده شده
    size : اندازه ارایه
    */

    // کد خود را اینجا بنویسید
}
