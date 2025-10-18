#include <iostream>
#include <string>
using namespace std;

double attendance(string s) {
    int A = 0, P = 0;
    for (char c : s) {
        if (c == 'A') A++;
        else if (c == 'P') P++;
    }

    // cout << "A: " << A << ", P: " << P << endl;

    double total = A + P;
    if (total == 0) return 0;  // avoid divide-by-zero

    double percentage = (P / total) * 100.0;
    return percentage;
}

int main() {
    string DBMS = "AAPPPPPPPAPPPPPAAPAPPAPP";
    string SE = "AAPPPPAPPPPPPA";
    string CN = "PAPPPPPPPPPPPAAPPPPAP";
    string CS = "PPPPAPPP";
    string DS = "AAPPPPAPPPPPPPPAPPPPAAAP";
    string Python = "APPPPPPP";
    string Macro = "APPPPA";
    string DSLab = "PPPPPPPPAA";
    string DBMSLab = "PPPPPPA";
    string M2 = "PPPPAPPPPPAAPAPPAP";
    string SP = "PPAAA";
    string NEC = "APP";
    string SELFLEARNing = "APA";

    cout << "DBMS: " << attendance(DBMS) << "%" << endl;
    cout << "SE: " << attendance(SE) << "%" << endl;
    cout << "CN: " << attendance(CN) << "%" << endl;
    cout << "CS: " << attendance(CS) << "%" << endl;
    cout << "DS: " << attendance(DS) << "%" << endl;
    cout << "Python: " << attendance(Python) << "%" << endl;
    cout << "Macro: " << attendance(Macro) << "%" << endl;
    cout << "DSLab: " << attendance(DSLab) << "%" << endl;
    cout << "DBMSLab: " << attendance(DBMSLab) << "%" << endl;
    cout << "M2: " << attendance(M2) << "%" << endl;
    cout << "SP: " << attendance(SP) << "%" << endl;
    cout << "NEC: " << attendance(NEC) << "%" << endl;
    cout << "Self Learning: " << attendance(SELFLEARNing) << "%" << endl;
}
