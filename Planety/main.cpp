#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void show(tuple<string, float, float, float, float, float, int, string>& planeta)
{
    cout << get<0>(planeta) << "\tsrednica: " << get<1>(planeta)<< "\tmasa: " << get<2>(planeta) << "\todleglosc od slonca: " << get<3>(planeta) << "\tczas obiegu [lata]: "
    << get<4>(planeta)<< "\tczas obrotu [dni]: " << get<5>(planeta) << "\tliczba ksiezycow: " << get<6>(planeta) << "\trodzaj: " << get<7>(planeta) << endl;
}

int main() {
    vector<tuple<string, float, float, float, float, float, int, string>> planety = {
        {"Merkury", 0.3825, 0.552, 0.3871, 0.2408, 58.64306, 0, "skalista"},
        {"Wenus", 0.9489, 0.8149, 0.7233, 0.6152, 243.01875, 0, "skalista"},
        {"Ziemia", 1.0, 1.0, 1.0, 1.0, 0.99727, 1, "skalista"},
        {"Mars", 0.5335, 0.1074, 1.5237, 1.8808, 1.02596, 2, "skalista"},
        {"Jowisz", 11.2092, 317.8, 5.2034, 11.8637, 0.41354, 79, "gazowa"},
        {"Saturn", 9.494, 95.1620, 9.5371, 29.4484, 0.44400, 82, "gazowa"},
        {"Uran", 4.0074, 14.5360, 19.1913, 84.0711, 0.71833, 27, "gazowo-lodowa"},
        {"Neptun", 3.8827, 17.1470, 30.0690, 164.8799, 0.67125, 14, "gazowo-lodowa"}
    };

    cout <<"Planety przed sortowaniem:"<<endl;
    for (auto& planeta : planety)
    {
        show(planeta);
    }

    sort(planety.begin(), planety.end(), [](auto& p1, auto& p2)
    {
        return get<1>(p1) < get<1>(p2);
    });

    cout << "\nPlanety po sortowaniu wedlug srednicy:"<<endl;
    for (auto& planeta : planety)
    {
        show(planeta);
    }

    return 0;
}
