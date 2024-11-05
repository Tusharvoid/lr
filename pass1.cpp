#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

int main()
{
    // Assembly-like instructions
    string arr[12][6] = {{"", "START", "101", ""}, {"", "MOVER", "BREG", "=2"}, {"AGAIN", "MULT", "BREG", "TERM"},
                         {"", "MOVER", "CREG", "TERM"}, {"", "ADD", "CREG", "N"}, {"", "MOVEM", "CREG", "TERM"},
                         {"N", "DS", "2", ""}, {"RESULT", "DS", "2", ""}, {"ONE", "DC", "1", ""},
                         {"TERM", "DC", "1", ""}, {"", "END", "", ""}};
    int arr2[20] = {};
    int i = 0, j = 0, p = 1, t = 1;
    int k = 100;
    int count = 1;

    // Opcode and Register mappings for intermediate representation
    map<string, string> opcodes = {
        {"START", "(AD, 01)"}, {"END", "(AD, 02)"}, {"MOVER", "(IS, 04)"}, {"MOVEM", "(IS, 05)"}, 
        {"MULT", "(IS, 03)"}, {"ADD", "(IS, 01)"}, {"DC", "(DL, 02)"}, {"DS", "(DL, 01)"}
    };

    map<string, string> registers = {
        {"BREG", "01"}, {"CREG", "02"}, {"DREG", "03"}  // Register codes
    };

    // Vector to store intermediate code lines
    vector<string> intermediateCode;

    cout << "\nReference code with Intermediate Code\n";
    cout << "-------------------------------------------------\n";
    for (i = 0; i < 12; i++)
    {
        string lineIntermediate = "";  // Temporary string to store each line's intermediate code
        for (j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        
        // Print location counter (LC) for each line, except for START and END
        if (i != 0 && i < 10)
        {
            cout << "(" << k << ")";
            arr[i][4] = to_string(k);  // Store LC in the array
            arr2[i - 1] = k;
        }
        k++;

        // Generate intermediate code for this line
        if (opcodes.find(arr[i][1]) != opcodes.end())
        {
            lineIntermediate += opcodes[arr[i][1]] + " ";  // Opcode for the operation

            if (!arr[i][2].empty() && registers.find(arr[i][2]) != registers.end())
                lineIntermediate += "(RG, " + registers[arr[i][2]] + ") "; // Register code

            if (arr[i][3][0] == '=')
                lineIntermediate += "(L, 1)"; // Literal as a placeholder for the literal table
            else if (!arr[i][3].empty())
                lineIntermediate += "(S, " + to_string(t++) + ")"; // Symbol as a placeholder for the symbol table
        }

        // Add this line's intermediate code to the vector
        if (!lineIntermediate.empty())
            intermediateCode.push_back(lineIntermediate);

        cout << endl;
    }
    
    cout << "\nSymbol Table:\n";
    cout << "\nIndex\tSymbol\t\tLC\n";
    cout << "-----------------------------\n";
    t = 1;
    for (i = 0; i < 12; i++)
    {
        if (arr[i][0] == "AGAIN" || arr[i][0] == "TERM" || arr[i][0] == "ONE" || arr[i][0] == "N" || arr[i][0] == "RESULT")
        {
            cout << t++ << "\t" << arr[i][0] << "\t\t" << arr2[i - 1] << endl;
        }
    }
    
    cout << "\nLiteral Table:\n";
    cout << "\nIndex\tLiteral\t\tLC\n";
    cout << "----------------------------\n";
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == "=2")
            {
                cout << count++ << "\t" << arr[i][j] << "\t(" << --k << ")\n";
            }
        }
    }

    cout << "\nPool Table:\n";
    cout << "\nIndex.no.\n";
    cout << "----------------------------\n";
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == "=2")
            {
                cout << p++ << endl;
            }
        }
    }

    // Display the Intermediate Code at the end
    cout << "\nComplete Intermediate Code:\n";
    cout << "----------------------------\n";
    for (const auto& code : intermediateCode)
    {
        cout << code << endl;
    }

    return 0;
}