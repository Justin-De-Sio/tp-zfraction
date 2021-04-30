#ifndef DEF_FRACTION
#define DEF_FRACTION
#include <iostream>

class ZFraction
{
public:
   ZFraction(int numerateur = 0, int denominateur = 1); //contructeur

   void simplifier();                            // simplifie la fraction
   void affiche(std::ostream &fluxSortie) const; // affichage

   int getNumerateur();
   int getDenominateur();
   double nombreReel();

   ZFraction &operator+=(ZFraction const &autre);
   ZFraction &operator-=(ZFraction const &autre);
   ZFraction &operator*=(ZFraction const &autre);

   bool estEgal(ZFraction const &autre) const;
   bool estPlusPetitQue(ZFraction const &autre) const;

private:
   int m_numerateur;   //Le numérateur de la fraction
   int m_denominateur; //Le dénominateur de la fraction
};

std::ostream &operator<<(std::ostream &flux, ZFraction const &fraction);

ZFraction operator+(ZFraction const &a, ZFraction const &b);
ZFraction operator-(ZFraction const &a, ZFraction const &b);
ZFraction operator*(ZFraction const &a, ZFraction const &b);

bool operator==(ZFraction const &a, ZFraction const &b);
bool operator!=(ZFraction const &a, ZFraction const &b);
bool operator<(ZFraction const &a, ZFraction const &b);
bool operator>(ZFraction const &a, ZFraction const &b);
bool operator<=(ZFraction const &a, ZFraction const &b);
bool operator>=(ZFraction const &a, ZFraction const &b);
int pgcd(int a, int b);

#endif