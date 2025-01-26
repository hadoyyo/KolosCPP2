#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

bool sprawdz_godzine(const string& time) {
    int h, m, s;
    if (sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s) != 3)
    {
        return false;
    }
    if (h < 16 || h > 20)
    {
        return false;
    }
    if (h == 20 && (m > 30 || (m == 30 && s > 59)))
    {
        return false;
    }
    return true;
}

bool sprawdz_date(const string& line) {

    regex pattern1(R"((\d{4})-(\d{2})-(\d{2}) (\d{2}):(\d{2}):(\d{2}))");  // YYYY-MM-DD HH:MM:SS
    regex pattern2(R"((\d{4})-(\d{2})-(\d{2}) (\d{2}):(\d{2}):(\d{2}))");  // YYYY-DD-MM HH:MM:SS
    regex pattern3(R"((\d{2})-(\d{2})-(\d{4}) (\d{2}):(\d{2}):(\d{2}))");  // DD-MM-YYYY HH:MM:SS

    smatch match;
    if (regex_match(line, match, pattern1) || regex_match(line, match, pattern2) || regex_match(line, match, pattern3))
    {
        string time = match.str(4) + ":" + match.str(5) + ":" + match.str(6);
        return sprawdz_godzine(time);
    }
    return false;
}

int main() {

    ifstream file("czas.txt");
    if (!file.is_open()) {
        cerr<<"Blad podczas proby otwarcia pliku"<<endl;
        return 1;
    }

    string line;
    while (getline(file, line))
    {

        if (sprawdz_date(line))
        {
            cout<<line<<" - Poprawny format i zakres godzin"<<endl;
        } else {
            cout<<line<<" - Nie spelnia wymagan"<<endl;
        }
    }

    file.close();
    return 0;
}

