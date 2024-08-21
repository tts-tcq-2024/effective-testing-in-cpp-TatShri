#include <iostream>
#include <sstream>
#include <assert.h>

std::string generateExpectedOutput() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::ostringstream oss;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            oss << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
        }
    }
    return oss.str();
}

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

int main() {
    std::ostringstream oss;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(oss.rdbuf());  // Redirect cout to oss

    int result = printColorMap();

    std::cout.rdbuf(oldCoutBuffer);  // Restore original cout buffer

    std::string actualOutput = oss.str();
    std::string expectedOutput = generateExpectedOutput();

    // Stronger Assertions
    assert(result == 25);
    assert(actualOutput == expectedOutput);  // This should fail due to misalignment and incorrect minor color indices
    std::cout << "All is well (maybe!)\n";
    return 0;
}
