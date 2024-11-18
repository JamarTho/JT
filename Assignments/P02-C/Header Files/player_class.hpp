#include <string>
#include <vector>

class Player {
private:
    std::string name;
    int score;

public:
    Player(std::string playerName) : name(playerName), score(0) {}

    void addScore(int points) {
        score += points;
    }

    int getScore() const {
        return score;
    }

    std::string getName() const {
        return name;
    }
};
