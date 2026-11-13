#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct State {
    int length = 0;
    int link = -1;
    int occurrences = 0;
    vector<int> next;

    State() : next(256, -1) {}
};

class SuffixAutomaton {
private:
    vector<State> states;
    int last;

public:
    explicit SuffixAutomaton(int n) {
        states.reserve(2 * n + 1);
        states.emplace_back();
        last = 0;
    }

    void extend(unsigned char character) {
        int c = character;

        int current = (int)states.size();
        states.emplace_back();

        states[current].length =
            states[last].length + 1;

        states[current].occurrences = 1;

        int p = last;

        while (p != -1 && states[p].next[c] == -1) {
            states[p].next[c] = current;
            p = states[p].link;
        }

        if (p == -1) {
            states[current].link = 0;
        } else {
            int q = states[p].next[c];

            if (states[p].length + 1 == states[q].length) {
                states[current].link = q;
            } else {
                int clone = (int)states.size();
                states.push_back(states[q]);

                states[clone].length = states[p].length + 1;
                states[clone].occurrences = 0;

                while (p != -1 &&
                       states[p].next[c] == q) {
                    states[p].next[c] = clone;
                    p = states[p].link;
                }

                states[q].link = clone;
                states[current].link = clone;
            }
        }

        last = current;
    }

    long long countDistinctSubstrings() const {
        long long result = 0;

        for (int i = 1; i < (int)states.size(); i++) {
            result += states[i].length -
                      states[states[i].link].length;
        }

        return result;
    }

    void propagateOccurrences() {
        vector<int> order(states.size());

        for (int i = 0; i < (int)states.size(); i++)
            order[i] = i;

        sort(order.begin(), order.end(),
            [&](int a, int b) {
                return states[a].length > states[b].length;
            });

        for (int v : order) {
            if (states[v].link != -1) {
                states[states[v].link].occurrences +=
                    states[v].occurrences;
            }
        }
    }

    int longestRepeatedSubstring() const {
        int answer = 0;

        for (const State& state : states) {
            if (state.occurrences >= 2)
                answer = max(answer, state.length);
        }

        return answer;
    }
};

int main() {
    string text;

    cout << "Enter a string: ";
    getline(cin, text);

    if (text.empty()) {
        cout << "String cannot be empty.\n";
        return 1;
    }

    SuffixAutomaton automaton((int)text.size());

    for (unsigned char c : text)
        automaton.extend(c);

    automaton.propagateOccurrences();

    cout << "\nDistinct substrings: "
         << automaton.countDistinctSubstrings() << '\n';

    cout << "Longest repeated substring length: "
         << automaton.longestRepeatedSubstring() << '\n';

    return 0;
}
