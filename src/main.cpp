#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <vector>
#include "tokenization.hpp"
#include "parser.hpp"


using namespace std;

// vector<Token> tokenize(const string& str){
//     for (int i = 0; i < str.length();i++){
//         char c = str.at(i);
//         if(isalpha(c)){

//         }
//     }
// }

int main(int argc, char *argv[])
{
    if(argc != 2){
        cerr << "Incorrect Usage. Correct Usage is " << endl;
        cerr << "toy <input.tl> " << endl;
        return EXIT_FAILURE;
    }

    string contents;

    {
        stringstream contents_stream;
        fstream input(argv[1], ios::in);
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
    }

    Tokenizer tokenizer(std::move(contents));
    vector<Token> tokens = tokenizer.tokenize();

    Parser parser(std::move(tokens));
    std::optional<NodeProg> prog parser.parse_prog();



    // tokenize(contents);

    return EXIT_SUCCESS;
}
