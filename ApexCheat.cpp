#include <iostream>
#include <vector>
#include <string>
#include <conio.h> // For _getch()

using namespace std;

// Feature flags
bool aimbot = false;
bool esp = false;
bool wallhack = false;
bool triggerbot = false;
bool norecoil = false;
bool radar = false;

void showMenu() {
    system("cls"); // Clear screen (Windows only)
    cout << "=============================\n";
    cout << "  Elusion Trainer - Trial Version\n";
    cout << "=============================\n";
    cout << "Status: Not Running\n";
    cout << "\nFeatures:\n";
    cout << "[1] Aimbot: " << (aimbot ? "ON" : "OFF") << endl;
    cout << "[2] ESP: " << (esp ? "ON" : "OFF") << endl;
    cout << "[3] Wallhack: " << (wallhack ? "ON" : "OFF") << endl;
    cout << "[4] TriggerBot: " << (triggerbot ? "ON" : "OFF") << endl;
    cout << "[5] NoRecoil: " << (norecoil ? "ON" : "OFF") << endl;
    cout << "[6] Radar: " << (radar ? "ON" : "OFF") << endl;
    cout << "\n[7] Start Trainer\n";
    cout << "[8] Exit\n";
    cout << "\nEnter your choice: ";
}

void updateStatus() {
    vector<string> activeFeatures;
    if (aimbot) activeFeatures.push_back("Aimbot");
    if (esp) activeFeatures.push_back("ESP");
    if (wallhack) activeFeatures.push_back("Wallhack");
    if (triggerbot) activeFeatures.push_back("TriggerBot");
    if (norecoil) activeFeatures.push_back("NoRecoil");
    if (radar) activeFeatures.push_back("Radar");

    if (!activeFeatures.empty()) {
        cout << "Status: Running - " << activeFeatures[0];
        for (size_t i = 1; i < activeFeatures.size(); ++i) {
            cout << ", " << activeFeatures[i];
        }
        cout << endl;
    } else {
        cout << "Status: Not Running" << endl;
    }
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                aimbot = !aimbot;
                break;
            case 2:
                esp = !esp;
                break;
            case 3:
                wallhack = !wallhack;
                break;
            case 4:
                triggerbot = !triggerbot;
                break;
            case 5:
                norecoil = !norecoil;
                break;
            case 6:
                radar = !radar;
                break;
            case 7:
                if (aimbot || esp || wallhack || triggerbot || norecoil || radar) {
                    updateStatus();
                    cout << "Status: Trainer Started (Fake!)" << endl;
                } else {
                    cout << "Please enable at least one feature." << endl;
                }
                _getch(); // Wait for key press
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                _getch();
        }

    } while (choice != 8);

    return 0;
}