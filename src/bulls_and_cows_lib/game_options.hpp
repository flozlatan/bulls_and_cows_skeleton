
#pragma once
#include "input.hpp"
#include <fstream>
#include <iostream>
#include <thread>
#include <stdexcept>
#include <sstream>

namespace bulls_and_cows {

    struct GameOptions
    {
        unsigned int max_number_of_attempts{12};
        unsigned int number_of_characters_per_code{5};
        char minimum_allowed_character{'A'};
        char maximum_allowed_character{'G'};
    };

        enum class GameOptionsMenuChoice
    {
        Error = -1,
        BackToMain = 0,
        ModifyMaximumNumberOfAttempts = 1,
        ModifyNumberOfCharactersPerCode = 2,
        ModifyMinimumAllowedCharacter = 3,
        SaveOptions = 4,
        LoadOptions = 5,
    };

     // Ask the user to select an option of the menu
    GameOptionsMenuChoice ask_games_options_choice(std::istream& input_stream);

    void display_actual_game_options(std::ostream& output_stream, const GameOptions& game_options);

    void display_game_options_menu(std::ostream& output_stream);   

    void change_Number_Characters(GameOptions& game_options, std::istream& input_stream);

    void change_Number_attempt(GameOptions& game_options, std::istream& input_stream);

    void change_Char(GameOptions& game_options, std::istream& input_stream);

    void save_game_options(const GameOptions& game_options);

    void load_file(GameOptions& game_options);




} // namespace bulls_and_cows
