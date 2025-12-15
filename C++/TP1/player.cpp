#include "headers/player.h"

Player::Player(const string& name)
{
    playerName = name;
}

Player::~Player()
{
    deleteCards();
}

void Player::deleteCards()
{
    for (size_t i = 0; i < benchCards.size(); i++) {
        delete benchCards[i];
    }
    for (size_t i = 0; i < actionCards.size(); i++) {
        delete actionCards[i];
    }
    benchCards.clear();
    actionCards.clear();
}

string Player::getName() const
{
    return playerName;
}

void Player::addCardToBench(Card* card)
{
    benchCards.push_back(card);
}

void Player::displayBench()
{
    cout << "Bench cards for Player " << playerName << ":" << endl;
    if (benchCards.empty()) {
        cout << "No cards on the bench" << endl;
        return;
    }

    for (size_t i = 0; i < benchCards.size(); i++) {
        benchCards[i]->displayInfo();
    }
}

void Player::displayAction()
{
    cout << "Action cards for Player " << playerName << ":" << endl;
    if (actionCards.empty()) {
        cout << "No active Pokemon" << endl;
        return;
    }

    for (size_t i = 0; i < actionCards.size(); i++) {
        actionCards[i]->displayInfo();
        cout << "\n";
    }
}

void Player::activatePokemonCard(int benchIndex)
{
    if (benchIndex < 0 || benchIndex >= (int)benchCards.size()) return;

    Card* card = benchCards[benchIndex];
    PokemonCard* pokemon = dynamic_cast<PokemonCard*>(card);
    if (pokemon == nullptr) return;

    cout << playerName << " is activating a Pokemon Card: " << pokemon->getCardName() << endl;
    actionCards.push_back(pokemon);
    benchCards.erase(benchCards.begin() + benchIndex);
}

void Player::attachEnergyCard(int benchIndex, int actionIndex)
{
    if (benchIndex < 0 || benchIndex >= (int)benchCards.size()) return;
    if (actionIndex < 0 || actionIndex >= (int)actionCards.size()) return;

    Card* card = benchCards[benchIndex];
    EnergyCard* energy = dynamic_cast<EnergyCard*>(card);
    if (energy == nullptr) return;

    PokemonCard* pokemon = actionCards[actionIndex];
    cout << playerName << " is attaching Energy Card of type " << energy->getEnergyType()
         << " to the Pokemon " << pokemon->getCardName() << endl;
    pokemon->addEnergy();

    benchCards.erase(benchCards.begin() + benchIndex);
    delete energy;
}

void Player::attack(int actionIndex, int attackIndex, Player& opponent, int opponentActionIndex)
{
    if (actionIndex < 0 || actionIndex >= (int)actionCards.size()) return;
    if (opponentActionIndex < 0 || opponentActionIndex >= (int)opponent.actionCards.size()) return;

    PokemonCard* attacker = actionCards[actionIndex];
    PokemonCard* defender = opponent.actionCards[opponentActionIndex];
    const vector<Attack>& attacks = attacker->getAttacks();
    if (attackIndex < 0 || attackIndex >= (int)attacks.size()) return;

    Attack chosen = attacks[attackIndex];
    if (attacker->getEnergyAttached() < chosen.cost) {
        cout << "Not enough energy to perform this attack" << endl;
        return;
    }

    cout << playerName << " is attacking " << opponent.playerName << "'s Pokemon "
         << defender->getCardName() << " with the Pokemon " << attacker->getCardName()
         << " with its attack: " << chosen.description << endl;
    cout << "Reducing " << chosen.damage << " from " << opponent.playerName
         << "'s Pokemon's HP" << endl;

    defender->reduceHP(chosen.damage);
    if (defender->getHP() <= 0) {
        cout << "Pokemon " << defender->getCardName() << " is defeated" << endl;
    } else {
        cout << "Pokemon " << defender->getCardName() << " is still alive" << endl;
    }
}

void Player::useTrainer(int benchIndex)
{
    if (benchIndex < 0 || benchIndex >= (int)benchCards.size()) return;

    Card* card = benchCards[benchIndex];
    TrainerCard* trainer = dynamic_cast<TrainerCard*>(card);
    if (trainer == nullptr) return;

    cout << playerName << " is using the Trainer Card to \"" << trainer->getTrainerEffect() << "\"" << endl;

    for (size_t i = 0; i < actionCards.size(); i++) {
        actionCards[i]->healToMax();
    }

    benchCards.erase(benchCards.begin() + benchIndex);
    delete trainer;
}
