
#include "game_options.hpp"

namespace bulls_and_cows {

    // TODO: define the body of the functions declared in game_options.cpp

        void display_game_options_menu(std::ostream& output_stream)
    {
        output_stream << "Game options menu\n"
                         "0 - Return to main\n"
                         "1 - Modify number of attempts\n"
                         "2 - Modify number of character per code\n"
                         "3 - Modify characters allowed\n"
                         "4 - Save your choice\n"
                         "5 - Load options\n"
                         "What is your choice ? ";
    }

    GameOptionsMenuChoice ask_games_options_choice(std::istream& input_stream)
    {
        const int user_choice = ask_int_or_default(input_stream, -1);
        switch (user_choice)
        {
        case 0:
            return GameOptionsMenuChoice::BackToMain;
        case 1:
            return GameOptionsMenuChoice::ModifyMaximumNumberOfAttempts;
        case 2:
            return GameOptionsMenuChoice::ModifyNumberOfCharactersPerCode;
        case 3:
            return GameOptionsMenuChoice::ModifyMinimumAllowedCharacter;
        case 4:
            return GameOptionsMenuChoice::SaveOptions;
        case 5:
            return GameOptionsMenuChoice::LoadOptions;
        }
        return GameOptionsMenuChoice::Error;
    }

    void display_actual_game_options(std::ostream& output_stream, const GameOptions& game_options)
    {
        output_stream << "Actual game options are : \n "
                     "Number of characters per code : " << game_options.number_of_characters_per_code << 
                     "\n Character min "<< game_options.minimum_allowed_character << 
                     "\n Character max " << game_options.maximum_allowed_character;

    }
    
    void change_Number_Characters(GameOptions& game_options, std::istream& input_stream)
    {

        std::cout << " New number of character ? ";
        int C = ask_int_or_default(input_stream, -1);
        game_options.number_of_characters_per_code = C;
        std::cout << "Now the new number of character is : " << C << "\n";
    }

    void change_Number_attempt(GameOptions& game_options, std::istream& input_stream)
    {

        std::cout << " New number of character ? ";
        int C = ask_int_or_default(input_stream, -1);
        game_options.max_number_of_attempts = C;
        std::cout << "Now the new number of attempt is : " << C << "\n";
    }

    void change_Char(GameOptions& game_options ,std::istream& input_stream)
    {
        std::cout << "Enter your new minimum character? \n";
        char char_min = ask_char_or_default(input_stream, -1);
        std::cout << "Enter your new maximum character? \n";
        char char_max = ask_char_or_default(input_stream, -1);
        if (char_max < char_min)
        {
            change_Char(game_options, input_stream);
        }
        else
        {
            game_options.minimum_allowed_character = char_min;
            game_options.maximum_allowed_character = char_max;
            std::cout << "Now the minimum character is : " << char_min << "\n"
                         "Now the maximum character is : " << char_max << "\n";
        }
    }
    void save_game_options(const GameOptions& game_options)
    {
        std::string path = "D:/DEVCPP/PROJECTS/bulls_and_cows_skeleton/out/option.txt";
        std::ofstream Lecturetexte(path.c_str());
            
        if (Lecturetexte)
        {

            Lecturetexte << game_options.number_of_characters_per_code << std::endl;    //enregistrement des options fraichement modifie 
            Lecturetexte << game_options.minimum_allowed_character << std::endl;        //Un seul charactere par ligne ce qui nous permettra une lecture de fichier plus facile
            Lecturetexte << game_options.maximum_allowed_character << std::endl;
            Lecturetexte << game_options.max_number_of_attempts << std::endl;

        }
        else
        {
            std::cout << "Error \n" << std::endl;
        }
    
    
    }
    void load_file(GameOptions& game_options)
    {
        const std::string path = "D:/DEVCPP/PROJECTS/bulls_and_cows_skeleton/out/option.txt";

        std::ifstream file(path);

        if (file)
        {
            std::string ligne;
            int num_ligne = 1;

            while (getline(file, ligne))
            {

                if (num_ligne == 1)
                {
                    game_options.number_of_characters_per_code = std::abs(atoi(ligne.c_str()));  //essayé avec static_cast mais pas moyen 
                }

                if (num_ligne == 2)
                {
                    game_options.minimum_allowed_character = *ligne.c_str();
                }

                if (num_ligne == 3)
                {
                    game_options.maximum_allowed_character = *ligne.c_str();
                }
                if (num_ligne == 4)
                {
                    game_options.max_number_of_attempts = std::abs(atoi(ligne.c_str())); // essayé avec static_cast mais pas moyen
                }
                num_ligne++;
            }
        }
        else
        {
            std::cout << "Impossible to open the file" << std::endl;
        }


    
    }

} // namespace bulls_and_cows
