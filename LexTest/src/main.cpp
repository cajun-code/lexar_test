#include <iostream>
#include <string>
#include <lexer.h>
#include <fstream>

using namespace std;
/** Main start of application */
int main(int argc, const char * argv[]) {

    if(argc > 1){
        string fileName = argv[1];
        ifstream inFile;
        inFile.open(fileName);
        Lexer lex;
        lex.processTokens(inFile, cout);
        
    }else{
        cout << "Please add a file path to tokenize." << endl;
        cout << "lex_test path_to_file\n";  
    }

    return 0;
}
