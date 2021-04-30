#include "ZFraction.hpp"
#include <iostream>
using namespace std;

//constructeur
ZFraction::ZFraction(int numerateur, int denominateur) : m_numerateur(numerateur), m_denominateur(denominateur)
{
  simplifier();
}

int pgcd(int a, int b)
{
  while (b != 0)
  {
    const int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

void ZFraction::simplifier()
{
  int resulatPGCD = pgcd(m_numerateur, m_denominateur);
  m_numerateur /= resulatPGCD;
  m_denominateur /= resulatPGCD;
}

//methode afficher
void ZFraction::affiche(ostream &fluxSortie) const
{
  if (m_denominateur == 1)
  {
    fluxSortie << m_numerateur;
  }
  else
  {
    fluxSortie << m_numerateur << '/' << m_denominateur;
  }
}

//fonction opérateur de fluxSortie
ostream &operator<<(ostream &fluxSortie, ZFraction const &fraction)
{
  fraction.affiche(fluxSortie);
  return fluxSortie;
}

//methode +=
ZFraction &ZFraction::operator+=(ZFraction const &autre)
{
  m_numerateur = autre.m_denominateur * m_numerateur + m_denominateur * autre.m_numerateur;
  m_denominateur = m_denominateur * autre.m_denominateur;
  simplifier();
  return *this;
}

//fonction opérateur +
ZFraction operator+(ZFraction const &a, ZFraction const &b)
{
  ZFraction copie(a);
  copie += b;
  return copie;
}

//methode -=
ZFraction &ZFraction::operator-=(ZFraction const &autre)
{
  m_numerateur = autre.m_denominateur * m_numerateur - m_denominateur * autre.m_numerateur;
  m_denominateur = m_denominateur * autre.m_denominateur;
  return *this;
}

//fonction opérateur -
ZFraction operator-(ZFraction const &a, ZFraction const &b)
{
  ZFraction copie(a);
  copie -= b;
  return copie;
}

//methode opérateur *=
ZFraction &ZFraction::operator*=(ZFraction const &autre)
{
  m_numerateur *= autre.m_numerateur;
  m_denominateur *= autre.m_denominateur;
  simplifier();
  return *this;
}
//fonction opérateur *
ZFraction operator*(ZFraction const &a, ZFraction const &b)
{
  ZFraction copie(a);
  copie *= b;
  return copie;
}

//methode test égalité
bool ZFraction::estEgal(ZFraction const &autre) const
{
  return m_numerateur == autre.m_numerateur && m_denominateur == autre.m_denominateur;
}

//fonction opérateur ==
bool operator==(ZFraction const&a, ZFraction const&b)
{
  return a.estEgal(b);
}

//fonction opérateur !=
bool operator!=(ZFraction const&a, ZFraction const&b)
{
  return !(a.estEgal(b));
}

//methode test inferiorité
bool ZFraction::estPlusPetitQue(ZFraction const &autre) const
{
  return (m_numerateur * autre.m_denominateur < m_denominateur * autre.m_numerateur);
}

//fonction opérateur a < b
bool operator<(ZFraction const&a, ZFraction const&b)
{
  return a.estPlusPetitQue(b);
}

//fonction opérateur a > b
bool operator>(ZFraction const&a, ZFraction const&b)
{
  return !(a.estPlusPetitQue(b));
}

//fonction opérateur a <= b
bool operator<=(ZFraction const&a, ZFraction const&b)
{
  return a.estPlusPetitQue(b) || a == b;
}

//fonction opérateur a >= b
bool operator>=(ZFraction const&a, ZFraction const&b)
{
  return !(a.estPlusPetitQue(b)) || a == b;
}

//methode qui récupère le numérateur
int ZFraction::getNumerateur()
{
  return m_numerateur;
}

//methode qui récupère le dénominateur
int ZFraction::getDenominateur()
{
  return m_denominateur;
}

//methode qui convertie en nombre réel
double ZFraction::nombreReel()
{
  return (1.0 * m_numerateur) / (1.0 * m_denominateur); //convertion en type double en mulpiliant par 1.0
}
