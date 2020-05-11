#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

class Coordinate {
public:
    std::string latitude;
    std::string longitude;
};

// Prototypes
std::vector<Coordinate> setCoordinates(std::string tcxFile);
std::string stripTags(std::string line);
void writeCoordinates(std::vector<Coordinate> coordinates, std::string templateFile);

int main() {
    std::cout << "Name of .tcx file: ";
    std::string tcxFile;
    std::cin >> tcxFile;
    std::vector<Coordinate> coordinates = setCoordinates(tcxFile);

    std::cout << "Name of .html template.";
    std::string templateFile;
    std::cin >> templateFile;
    writeCoordinates(coordinates, templateFile);
    return 0;
}

// Reads TCX file and returns vector of coordinates
std::vector<Coordinate> setCoordinates(std::string tcxFile) {
    std::vector<Coordinate> coordinates;
    // Open TCX file
    std::ifstream input(tcxFile);
    // Read file
    std::string text;
    while (getline(input, text)) {
        // Find block of code beginning with <Position>
        if (text.find("<Position>") != std::string::npos) {
            Coordinate coordinate;

            // Set latitude and longitude
            getline(input, text);
            coordinate.latitude = stripTags(text);
            getline(input, text);
            coordinate.longitude = stripTags(text);

            // Add coordinate to coordinates
            coordinates.push_back(coordinate);
        }
    }
    input.close();
    return coordinates;
}

// Return line without tags
std::string stripTags(std::string line) {
    for (int i = 0; i < line.length(); i++) {
        // Remove whitespaces
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        // Remove tags
        if (line[i] == '<') {
            for (int j = i; j < line.length(); j++) {
                if (line[j] == '>') {
                    line.erase(i, (j - i + 1));
                    break;
                }
            }
        }
    }
    return line;
}

// Write coordinates to final html
void writeCoordinates(std::vector<Coordinate> coordinates, std::string templateFile) {
    // Open files
    std::ifstream input(templateFile);
    std::ofstream output("finalMap.html");

    // Read mapa1.html
    std::string line;
    while (getline(input, line)) {
        // Copy from input to output
        output << line << std::endl;
        // If line contains var flightPlanCoordinates = [, add coordinates
        if (line.find("var flightPlanCoordinates = [") != std::string::npos) {
            for (int i = 0; i < coordinates.size(); i++) {
                // If last line, do not add comma after the command, else add comma
                if (i == coordinates.size() - 1) {
                    output << "    new google.maps.LatLng(" << coordinates.at(i).latitude << ", " << coordinates.at(i).longitude << ")" << std::endl;
                } else {
                    output << "    new google.maps.LatLng(" << coordinates.at(i).latitude << ", " << coordinates.at(i).longitude << ")," << std::endl;
                }
            }
        }
    }
    input.close();
    output.close();
}