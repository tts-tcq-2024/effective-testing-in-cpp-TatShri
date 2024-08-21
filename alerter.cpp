#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

// Function pointer for the network alert function
int (*networkAlert)(float celcius) = nullptr;

// Stub function simulating network alert
int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Simulate failure if temperature is above a threshold (e.g., 200°C)
    if (celcius > 200) {
        return 500;  // Return 500 for not-ok
    }
    return 200;  // Return 200 for ok
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlert(celcius);  // Call the network alert function
    if (returnCode != 200) {
        // This should increment the failure count, but the current bug prevents it
        alertFailureCount += 0;  // Bug: Failure count is not incremented
    }
}

int main() {
    // Set the network alert function to the stub for testing
    networkAlert = networkAlertStub;

    // Test cases with temperatures that should trigger an alert failure
    alertInCelcius(400.5);  // Should fail, as the temperature in Celsius is high
    alertInCelcius(303.6);  // Should fail, as the temperature in Celsius is high

    // Verify that the alertFailureCount is incremented correctly
    assert(alertFailureCount == 2);  // This will fail because alertFailureCount remains 0

    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
