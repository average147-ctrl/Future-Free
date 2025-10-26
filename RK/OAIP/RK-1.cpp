#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main() {
    vector<string> data;
    string line;
    
    while (getline(cin, line)) {
        data.push_back(line);
    }

    vector<double> alt, vel, temp, pres;

    for (const auto& str : data) {
        char* cstr = new char[str.size() + 1];
        strcpy(cstr, str.c_str());
        
        char* alt_ptr = strstr(cstr, "ALT:");
        char* vel_ptr = strstr(cstr, "VEL:");
        char* temp_ptr = strstr(cstr, "TEMP:");
        char* pres_ptr = strstr(cstr, "PRES:");
        
        if (alt_ptr) alt.push_back(atof(alt_ptr + 4));
        if (vel_ptr) vel.push_back(atof(vel_ptr + 4));
        if (temp_ptr) temp.push_back(atof(temp_ptr + 5));
        if (pres_ptr) pres.push_back(atof(pres_ptr + 5));
        
        delete[] cstr;
    }

    double max_alt = alt[0];
    double sum_vel = 0;
    double min_temp = temp[0];

    for (size_t i = 0; i < alt.size(); ++i) {
        if (alt[i] > max_alt) max_alt = alt[i];
        sum_vel += vel[i];
        if (temp[i] < min_temp) min_temp = temp[i];
    }

    double avg_vel = sum_vel / vel.size();

    cout << "Max altitude: " << max_alt << " m\n";
    cout << "Average velocity: " << avg_vel << " m/s\n";
    cout << "Min temperature: " << min_temp << " °C\n";

    return 0;
}