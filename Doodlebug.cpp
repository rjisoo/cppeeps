/*********************************************************************
** Program name:    Doodlebug.hpp
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
** Description:     Doodlebug class description here
*********************************************************************/
#include "Doodlebug.hpp"

/*********************************************************************
** Description:     no-args default constructor
*********************************************************************/
Doodlebug::Doodlebug() {}

/*********************************************************************
** Description:     two-arg default constructor with base class
** 					initialization list
*********************************************************************/
Doodlebug::Doodlebug(int row, int col) : Critter{"X", row, col}
{
	// this is being used for debugging - DELETE AFTER DEBUGGED
	static int num = 1;
	cout << "Doodlebug #" << num << " created on Board[" << row << "][" << col << "]" << endl;
	num++;
}

/*********************************************************************
** Description:     destructor
*********************************************************************/
Doodlebug::~Doodlebug() {}

/*********************************************************************
** Description:     description
*********************************************************************/
int Doodlebug::getRow() {
	return row;
}

/*********************************************************************
** Description:     description
*********************************************************************/
int Doodlebug::getCol() {
	return col;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::setRow(int row) {
	this->row = row;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::setCol(int col) {
	this->col = col;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::setStepsSurvived() {
    stepsSurvived++;
    if (stepsSurvived <= 8) {
    	readyToBreed = true;
    }
}

/*********************************************************************
** Description:     description
*********************************************************************/
int Doodlebug::getStepsSurvived() {
	return stepsSurvived;
}

/*********************************************************************
** Description:     description
*********************************************************************/
string Doodlebug::getCritterType() {
	return critterType;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::eat(Critter *bug) {
	if (bug->getCritterType() == "O") {
		// logic to show that ant has been eaten


	}
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::move(Critter ***grid, int ROW, int COL) {
	// for every time step, the doodlebug randomly moves up, down,
	// left, right. If the neighboring cell in the selected direction
	// is occupied, or would move the ant off the grid, then the
	// doodlebug stays in the current cell
	// cout << "Doodlebug Row " << row << " Col " << col << endl;


	// move critter by iterating through board


	// DELETE COUT STMT
	cout << "Doodlebug selected to move \n";

	// generate a random direction to move critter
	int direction;
	direction = generateRandomNumber(1,4);

	// use switch statement to display which direction critter went
	// DEBUGGING, DELETE THIS SWITCH STMT BEFORE SUBMITTING
	switch (direction) {
		case UP:
			cout << "Doodlebug randomly selected to go NORTH\n";
			break;
		case RIGHT:
			cout << "Doodlebug randomly selected to go EAST\n";
			break;
		case DOWN:
			cout << "Doodlebug randomly selected to go SOUTH\n";
			break;
		case LEFT:
			cout << "Doodlebug randomly selected to go WEST\n";
			break;
		default:
			cout << "Unable to get direction to move to!\n";
	}

	cout << "Random direction generated " << direction << endl;

	// use switch statement to move critter based on random number generated
	// NOTES:
	// row = specific doodle row
	// ROW = max ROW size
	switch (direction) {
		case UP: // get NORTH square
			{
				if ( (row - 1) < 0 ) {  // if out of bounds NORTH wall

					//grid[ROW - 1][col] = grid[row][col]; // testing with this code

					if (grid[ROW - 1][col] == nullptr) {   // go to last row

						// check if critter has already moved during time step
						if (getCritterMoved()) {
							cout << "Did critter move already? " << getCritterMoved() << endl;
							// if critter already moved, do not move it again

						}
						else {
							// DEBUGGING - DELETE WHEN DONE
							cout << "\nPACMAN NORTH move\n";
							cout << "Doodlebug move NORTH available, " << "Move to [" << ROW - 1 << "][" << col << "]" << endl;

							// set critter moved bool in Doodlebug to true
							setCritterMoved(true);

							// move doodlebug
							grid[ROW - 1][col] = grid[row][col];


							// DEBUGGING - DELETE WHEN DONE
							cout << "OLD Row " << getRow() << " Col " << getCol() << endl;

							// update doodlebug row and col in doodlebug class
							setRow( ROW - 1 );
							setCol( col );

							// DEBUGGING - DELETE WHEN DONE
							cout << "NEW Row " << getRow() << " Col " << getCol() << endl;

							// update doodlebug stepsSurvived counter in doodlebug class
							setStepsSurvived();
							// DEBUGGING - DELETE WHEN DONE
							cout << "Steps moved by [" << row << "][" << col << "]" << getStepsSurvived() << endl;

							// set old pointer to null
							grid[row][col] = nullptr;
						}
					}
					else {
						// DEBUGGING - DELETE WHEN DONE
						cout << "Doodlebug move NORTH " << "[" << row << "][" << col<< "]" << " unavailable\n";
					}
				}
				else {
					if (grid[row - 1][col] == nullptr) {

						// check if critter has already moved during time step
						if (getCritterMoved()) {
							// if critter already moved, do not move it again
						}
						else {
							cout << "Normal NORTH move\n";
							// DEBUGGING - DELETE WHEN DONE
							cout << "Doodlebug move NORTH available, " << "Move to [" << row - 1 << "][" << col << "]" << endl;

							// set critter moved bool in Doodlebug (must set bool before moving)
							setCritterMoved(true);

							// move doodlebug
							grid[row - 1][col] = grid[row][col];

							// DEBUGGING - DELETE WHEN DONE
							cout << "OLD Row " << getRow() << " Col " << getCol() << endl;

							// update doodlebug row and col in doodlebug class
							setRow( row - 1 );
							setCol( col );

							// DEBUGGING - DELETE WHEN DONE
							cout << "NEW Row " << getRow() << " Col " << getCol() << endl;

							// update doodlebug stepsSurvived counter in doodlebug class
							setStepsSurvived();
							// DEBUGGING - DELETE WHEN DONE
							cout << "Steps moved by [" << row << "][" << col << "]" << getStepsSurvived() << endl;

							// delete old pointer here? I don't think so
							// delete board[r_index][c_index];

							// set old pointer to null
							grid[row][col] = nullptr;
						}
					}
					else {
						// DEBUGGING - DELETE WHEN DONE
						cout << "Doodlebug move NORTH " << "[" << row << "][" << col << "]" << " unavailable\n";
					}
				}
			}
			break;
		case RIGHT: // get EAST square
			{
				if ( (col + 1) >= COL ) {  // if out of bounds EAST wall
					if (grid[row][0] == nullptr) {   // go to first col

						// check if critter has already moved during time step
						if (getCritterMoved()) {
							// if critter already moved, do not move it again
						}
						else {
							// DEBUGGING - DELETE WHEN DONE
							cout << "Doodlebug move EAST available, " << "Move to [" << row << "][" << 0 << "]" << endl;

							// set critter moved bool in Doodlebug to true
							setCritterMoved(true);

							// move doodlebug
							grid[row][0] = grid[row][col];


							// DEBUGGING - DELETE WHEN DONE
							cout << "OLD Row " << getRow() << " Col " << getCol() << endl;

							// update doodlebug row and col in doodlebug class
							setRow( row );
							setCol( 0 );

							// DEBUGGING - DELETE WHEN DONE
							cout << "NEW Row " << getRow() << " Col " << getCol() << endl;

							// update doodlebug stepsSurvived counter in doodlebug class
							setStepsSurvived();
							// DEBUGGING - DELETE WHEN DONE
							cout << "Steps moved by [" << row << "][" << col << "]" << getStepsSurvived() << endl;

							// set old pointer to null
							grid[row][col] = nullptr;
						}
					}
					else {
						// DEBUGGING - DELETE WHEN DONE
						cout << "Doodlebug move EAST " << "[" << row << "][" << col << "]" << " unavailable\n";
					}
				}
				else {
					if (grid[row][col + 1] == nullptr) {

						// check if critter has already moved during time step
						if (getCritterMoved()) {
							// if critter already moved, do not move it again
						}
						else {
							// DEBUGGING - DELETE WHEN DONE
							cout <<  "Doodlebug move EAST available, " << "Move to [" << row << "][" << col + 1 << "]" << endl;

							// set critter moved bool in Doodlebug (must set bool before moving)
							setCritterMoved(true);

							// move doodlebug
							grid[row][col + 1] = grid[row][col];

							// DEBUGGING - DELETE WHEN DONE
							cout << "OLD Row " << getRow() << " Col " << getCol() << endl;

							// update doodlebug row and col in doodlebug class
							setRow( row );
							setCol( col + 1 );

							// DEBUGGING - DELETE WHEN DONE
							cout << "NEW Row " << getRow() << " Col " << getCol() << endl;

							// update doodlebug stepsSurvived counter in doodlebug class
							setStepsSurvived();
							// DEBUGGING - DELETE WHEN DONE
							cout << "Steps moved by [" << row << "][" << col << "]" << getStepsSurvived() << endl;

							// set old pointer to null
							grid[row][col] = nullptr;
						}
					}
					else {
						// DEBUGGING - DELETE WHEN DONE
						cout << "Doodlebug move EAST " << "[" << row << "][" << col << "]" << " unavailable\n";
					}
				}
			}
			break;
		case DOWN: // get SOUTH square
			{
//					if (row + 1 >= ROW) {  // if out of bounds SOUTH wall
//						if (grid[0][col] == nullptr) { // go to first row
//
//							// check if critter has already moved during time step
//							if (getCritterMoved()) {
//								// if critter already moved, do not move it again
//							}
//							else {
//								// DEBUGGING - DELETE WHEN DONE
//								cout <<  critter << " move NORTH available, " << "Move to [" << 0 << "][" << col << "]" << endl;
//
//								// set critter moved bool in Doodlebug to true
//								setCritterMoved(true);
//
//								// move doodlebug
//								grid[0][col] = grid[row][col];
//
//								// update doodlebug row and col in doodlebug class
//								setRow( 0 );
//								setCol( col );
//
//								// DEBUGGING - DELETE WHEN DONE
//								cout << "OLD Row " << getRow() << " Col " << getCol() << endl;
//								cout << "NEW Row " << grid[0][col]->getRow() << " Col " << grid[0][col]->getCol() << endl;
//
//								// update doodlebug stepsSurvived counter in doodlebug class
//								setStepsSurvived();
//								// DEBUGGING - DELETE WHEN DONE
//								cout << "Steps moved " << grid[0][col]->getStepsSurvived() << endl;
//
//								// set old pointer to null
//								grid[row][col] = nullptr;
//							}
//						}
//						else {
//							// DEBUGGING - DELETE WHEN DONE
//							cout << critter << " move SOUTH " << "[" << row << "][" << col << "]" << " unavailable\n";
//						}
//					}
//					else {
//						if (grid[row + 1][col] == nullptr) {
//
//							// check if critter has already moved during time step
//							if (getCritterMoved()) {
//								// if critter already moved, do not move it again
//							}
//							else {
//								// DEBUGGING - DELETE WHEN DONE
//								cout << critter << " move SOUTH available, " << "Move to [" << row + 1 << "][" << col << "]" << endl;
//
//								// set critter moved bool in Doodlebug (must set bool before moving)
//								setCritterMoved(true);
//
//								// move doodlebug
//								grid[row + 1][col] = grid[row][col];
//
//								// update doodlebug row and col in doodlebug class
//								setRow( row + 1 );
//								setCol( col );
//
//								// DEBUGGING - DELETE WHEN DONE
//								cout << "OLD Row " << getRow() << " Col " << getCol() << endl;
//								cout << "NEW Row " << grid[row + 1][col]->getRow() << " Col " << grid[row + 1][col]->getCol() << endl;
//
//								// update doodlebug stepsSurvived counter in doodlebug class
//								setStepsSurvived();
//								// DEBUGGING - DELETE WHEN DONE
//								cout << "Steps moved " << grid[row + 1][col]->getStepsSurvived() << endl;
//
//								// set old pointer to null
//								grid[row][col] = nullptr;
//							}
//						}
//						else {
//							// DEBUGGING - DELETE WHEN DONE
//							cout << critter << " move SOUTH " << "[" << row << "][" << col << "]" << " unavailable\n";
//						}
//					}
			}
			break;
		case LEFT: // get WEST square
			{
//					if ( (col - 1) < 0 ) {  // if out of bounds WEST wall
//						if (grid[row][col - 1] == nullptr) {   // go to last col
//
//							// check if critter has already moved during time step
//							if (getCritterMoved()) {
//								// if critter already moved, do not move it again
//							}
//							else {
//								// DEBUGGING - DELETE WHEN DONE
//								cout << critter << " move WEST available, " << "Move to [" << row << "][" << col - 1 << "]" << endl;
//
//								// set critter moved bool in Doodlebug to true
//								setCritterMoved(true);
//
//								// move doodlebug to last column
//								grid[row][col - 1] = grid[row][col];
//
//								// update doodlebug row and col in doodlebug class
//								setRow( row );
//								setCol( col - 1 );
//
//								// DEBUGGING - DELETE WHEN DONE
//								cout << "OLD Row " << getRow() << " Col " << getCol() << endl;
//								cout << "NEW Row " << grid[row][col - 1]->getRow() << " Col " << grid[row][col - 1]->getCol() << endl;
//
//								// update doodlebug stepsSurvived counter in doodlebug class
//								setStepsSurvived();
//								// DEBUGGING - DELETE WHEN DONE
//								cout << "Steps moved " << grid[row][col - 1]->getStepsSurvived() << endl;
//
//								// set old pointer to null
//								grid[row][col] = nullptr;
//							}
//						}
//						else {
//							// DEBUGGING - DELETE WHEN DONE
//							cout << critter << " move WEST " << "[" << row << "][" << col << "]" << " unavailable\n";
//						}
//					}
//					else {
//						if (grid[row][col - 1] == nullptr) {
//
//							// check if critter has already moved during time step
//							if (getCritterMoved()) {
//								// if critter already moved, do not move it again
//							}
//							else {
//								// DEBUGGING - DELETE WHEN DONE
//								cout << critter << " move WEST available, " << "Move to [" << row << "][" << col - 1 << "]" << endl;
//
//								// set critter moved bool in Doodlebug (must set bool before moving)
//								setCritterMoved(true);
//
//								// move doodlebug
//								grid[row][col - 1] = grid[row][col];
//
//								// update doodlebug row and col in doodlebug class
//								setRow( row );
//								setCol( col - 1 );
//
//								// DEBUGGING - DELETE WHEN DONE
//								cout << "OLD Row " << getRow() << " Col " << getCol() << endl;
//								cout << "NEW Row " << grid[row][col - 1]->getRow() << " Col " << grid[row][col - 1]->getCol() << endl;
//
//								// update doodlebug stepsSurvived counter in doodlebug class
//								setStepsSurvived();
//								// DEBUGGING - DELETE WHEN DONE
//								cout << "Steps moved " << grid[row][col - 1]->getStepsSurvived() << endl;
//
//								// set old pointer to null
//								grid[row][col] = nullptr;
//							}
//						}
//						else {
//							// DEBUGGING - DELETE WHEN DONE
//							cout << critter << " move WEST " << "[" << row << "][" << col << "]" << " unavailable\n";
//						}
//					}
			}
			break;
		default:
			cout << "Unable to determine direction to move!\n";
	}


	// reset all doodlebug move bool to false (otherwise you may move bugs more than once each time step)
//	for (int r_index = 0; r_index < row; r_index++) {
//		for (int c_index = 0; c_index < col; c_index++) {
//			if (grid[r_index][c_index] != nullptr) {
//				if (grid[r_index][c_index]->getCritterType() == "X") {
//					grid[r_index][c_index]->setCritterMoved(false);
//				}
//				if (grid[r_index][c_index]->getCritterType() == "O") {
//					grid[r_index][c_index]->setCritterMoved(false);
//				}
//			}
//		}
//	}

}

/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::setCritterMoved(bool moved) {
	critterMoved = moved;
}

/*********************************************************************
** Description:     description
*********************************************************************/
bool Doodlebug::getCritterMoved() {
	return critterMoved;
}

/*********************************************************************
** Description:     description
*********************************************************************/
void Doodlebug::breed(Critter ***grid, int ROW, int COL) {
	// if a doodlebug survives for eight time steps, at the end of the
	// time step, it will spawn off a new doodlebug in the same manner
	// as the ant (only bree into an adjacent empty cell)
	cout << "Steps survived " << stepsSurvived << endl;

	int select = generateRandomNumber(1,4);
	// find which spaces are empty and set to TRUE in array
	bool keepLooking = true;

	while (keepLooking) {
		// generate a random number from 1-4
		select = generateRandomNumber(1,4);
		// if all four adjacent sides are occupied, do not breed
		if ( (row > 0 && grid[row - 1][col] != nullptr) &&
		     (col < COL-1 && grid[row][col + 1] != nullptr) &&
		     (row < ROW-1 && grid[row + 1][col] != nullptr) &&
		     (col > 0 && grid[row][col - 1] != nullptr) ) {

			// if all sides around doodlebug unavailable, do not spawn
			select = 5;
			keepLooking = false;
			cout << "All sides are full\n";
		}

		// DEBUGGING - DELETE COUT WHEN DONE
		cout << "Side selected " << select << endl;

		// if adjacent sides available, randomly select one
		// "select" variable will end while-loop and be input for
		// next switch statement below that creates a new doodlebug
		switch (select) {
			case 1:
				// NORTH
				if ((row - 1) >= 0 && grid[row - 1][col] == nullptr) {
					// DEBUGGING - DELETE COUT WHEN DONE
					cout << "NORTH selected " << select << endl;
				}
				keepLooking = false;
				break;
			case 2:
				// EAST
				if ((col + 1) < COL && grid[row][col + 1] == nullptr) {
					// DEBUGGING - DELETE COUT WHEN DONE
					cout << "EAST selected " << select << endl;
				}
				keepLooking = false;
				break;
			case 3:
				// SOUTH
				if ((row + 1) < ROW && grid[row + 1][col] == nullptr) {
					// DEBUGGING - DELETE COUT WHEN DONE
					cout << "SOUTH selected " << select << endl;
				}
				keepLooking = false;
				break;
			case 4:
				// WEST
				if ((col - 1) >= 0 && grid[row][col - 1] == nullptr) {
					// DEBUGGING - DELETE COUT WHEN DONE
					cout << "WEST selected " << select << endl;
				}
				keepLooking = false;
				break;
			default:
				cout << "Unable to determine selection!\n";
		}
	}

	// if a doodlebug has survived for 8 steps or more, than the doodlebug
	// should breed if there is space available
	// NEED TO INCORPORATE EAT FUNCTION
	if (stepsSurvived >= 8) {
		switch (select) {
			case 1:
				// breed NORTH square
				if ((row - 1) >= 0 && grid[row - 1][col] == nullptr) {
					grid[row - 1][col] = new Doodlebug(row - 1, col);
				}
				else {
					// DEBUGGING - this else stmt can be deleted
					cout << "Unable to spawn a doodlebug\n";
				}
				break;
			case 2:
				// breed EAST square
				if ((col + 1) < COL && grid[row][col + 1] == nullptr) {
					grid[row][col + 1] = new Doodlebug(row, col + 1);
				}
				else {
					// DEBUGGING - this else stmt can be deleted
					cout << "Unable to spawn a doodlebug\n";
				}
				break;
			case 3:
				// breed SOUTH square
				if ((row + 1) < ROW && grid[row + 1][col] == nullptr) {
					grid[row + 1][col] = new Doodlebug(row + 1, col);
				}
				else {
					// DEBUGGING - this else stmt can be deleted
					cout << "Unable to spawn a doodlebug\n";
				}
				break;
			case 4:
				// breed WEST square
				if ((col - 1) >= 0 && grid[row][col - 1] == nullptr) {
					grid[row][col - 1] = new Doodlebug(row, col - 1);
				}
				else {
					// DEBUGGING - this else stmt can be deleted
					cout << "Unable to spawn a doodlebug\n";
				}
				break;
			default:
				cout << "Doodlebug unable to breed, all spaces occupied!\n";
		}
	}
}