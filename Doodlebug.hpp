/*********************************************************************
** Program Name:  Predator vs. Prey
** Class Name:    Doodlebug
** Parent:        Critter
** Author:        Kuljot Biring, Rachel Schlick, Ryan Gross,
**                Sandro Aguilar, Jeesoo Ryoo
** Date:          02/17/2019
** Description:   Class specification file for Doodlebug class.
*********************************************************************/
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "Critter.hpp"

class Doodlebug : public Critter
{
private:
  int stepsStarved;
  void checkAdjacentCells(Critter ***&grid, int gridROW, int gridCOL);
  int eat(Critter ***&grid);

protected:
public:
  Doodlebug();
  Doodlebug(int row, int col);
  ~Doodlebug();
  void setStepsSurvived() override;
  int getStepsSurvived() override;
  bool isStarved() override;
  int move(Critter ***&grid, int gridROW, int gridCOL) override;
  int breed(Critter ***&grid, int row, int col) override;
};

#endif
