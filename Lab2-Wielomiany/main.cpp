#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool test_wielomian(const string& wejscie)
{
    regex wzorzec_wielomianu(R"(^[+-]?\d*x\^4([+-](?!0)(\d*)x\^3)?([+-](?!0)(\d*)x\^2)?([+-](?!0)(\d*)x)?([+-]?\d+)?$)");

    return regex_match(wejscie, wzorzec_wielomianu);
}

int main() {

    string wielomiany[] = {
        "5x^4+x^3 + x - 3",
        "5x^4+x^3 + x",
        "-5x^4-4x^3+x^2 - 4",
        "5x4-2x^3 + x - 3",
        "5x^4+0x^3 + x - 3",
        "5x^4+x^3 + x -- 3"
    };

    for (auto& wielomian : wielomiany)
    {

        wielomian.erase(remove(wielomian.begin(), wielomian.end(), ' '), wielomian.end());

        if (test_wielomian(wielomian))
        {
            cout << wielomian << " - Poprawny zapis"<< endl;
        }
        else
        {
            cout << wielomian << " - Bledny zapis" << endl;
        }
    }

    return 0;
}
