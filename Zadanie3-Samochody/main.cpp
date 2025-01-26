#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    vector<tuple<string, string, int>> samochody = {
        {"Mazda", "benzyna", 2018},
        {"Peugeot", "diesel", 2019},
        {"Skoda", "benzyna", 2009},
        {"Toyota", "benzyna", 2025},
        {"Audi", "diesel", 2020},
        {"Hunday", "diesel", 2015}
    };

    sort(samochody.begin(), samochody.end(), [](tuple<string, string, int>& a, const tuple<string, string, int>& b)
    {
        if (get<1>(a) == "benzyna" && get<1>(b) == "benzyna")
        {
            return get<2>(a) > get<2>(b);
        }
        return false;
    });

    cout << "Samochody benzynowe posortowane malejaco wedlug roku produkcji:"<<endl;
    for (auto& samochod : samochody)
    {
        if (get<1>(samochod) == "benzyna")
        {
            cout << get<0>(samochod) << " - " << get<2>(samochod) << endl;
        }
    }

    return 0;
}
