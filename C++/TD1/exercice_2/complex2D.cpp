#include "complex2D.h"

Complex2D::Complex2D(double _reel, double _imaginaire){
    reel = _reel;
    imaginaire = _imaginaire;
};

Complex2D::Complex2D(float _valeur){
    reel = valeur;
    imaginaire = valeur;
};

Complex2D::Complex2D(const Complex2D& autre){
    reel = autre.reel;
    imaginaire = autre.imaginaire;
};

void Complex2D::setImaginaire(double _imaginaire){
    imaginaire = _imaginaire;
};

void Complex2D::setReel(double _reel){
    reel = _reel;
};

double Complex2D::getImaginaire() const{
    return imaginaire;
};

double Complex2D::getReel() const{
    return reel;
};

Complex2D Complex2D::operator+(const Complex2D& autre) const {
    return Complex2D(reel + autre.reel, imaginaire + autre.imaginaire);
};

Complex2D Complex2D::operator-(const Complex2D& autre) const {
    return Complex2D(reel - autre.reel, imaginaire - autre.imaginaire);
};

Complex2D Complex2D::operator*(const Complex2D& autre) const {
    return Complex2D(reel * autre.reel, imaginaire * autre.imaginaire);
};

Complex2D Complex2D::operator/(const Complex2D& autre) const {
    return Complex2D(reel / autre.reel, imaginaire / autre.imaginaire);
};

Complex2D Complex2D::operator<(const Complex2D& autre) const {
    return Complex2D(reel / autre.reel, imaginaire / autre.imaginaire);
};

Complex2D Complex2D::operator>(const Complex2D& autre) const {
    return Complex2D(reel / autre.reel, imaginaire / autre.imaginaire);
};