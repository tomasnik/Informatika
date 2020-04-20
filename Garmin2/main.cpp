#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

float stripTags(std::string line);

int main() {
    // Open TCX file
    std::ifstream input("activity_318109582.tcx");
    // Read file
    std::string text;
    float total_time = 0, total_distance = 0;
    while (getline(input, text))
    {
        // Find line beginning with <Lap
        if (text.find("<Lap") != std::string::npos)
        {
            // Get line with time
            std::string time;
            getline(input, time);
            // Add to total_time
            total_time += stripTags(time);

            // Get line with distance
            std::string distance;
            getline(input, distance);
            // Add to total_distance
            total_distance += stripTags(distance);
        }
    }
    // Print time in minutes and seconds
    std::cout << "Celkovy cas: " << (int) total_time / 60 << " minut a " << (int) total_time % 60 << " sekund" << std::endl;
    // Print distance in kilometers, rounded to two decimal places
    std::cout << "Celkova vzdalenost: " << round(total_distance / 100 * 10) / 100 << " km";
    return 0;
}

// Return float from line with tags
float stripTags(std::string line) {
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == '<')
        {
            for (int j = i; j < line.length(); j++)
            {
                if (line[j] == '>')
                {
                    line.erase(i, (j - i + 1));
                    break;
                }
            }
        }
    }
    return std::stof(line);
}
