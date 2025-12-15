#include "headers/player.h"

Player::Player(const string& name) : playerName(name) {}

Player::~Player()
{
    deleteCards();
}

void Player::deleteCards()
{
    for (auto* c : benchCards) {
        delete c;
    }
    for (auto* p : actionCards) {
        delete p;
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

    for (auto* c : benchCards) {
        c->displayInfo();
    }
}

void Player::displayAction()
{
    cout << "Action cards for Player " << playerName << ":" << endl;
    if (actionCards.empty()) {
        cout << "No active Pokemon" << endl;
        return;
    }

    for (auto* p : actionCards) {
        p->displayInfo();
        cout << "\n";
    }
}

void Player::activatePokemonCard(int benchIndex)
{
    if (benchIndex < 0 || benchIndex >= static_cast<int>(benchCards.size())) return;
    auto* card = benchCards[benchIndex];
    auto* pokemon = dynamic_cast<PokemonCard*>(card);
    if (!pokemon) return;

    cout << playerName << " is activating a Pokemon Card: " << pokemon->getCardName() << endl;
    actionCards.push_back(pokemon);
    benchCards.erase(benchCards.begin() + benchIndex);
}

void Player::attachEnergyCard(int benchIndex, int actionIndex)
{
    if (benchIndex < 0 || benchIndex >= static_cast<int>(benchCards.size())) return;
    if (actionIndex < 0 || actionIndex >= static_cast<int>(actionCards.size())) return;

    auto* card = benchCards[benchIndex];
    auto* energy = dynamic_cast<EnergyCard*>(card);
    if (!energy) return;

    auto* pokemon = actionCards[actionIndex];
    cout << playerName << " is attaching Energy Card of type " << energy->getEnergyType()
         << " to the Pokemon " << pokemon->getCardName() << endl;
    pokemon->addEnergy();

    benchCards.erase(benchCards.begin() + benchIndex);
    delete energy;
}

void Player::attack(int actionIndex, int attackIndex, Player& opponent, int opponentActionIndex)
{
    if (actionIndex < 0 || actionIndex >= static_cast<int>(actionCards.size())) return;
    if (opponentActionIndex < 0 || opponentActionIndex >= static_cast<int>(opponent.actionCards.size())) return;

    PokemonCard* attacker = actionCards[actionIndex];
    PokemonCard* defender = opponent.actionCards[opponentActionIndex];
    const auto& attacks = attacker->getAttacks();
    if (attackIndex < 0 || attackIndex >= static_cast<int>(attacks.size())) return;

    const Attack& chosen = attacks[attackIndex];
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
    if (benchIndex < 0 || benchIndex >= static_cast<int>(benchCards.size())) return;
    auto* card = benchCards[benchIndex];
    auto* trainer = dynamic_cast<TrainerCard*>(card);
    if (!trainer) return;

    cout << playerName << " is using the Trainer Card to \"" << trainer->getTrainerEffect() << "\"" << endl;
    for (auto* p : actionCards) {
        p->healToMax();
    }

    benchCards.erase(benchCards.begin() + benchIndex);
    delete trainer;
}
