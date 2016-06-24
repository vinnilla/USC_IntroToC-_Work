//space.h
#ifndef SPACE_H
#define SPACE_H

class Space {
 private:
  int x;
  int y;
  int buyPrice;
  int rentPrice;
  int updatedRent;
  int group; // 1=mazda 2=honda 3=toyota 4=merc 5=audi 6=bmw 7=porsche 8=maserati 9=taxi 10=bus
  int upgradePrice;
  int upgrade;
  int owner;
  bool monopoly;
  bool buyable;
  bool upgradable;
  int type; // 0=cars 1=taxi 2=bus 3=community chest 4=chance 5=income tax 6=luxury tax 7=gotojail 9=nothing

 public:
  Space();
  void setupinfo(int, int, int, int);
  void setType(int);
  void setX(int);
  void setY(int);
  void setOwner(int);

  int retrieveX();
  int retrieveY();
  int retrieveType();
  int retrieveBuy();
  int retrieveRent();
  int retrieveOwner();
  int retrieveUpgrade();
  int retrieveUpgradePrice();
  int retrieveGroup();
  bool checkMonopoly();
  bool checkBuyable();

  void upgradesingle();

  void updateMonopoly(int);
};

#endif
