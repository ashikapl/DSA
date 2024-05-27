#include <iostream>
#include <vector>
#include <string>

// Function to extract the status value from a JSON string
std::string extractStatus(const std::string& jsonStr) {
    // Find the position of the "status" key
    size_t pos = jsonStr.find("\"status\"");
    if (pos == std::string::npos) {
        return "Error"; // Return "Error" if "status" is not found
    }

    // Find the colon following the "status" key
    pos = jsonStr.find(":", pos);
    if (pos == std::string::npos) {
        return "Error"; // Return "Error" if colon is not found
    }

    // Find the first quote after the colon
    pos = jsonStr.find("\"", pos);
    if (pos == std::string::npos) {
        return "Error"; // Return "Error" if starting quote is not found
    }

    // Find the closing quote for the status value
    size_t start = pos + 1;
    pos = jsonStr.find("\"", start);
    if (pos == std::string::npos) {
        return "Error"; // Return "Error" if closing quote is not found
    }

    // Extract the status value
    return jsonStr.substr(start, pos - start);
}

// Function to count the occurrences of each status
std::vector<int> evaluate_deployments(const std::vector<std::string>& v) {
    int successCount = 0, failCount = 0, errorCount = 0;

    for (const std::string& s : v) {
        std::string status = extractStatus(s);

        if (status == "Success") {
            successCount++;
        } else if (status == "Fail") {
            failCount++;
        } else {
            errorCount++;
        }
    }

    return { successCount, failCount, errorCount };
}

int main() {
    std::vector<std::string> v = {
        R"({"deployment_id": "d-123456abcd", "status": "Success"})",
        R"({"deployment_id": "d-098765abcd", "status": "ABCD"})"
    };

    std::vector<int> counts = evaluate_deployments(v);

    std::cout << "Total Success: " << counts[0] << std::endl;
    std::cout << "Total Fail: " << counts[1] << std::endl;
    std::cout << "Total Error: " << counts[2] << std::endl;

    return 0;
}
