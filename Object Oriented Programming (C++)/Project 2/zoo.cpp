/********************************************************************* 
** Author: Serena Tay
** Date: July 22, 2018
** Description: Project 2 Assignnment (Zoo Tycoon)
** Zoo class cpp file
*********************************************************************/

#include <iostream>
#include "zoo.hpp"
#include <ctime>
/*
#include "animal.hpp"
#include "penguin.hpp"
#include "tiger.hpp"
#include "turtle.hpp"
#include "game.hpp"
#include "menu.hpp"
*/

using std::cin;
using std::cout;
using std::endl;
using std::string;

Zoo::Zoo() //initialize dynamic arrays and bank balance to requirements
{
    penguinArray = new Penguin[10];
    tigerArray = new Tiger[10];
    turtleArray = new Turtle[10];
    bankBalance = 100000;
    penguinCount = 0;
    tigerCount = 0;
    turtleCount = 0;
    penguinCapacity = 10;
    tigerCapacity = 10;
    turtleCapacity = 10;
    /*
    const int costPenguin = 1000;
    const int costTiger = 10000;
    const int costTurtle = 100;
    const int baseFoodCost = 10;
    const int foodCostPenguin = baseFoodCost;
    const int foodCostTiger = 5 * baseFoodCost;
    const int foodCostTurtle = baseFoodCost * (1 / 2);

    */
}

int Zoo::bonusPayoff()
{
    int bonusResult = (rand() % 250) + 250; //to obtain a pseudo-random number between 250 and 500
    int payoff = tigerCount * bonusResult;
    return payoff;
}

void Zoo::updateAnimalCount(int animalType, int number)
{
    if (animalType == 1)
    {
        penguinCount = penguinCount + number;
    }

    if (animalType == 2)
    {
        tigerCount = tigerCount + number;
    }

    if (animalType == 3)
    {
        turtleCount = turtleCount + number;
    }
}

void Zoo::createAnimal(int animalType, int number, int buyOrBorn) //create animal object
{
    // 0 for first buy (start at age 1 aka an adult)
    // 1 for born (start at age 0)
    // 2 for daily buy (start at age 3 aka an adult)
    if (buyOrBorn == 0) //bought during first buy
    {
        if (animalType == 1) //penguin bought
        {
            for (int i = 0; i < number; i++)
            {
                penguinArray[(penguinCount - 1)] = Penguin();
            }
        }

        if (animalType == 2) //tiger bought
        {
            for (int i = 0; i < number; i++)
            {
                tigerArray[(tigerCount - 1)] = Tiger();
            }
        }

        if (animalType == 3) //turtle bought
        {
            for (int i = 0; i < number; i++)
            {
                turtleArray[(turtleCount - 1)] = Turtle();
            }
        }
    }

    if (buyOrBorn == 1) //born
    {
        if (animalType == 1) //penguin born
        {
            for (int i = 0; i < number; i++)
            {
                penguinArray[(penguinCount - 1)] = Penguin(0);
            }
        }

        if (animalType == 2) //tiger born
        {
            for (int i = 0; i < number; i++)
            {
                tigerArray[(tigerCount - 1)] = Tiger(0);
            }
        }

        if (animalType == 3) //turtle born
        {
            for (int i = 0; i < number; i++)
            {
                turtleArray[(turtleCount - 1)] = Turtle(0);
            }
        }
    }

    if (buyOrBorn == 3) // purchase from daily buy
    {
        if (animalType == 1) //penguin born
        {
            for (int i = 0; i < number; i++)
            {
                penguinArray[(penguinCount - 1)] = Penguin(3);
            }
        }

        if (animalType == 2) //tiger born
        {
            for (int i = 0; i < number; i++)
            {
                tigerArray[(tigerCount - 1)] = Tiger(3);
            }
        }

        if (animalType == 3) //turtle born
        {
            for (int i = 0; i < number; i++)
            {
                turtleArray[(turtleCount - 1)] = Turtle(3);
            }
        }
    }
}

void Zoo::removeSickAnimal(int animalType) //remove last object in dynamic array
{
    if (animalType == 1) // penguin
    {
        Penguin *temp = NULL;
        temp = new Penguin[penguinCapacity];
        for (int i = 0; i < (penguinCount - 1); i++) //copy info from old array in the temp array except for the last object in the array
        {
            temp[i] = penguinArray[i];
        }
        delete[] penguinArray; //delete old array
        penguinArray = temp;   // change pointer to the memory address of the new array
        temp = NULL;           //set pointer to NULL
    }

    if (animalType == 2) //tiger
    {
        Tiger *temp = NULL;
        temp = new Tiger[tigerCapacity];
        for (int i = 0; i < (tigerCount - 1); i++) //copy info from old array in the temp array except for the last object in the array
        {
            temp[i] = tigerArray[i];
        }
        delete[] tigerArray; //delete old array
        tigerArray = temp;   // change pointer to the memory address of the new array
        temp = NULL;         //set pointer to NULL
    }
    if (animalType == 3) //turtle
    {
        Turtle *temp = NULL;
        temp = new Turtle[turtleCapacity];
        for (int i = 0; i < (turtleCount - 1); i++) //copy info from old array in the temp array except for the last object in the array
        {
            temp[i] = turtleArray[i];
        }
        delete[] turtleArray; //delete old array
        turtleArray = temp;   // change pointer to the memory address of the new array
        temp = NULL;          //set pointer to NULL
    }
}

int Zoo::getAnimalCount(int animalType) //to get count for specific animal type
{
    if (animalType == 1) //penguin
    {
        return penguinCount;
    }

    if (animalType == 2) //tiger
    {
        return tigerCount;
    }

    if (animalType == 3) //turtle
    {
        return turtleCount;
    }

    else
        return 0;
}

int Zoo::getAnimalAge(int animalType) //to get count for specific animal type
{
    if (animalType == 1) //penguin
    {
        return penguinArray[0].getAge();
    }

    if (animalType == 2) //tiger
    {
        return tigerArray[0].getAge();
    }

    if (animalType == 3) //turtle
    {
        return turtleArray[0].getAge();
    }

    else
        return 0;
}

void Zoo::updateAge() //make animal grow a day older
{
    for (int i = 0; i < penguinCount; i++)
    {
        penguinArray[i].growOld();
    }

    for (int i = 0; i < tigerCount; i++)
    {
        tigerArray[i].growOld();
    }

    for (int i = 0; i < turtleCount; i++)
    {
        turtleArray[i].growOld();
    }
}

bool Zoo::checkAdult(int animalType)
{

    if (animalType == 1) //penguin
        for (int i = 0; i < penguinCount; i++)
        {
            if (penguinArray[i].getAge() > 3)
                return true;
        }

    if (animalType == 2)
        for (int i = 0; i < tigerCount; i++)
        {
            if (tigerArray[i].getAge() > 3)
                return true;
        }

    if (animalType == 3)
        for (int i = 0; i < turtleCount; i++)
        {
            if (turtleArray[i].getAge() > 3)
                return true;
        }
    return false;
}

void Zoo::updateBankBalance(int amount)
{
    bankBalance = bankBalance + amount;
}

void Zoo::payFoodCost() // deduct food cost for the day for all animals
{
    int totalFoodCostPenguin = penguinCount * foodCostPenguin * (-1);
    updateBankBalance(totalFoodCostPenguin);
    int totalFoodCostTiger = tigerCount * foodCostTiger * (-1);
    updateBankBalance(totalFoodCostTiger);
    int totalFoodCostTurtle = turtleCount * foodCostTurtle * (-1);
    updateBankBalance(totalFoodCostTurtle);
}

void Zoo::printDailyReport(int day)
{
    cout << endl;
    cout << "Summary report for Day " << day << " :" << endl;
    cout << "Bank balance: " << bankBalance << endl;
    cout << "Animals you current have: " << endl;
    cout << "Penguins: " << penguinCount << endl;
    cout << "Penguin current capacity: " << (penguinCapacity - penguinCount) << endl;
    cout << "Tiger: " << tigerCount << endl;
    cout << "Tiger current capacity: " << (tigerCapacity - tigerCount) << endl;
    cout << "Turtle: " << turtleCount << endl;
    cout << "Turtle current capacity: " << (turtleCapacity - turtleCount) << endl;
    cout << endl;
}

bool Zoo::checkBankBalance()
{
    if (bankBalance > 0)
    {
        return true;
    }

    return false;
}

void Zoo::resizeArray(int event, int animalType) //resize array when near capacity
{
    //Animal *temp = NULL;

    // 2 situations, 1. when a purchase of an animal is made  2. when a baby boom occurred
    if (event == 1) //animal purchased
    {
        if (animalType == 1) // penguin
        {
            if ((penguinCapacity - penguinCount) == 1) //one spot remaining
            {
                Penguin *temp = NULL;
                temp = new Penguin[penguinCapacity * 2];
                for (int i = 0; i < penguinCapacity; i++) //copy info from old array in the temp array
                {
                    temp[i] = penguinArray[i];
                }
                delete[] penguinArray; //delete old array
                penguinArray = temp;   // change pointer to the memory address of the new array
                temp = NULL;           //set pointer to NULL
                increaseCapacityCounter("penguin");
            }
        }

        if (animalType == 2) //tiger
        {
            if ((tigerCapacity - tigerCount) == 1) //one spot remaining
            {
                Tiger *temp = NULL;
                temp = new Tiger[tigerCapacity * 2];
                for (int i = 0; i < tigerCapacity; i++) //copy info from old array in the temp array
                {
                    temp[i] = tigerArray[i];
                }
                delete[] tigerArray; //delete old array
                tigerArray = temp;   // change pointer to the memory address of the new array
                temp = NULL;         //set pointer to NULL
                increaseCapacityCounter("tiger");
            }
        }
        if (animalType == 3) //turtle
        {
            if ((turtleCapacity - turtleCount) == 1) //one spot remaining
            {
                Turtle *temp = NULL;
                temp = new Turtle[turtleCapacity * 2];
                for (int i = 0; i < turtleCapacity; i++) //copy info from old array in the temp array
                {
                    temp[i] = turtleArray[i];
                }
                delete[] turtleArray; //delete old array
                turtleArray = temp;   // change pointer to the memory address of the new array
                temp = NULL;          //set pointer to NULL
                increaseCapacityCounter("turtle");
                // source used: https://www.cs.fsu.edu/~myers/c++/notes/dma.html
            }
        }
    }

    if (event == 2) //baby boom
    {
        if (animalType == 1) // penguin
        {
            if ((penguinCapacity - penguinCount) < 5)
            {
                Penguin *temp = NULL;
                temp = new Penguin[penguinCapacity * 2];
                for (int i = 0; i < penguinCapacity; i++) //copy info from old array in the temp array
                {
                    temp[i] = penguinArray[i];
                }
                delete[] penguinArray; //delete old array
                penguinArray = temp;   // change pointer to the memory address of the new array
                temp = NULL;           //set pointer to NULL
                increaseCapacityCounter("penguin");
            }
        }

        if (animalType == 2) //tiger
        {
            if ((tigerCapacity - tigerCount) < 1)
            {
                Tiger *temp = NULL;
                temp = new Tiger[tigerCapacity * 2];
                for (int i = 0; i < tigerCapacity; i++) //copy info from old array in the temp array
                {
                    temp[i] = tigerArray[i];
                }
                delete[] tigerArray; //delete old array
                tigerArray = temp;   // change pointer to the memory address of the new array
                temp = NULL;         //set pointer to NULL
                increaseCapacityCounter("tiger");
            }
        }
        if (animalType == 3) //turtle
        {
            Turtle *temp = NULL;
            temp = new Turtle[turtleCapacity * 2];
            for (int i = 0; i < turtleCapacity; i++) //copy info from old array in the temp array
            {
                temp[i] = turtleArray[i];
            }
            delete[] turtleArray; //delete old array
            turtleArray = temp;   // change pointer to the memory address of the new array
            temp = NULL;          //set pointer to NULL
            increaseCapacityCounter("turtle");
            // source used: https://www.cs.fsu.edu/~myers/c++/notes/dma.html
        }
    }
}

void Zoo::increaseCapacityCounter(string animalName) //when capacity is doubled
{
    if (animalName == "penguin")
        penguinCapacity = penguinCapacity * 2;
    if (animalName == "tiger")
        tigerCapacity = tigerCapacity * 2;
    if (animalName == "turtle")
        turtleCapacity = turtleCapacity * 2;
}
void Zoo::deletePointers()
{
    delete[] penguinArray; // deallocates the array
    penguinArray = NULL;   //set pointer to NULL
    delete[] tigerArray;   // deallocates the array
    tigerArray = NULL;     //set pointer to NULL
    delete[] turtleArray;  // deallocates the array
    turtleArray = NULL;    //set pointer to NULL
}
