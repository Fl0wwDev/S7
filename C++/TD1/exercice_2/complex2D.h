#ifndef COMPLEX2D_H
#define COMPLEX2D_H

class Complex2D {
    private:
        double reel;
        double imaginaire;
        float valeur;

    public:
        Complex2D() {};
        Complex2D(double _reel, double _imaginaire);
        Complex2D(float _valeur);
        Complex2D(const Complex2D& autre);
        void setReel(double);
        void setImaginaire(double);
        double getReel() const;
        double getImaginaire() const;
        Complex2D operator+(const Complex2D& autre) const;
        Complex2D operator-(const Complex2D& autre) const;
        Complex2D operator*(const Complex2D& autre) const;
        Complex2D operator/(const Complex2D& autre) const;
        Complex2D operator<(const Complex2D& autre) const;
        Complex2D operator>(const Complex2D& autre) const;

};

#endif