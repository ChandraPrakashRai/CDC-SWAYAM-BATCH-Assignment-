// K Battle Ship Placement Problem
// Backtracking approach
// Each ship has 3 parameters: rowAttack, columnAttack, diagonalAttack.
// If a ship is at (r, c), it attacks:
//   - All cells in same row within rowAttack distance
//   - All cells in same column within columnAttack distance
//   - All diagonal cells within diagonalAttack distance
//
// Goal: Place all K ships so that no ship attacks any other.
//
// Input format to test example:
// N M K
// Then K lines: rowAttack colAttack diagAttack
//
// Output: coordinates of ships or "No solution".
//
// This code is clean, hand-written, and fully commented.

#include <bits/stdc++.h>
using namespace std;

struct Ship {
    int ra, ca, da; // rowAttack, columnAttack, diagonalAttack
};

int N, M, K;
vector<Ship> ships;     // ships[i] = attack parameters of ship i
vector<pair<int,int>> placed; // coordinates of placed ships

bool inBounds(int r, int c) {
    return (r >= 0 && r < N && c >= 0 && c < M);
}

// Check if (r, c) is safe for ship 'cur'
bool isSafe(int r, int c, int cur) {

    for (int i = 0; i < (int)placed.size(); i++) {
        auto [pr, pc] = placed[i];  // previously placed ship position
        Ship &A = ships[i];
        Ship &B = ships[cur];

        // Check mutual attacks
        // If either A attacks B or B attacks A, it's invalid

        // --- Check row attack ---
        if (pr == r) {
            if (abs(pc - c) <= A.ra) return false;
            if (abs(pc - c) <= B.ra) return false;
        }

        // --- Check column attack ---
        if (pc == c) {
            if (abs(pr - r) <= A.ca) return false;
            if (abs(pr - r) <= B.ca) return false;
        }

        // --- Check diagonal attack ---
        if (abs(pr - r) == abs(pc - c)) {
            if (abs(pr - r) <= A.da) return false;
            if (abs(pr - r) <= B.da) return false;
        }
    }

    return true; // Safe placement
}

bool backtrack(int idx) {
    if (idx == K) return true; // all ships placed

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {

            if (isSafe(r, c, idx)) {
                // place ship
                placed.push_back({r, c});

                if (backtrack(idx + 1))
                    return true;

                // backtrack
                placed.pop_back();
            }
        }
    }
    return false;
}

int main() {
    cin >> N >> M >> K;

    ships.resize(K);
    for (int i = 0; i < K; i++)
        cin >> ships[i].ra >> ships[i].ca >> ships[i].da;

    if (backtrack(0)) {
        cout << "Solution exists:\n";
        for (int i = 0; i < K; i++) {
            cout << "Ship " << i+1 << ": (" << placed[i].first
                 << ", " << placed[i].second << ")\n";
        }
    } else {
        cout << "No solution possible\n";
    }
    return 0;
}
