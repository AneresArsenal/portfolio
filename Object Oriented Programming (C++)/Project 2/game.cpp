/********************************************************************* 
** Author: Serena Tay
** Date: July 22, 2018
** Description: Project 2 Assignnment (Zoo Tycoon)
** Game class cpp file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "game.hpp"


using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

Menu programRunning;
Zoo zooRunning;

Game::Game()
{
    srand(time(NULL));
    day = 1;
    penguinBuy = 0;
    tigerBuy = 0;
    turtleBuy = 0;
    choice = 0;
}
void Game::runGame()
{
    programRunning.displayMenu(); //display menu
    choice = programRunning.getMenuChoice();

    while (choice == 1)
    {
        if (day == 1) //first day
        {
            firstBuy(); //first buy of the game
            randomEvents();
            dailyBuy(); //daily animal buy time
            day++;
            if (zooRunning.checkBankBalance())
            {
                programRunning.displayMenu(); //show program when program ended
                choice = programRunning.getMenuChoice();
            }
            else //negative balance, game over
            {
                choice = 2;
                cout << "Bad news. You do not have any money left. Zoo went into bankruptcy." << endl;
            }
        }

        else //after first day
        {
            zooRunning.updateAge();
            zooRunning.payFoodCost(); //pay food cost at the start of the day
            zooRunning.printDailyReport((day - 1));
            randomEvents();
            dailyBuy(); //daily animal buy time
            day++;
            if (zooRunning.checkBankBalance()) //positive bank balance
            {
                programRunning.displayMenu(); //show program when program ended
                choice = programRunning.getMenuChoice();
            }
            else //negative balance, game over
            {
                choice = 2;
                cout << "Bad news. You do not have any money left. Zoo went into bankruptcy." << endl;
            }
        }
    }

    if (choice == 2) //quit simulation
    {
        zooRunning.deletePointers(); //deallocate arrays and delete pointers
        cout << "Game ended. Thank you for playing!" << endl;
    }
}
void Game::randomEvents()
{
    cout << "It is the time of the day! Where randomness looms and an unexpected event will occur." << endl;
    int result = (rand() % 4) + 1; //to obtain a pseudo-random number between 1 and  4 for each event
    //source used: http://www.cplusplus.com/forum/beginner/22286/

    if (result == 1)
    {
        randomEvent1();
    }
    /*
    A sickness occurs to an animal in the zoo:
    Pick an animal at random that will die
    Remove one animal of that type from the exhibit. (dynamic array in the zoo)
    */

    if (result == 2)
    {
        randomEvent2();
    }
    /*
    A boom in zoo attendance occurs:
    Generate a random bonus for the day, 250-500 dollars for each tiger in the zoo
    Add the bonus payoff for each tiger to the total payoff of the day as a reward
    */
    if (result == 3)
    {
        randomEvent3();
    }

    /*
A baby animal is born:
Pick an animal at random to have a baby
Check if there is an animal old enough to be a parent (age >= 3), add babies to the zoo depending on the “number of babies” specific to the type of animal. If no animal is old enough of the randomly selected type, pick another type of animal. Baby animals start at age 0.  For simplicity, you don’t need to consider the gender of the adult animals in order to have babies. One adult animal is good enough to have babies.
Note: If no animals are able to give birth to baby animals in the zoo, your program needs to be able to recognize this and recover.
*/
    if (result == 4)
    {
        randomEvent4();
    }
}

void Game::firstBuy()
{
    if ((programRunning.getCountPlay()) == 1) //run only for the first day purchase
    {
        //reset counter
        penguinBuy = 0;
        tigerBuy = 0;
        turtleBuy = 0;

        penguinBuy = programRunning.prompt("number of penguins you would like to buy", 1, 2);
        zooRunning.updateAnimalCount(1, penguinBuy);
        zooRunning.createAnimal(1, penguinBuy, 0);
        for (int i = 0; i < penguinBuy; i++)
        {
            int bill = zooRunning.costPenguin * -1;
            zooRunning.updateBankBalance(bill);
        }

        tigerBuy = programRunning.prompt("number of tigers you would like to buy", 1, 2);
        zooRunning.updateAnimalCount(2, tigerBuy);
        zooRunning.createAnimal(2, tigerBuy, 0);
        for (int i = 0; i < tigerBuy; i++)
        {
            int bill = zooRunning.costTiger * -1;
            zooRunning.updateBankBalance(bill);
        }

        turtleBuy = programRunning.prompt("number of turtles you would like to buy", 1, 2);
        zooRunning.updateAnimalCount(3, turtleBuy);
        zooRunning.createAnimal(3, turtleBuy, 0);
        for (int i = 0; i < turtleBuy; i++)
        {
            int bill = zooRunning.costTurtle * -1;
            zooRunning.updateBankBalance(bill);
        }
    }
}

void Game::dailyBuy()
{
    //reset counter
    penguinBuy = 0;
    tigerBuy = 0;
    turtleBuy = 0;

    int animalChoice = programRunning.promptChoice("which type of animal you would like to buy", "penguin", "tiger", "turtle", "none");

    if (animalChoice == 1) // buy a penguin
    {
        zooRunning.resizeArray(1, 1);
        zooRunning.updateAnimalCount(1, 1); // (animalType, number)
        int bill = zooRunning.costPenguin * -1;
        zooRunning.updateBankBalance(bill);
    }

    if (animalChoice == 2) //buy a tiger
    {
        zooRunning.resizeArray(1, 2);
        zooRunning.updateAnimalCount(2, 1); // (animalType, number)
        int bill = zooRunning.costTiger * -1;
        zooRunning.updateBankBalance(bill);
    }

    if (animalChoice == 3) //buy a turtle
    {
        zooRunning.resizeArray(1, 3);
        zooRunning.updateAnimalCount(3, 1); // (animalType, number)
        int bill = zooRunning.costTurtle * -1;
        zooRunning.updateBankBalance(-zooRunning.costTurtle);
    }

    if (animalChoice == 4) // no purchase made
    {
        cout << "No purchase made. Day " << day << " has ended." << endl;
    }
}

void Game::randomEvent1() //animal dying
{

    int penguinCount = zooRunning.getAnimalCount(1);
    int tigerCount = zooRunning.getAnimalCount(2);
    int turtleCount = zooRunning.getAnimalCount(3);
    int totalAnimal = 3;
    if (penguinCount == 0)
    {
        totalAnimal -= 1;
    }

    if (tigerCount == 0)
    {
        totalAnimal -= 1;
    }

    if (turtleCount == 0)
    {
        totalAnimal -= 1;
    }

    if (totalAnimal == 0) //no tiger (choose either random event 2, 3 or 4)
    {
        int result = (rand() % 3) + 1; //to obtain a pseudo-random number between 1 and 3

        if (result == 1)
        {
            randomEvent2();
        }

        if (result == 2)
        {
            randomEvent3();
        }

        if (result == 3)
        {
            randomEvent4();
        }
    }

    else
    {
        int sickResult = (rand() % totalAnimal) + 1; //to obtain a pseudo-random number between 1 and 3 to pick an animal

        ifstream inputFile("random1.txt"); //declare input file to use as function parameter
        string text;
        getline(inputFile, text);
        cout << text << endl;
        inputFile.close(); //close input file when completes reading

        //cout << "An unfortunate sickness occurred in the zoo and claim the life of an animal. " << endl;

        if (totalAnimal == 1) //only one animaltype has animal
        {
            if (penguinCount != 0)
            {
                cout << "The unfortunate animal is a penguin. Rest in peace Happy Feet." << endl;
                zooRunning.removeSickAnimal(1);
                zooRunning.updateAnimalCount(1, -1);
            }
            if (tigerCount != 0)
            {
                cout << "The unfortunate animal is a tiger. Tigger lost one of his closest family member. Thoughts are with him. " << endl;
                zooRunning.removeSickAnimal(2);
                zooRunning.updateAnimalCount(2, -1);
            }
            if (turtleCount != 0)
            {
                cout << "The unfortunate animal is a turtle. Squirtle would need to pull out from the next Tournament to be with family. " << endl;
                zooRunning.removeSickAnimal(3);
                zooRunning.updateAnimalCount(3, -1);
            }
        }

        if (totalAnimal == 2) //only two animaltype has animals
        {
            if (penguinCount == 0) //no penguin, choose from tiger or turtle
            {

                if (sickResult == 1) // tiger died
                {
                    cout << "The unfortunate animal is a tiger. Tigger lost one of his closest family member. Thoughts are with him. " << endl;
                    zooRunning.removeSickAnimal(2);
                    zooRunning.updateAnimalCount(2, -1);
                }
                if (sickResult == 2) //turtle died
                {
                    cout << "The unfortunate animal is a turtle. Squirtle would need to pull out from the next Tournament to be with family. " << endl;
                    zooRunning.removeSickAnimal(3);
                    zooRunning.updateAnimalCount(3, -1);
                }
            }
            if (tigerCount == 0) //no tiger, choose from penguin or turtle
            {
                if (sickResult == 1) // penguin died
                {
                    cout << "The unfortunate animal is a penguin. Rest in peace Happy Feet." << endl;
                    zooRunning.removeSickAnimal(1);
                    zooRunning.updateAnimalCount(1, -1);
                }

                if (sickResult == 2) //turtle died
                {
                    cout << "The unfortunate animal is a turtle. Squirtle would need to pull out from the next Tournament to be with family. " << endl;
                    zooRunning.removeSickAnimal(3);
                    zooRunning.updateAnimalCount(3, -1);
                }
            }
            if (turtleCount == 0) //no turtle, choose from penguin or tiger
            {
                if (sickResult == 1) // penguin died
                {
                    cout << "The unfortunate animal is a penguin. Rest in peace Happy Feet." << endl;
                    zooRunning.removeSickAnimal(1);
                    zooRunning.updateAnimalCount(1, -1);
                }

                if (sickResult == 2) // tiger died
                {
                    cout << "The unfortunate animal is a tiger. Tigger lost one of his closest family member. Thoughts are with him. " << endl;
                    zooRunning.removeSickAnimal(2);
                    zooRunning.updateAnimalCount(2, -1);
                }
            }
        }

        if (totalAnimal == 3) //all three animals available to pick from
        {
            if (sickResult == 1) // penguin died
            {
                cout << "The unfortunate animal is a penguin. Rest in peace Happy Feet." << endl;
                zooRunning.removeSickAnimal(1);
                zooRunning.updateAnimalCount(1, -1);
            }

            if (sickResult == 2) // tiger died
            {
                cout << "The unfortunate animal is a tiger. Tigger lost one of his closest family member. Thoughts are with him. " << endl;
                zooRunning.removeSickAnimal(2);
                zooRunning.updateAnimalCount(2, -1);
            }

            if (sickResult == 3) //turtle died
            {
                cout << "The unfortunate animal is a turtle. Squirtle would need to pull out from the next Tournament to be with family. " << endl;
                zooRunning.removeSickAnimal(3);
                zooRunning.updateAnimalCount(3, -1);
            }
        }
    }
}

void Game::randomEvent2()
{
    int tigerCount = 0;
    tigerCount = zooRunning.getAnimalCount(2);

    if (tigerCount == 0) //no tiger (choose either random event 1, 3 or 4)
    {
        int result = (rand() % 3) + 1; //to obtain a pseudo-random number between 1 and 3

        if (result == 1)
        {
            randomEvent1();
        }

        if (result == 2)
        {
            randomEvent3();
        }

        if (result == 3)
        {
            randomEvent4();
        }
    }

    else
    {
        ifstream inputFile("random2.txt"); //declare input file to use as function parameter
        string text;
        getline(inputFile, text);
        cout << text << endl;
        inputFile.close(); //close input file when completes reading
        //cout << "Congratulations! There is a boom in zoo attendance!" << endl;
        int currentBonusPayoff = zooRunning.bonusPayoff();
        cout << "You have earned a bonus payoff of $" << currentBonusPayoff << " for the day!" << endl;
        zooRunning.updateBankBalance(currentBonusPayoff);
    }
}

void Game::randomEvent3() //baby boom
{
    int penguinCount = 0;
    int tigerCount = 0;
    int turtleCount = 0;
    bool penguinAdult = 0;
    bool tigerAdult = 0;
    bool turtleAdult = 0;
    int totalAnimal = 3;

    //first detect how many animalTypes have animals in the array
    penguinCount = zooRunning.getAnimalCount(1);
    tigerCount = zooRunning.getAnimalCount(2);
    turtleCount = zooRunning.getAnimalCount(3);

    // second detect the age of the oldest animal in each animal type if there is an adult
    //(use checkAdult function to run through array to return true if there is an adult)
    if (penguinCount != 0)
    {
        penguinAdult = zooRunning.checkAdult(1);
    }

    if (tigerCount != 0)
    {
        tigerAdult = zooRunning.checkAdult(2);
    }

    if (turtleCount != 0)
    {
        turtleAdult = zooRunning.checkAdult(3);
    }

    if (!penguinAdult)
    {
        totalAnimal -= 1;
    }

    if (!tigerAdult)
    {
        totalAnimal -= 1;
    }

    if (!turtleAdult)

    {
        totalAnimal -= 1;
    }

    if (totalAnimal == 0) //no adults animal (choose either random event 1, 2 or 4)
    {
        int result = (rand() % 3) + 1; //to obtain a pseudo-random number between 1 and 3

        if (result == 1)
        {
            randomEvent1();
        }

        if (result == 2)
        {
            randomEvent2();
        }

        if (result == 3)
        {
            randomEvent4();
        }
    }

    else
    {
        ifstream inputFile("random3.txt"); //declare input file to use as function parameter
        string text;
        getline(inputFile, text);
        cout << text << endl;
        inputFile.close(); //close input file when completes reading

        int bornResult = (rand() % totalAnimal) + 1; //to obtain a pseudo-random number between 1 and 3 to pick an animal

        //cout << "An unfortunate sickness occurred in the zoo and claim the life of an animal. " << endl;

        if (totalAnimal == 1) //only one animaltype has animal
        {
            if (penguinAdult) //there is a penguin adult
            {
                cout << "Love is in the air. Mama penguin gave birth to 5 healthy penguin and is currently looking for baby name suggestions!" << endl;
                zooRunning.updateAnimalCount(1, 5); //update count to 5 babies (animal type, number)
                zooRunning.resizeArray(2, 1);       //check capacity to see if array needs to be resized (event, animal type)
                zooRunning.createAnimal(1, 5, 1);   //create objects (type, number of babies, born is 1)
            }
            if (tigerAdult) //there is a tiger adult
            {
                cout << "Love is in the air. Mama tiger gave birth to a healthy cub and is currently looking for baby name suggestions!" << endl;
                zooRunning.updateAnimalCount(2, 1); //update count for 1 baby (animal type, number)
                zooRunning.resizeArray(2, 2);       //check capacity to see if array needs to be resized (event, animal type)
                zooRunning.createAnimal(2, 1, 1);   //create objects (type, number of babies, born is 1)
            }
            if (turtleAdult) //there is a turtle adult
            {
                cout << "Love is in the air. Mrs. Squirtle gave birth to whooping 10 baby turtles and is currently looking for a Pokemon Gym to enrol them in!" << endl;
                zooRunning.updateAnimalCount(3, 10); //update count for 10 babies (animal type, number)
                zooRunning.resizeArray(2, 3);        //check capacity to see if array needs to be resized (event, animal type)
                zooRunning.createAnimal(3, 10, 1);   //create objects (type, number of babies, born is 1)
            }
        }

        if (totalAnimal == 2) //only two animaltype has animals
        {
            if ((!penguinAdult) && (tigerAdult) && (turtleAdult)) //no adult penguin, choose from tiger or turtle
            {

                if (bornResult == 1) // tiger gave birth
                {
                    cout << "Love is in the air. Mama tiger gave birth to a healthy cub and is currently looking for baby name suggestions!" << endl;
                    zooRunning.updateAnimalCount(2, 1); //update count for 1 baby (animal type, number)
                    zooRunning.resizeArray(2, 2);       //check capacity to see if array needs to be resized (event, animal type)
                    zooRunning.createAnimal(2, 1, 1);   //create objects (type, number of babies, born is 1)
                }
                if (bornResult == 2) //turtle gave birth
                {
                    cout << "Love is in the air. Mrs. Squirtle gave birth to whooping 10 baby turtles and is currently looking for a Pokemon Gym to enrol them in!" << endl;
                    zooRunning.updateAnimalCount(3, 10); //update count for 1 baby (animal type, number)
                    zooRunning.resizeArray(2, 3);        //check capacity to see if array needs to be resized (event, animal type)
                    zooRunning.createAnimal(3, 10, 1);   //create objects (type, number of babies, born is 1)
                }
            }
            if ((penguinAdult) && (!tigerAdult) && (turtleAdult)) //no adult tiger, choose from penguin or turtle
            {
                if (bornResult == 1) // penguin gave birth
                {
                    cout << "Love is in the air. Mama penguin gave birth to 5 healthy penguin and is currently looking for baby name suggestions!" << endl;
                    zooRunning.updateAnimalCount(1, 5); //update count for 5 babies (animal type, number)
                    zooRunning.resizeArray(2, 1);       //check capacity to see if array needs to be resized (event, animal type)
                    zooRunning.createAnimal(1, 5, 1);   //create objects (type, number of babies, born is 1)
                }

                if (bornResult == 2) //turtle gave birth
                {
                    cout << "Love is in the air. Mrs. Squirtle gave birth to whooping 10 baby turtles and is currently looking for a Pokemon Gym to enrol them in!" << endl;
                    zooRunning.updateAnimalCount(3, 10); //update count for 10 babies (animal type, number)
                    zooRunning.resizeArray(2, 3);        //check capacity to see if array needs to be resized (event, animal type)
                    zooRunning.createAnimal(3, 10, 1);   //create objects (type, number of babies, born is 1)
                }
            }
            if ((penguinAdult) && (tigerAdult) && (!turtleAdult)) //no adult turtle, choose from penguin or tiger
            {
                if (bornResult == 1) // penguin gave birth
                {
                    cout << "Love is in the air. Mama penguin gave birth to 5 healthy penguin and is currently looking for baby name suggestions!" << endl;
                    zooRunning.updateAnimalCount(1, 5); //update count to 5 babies (animal type, number)
                    zooRunning.resizeArray(2, 1);       //check capacity to see if array needs to be resized (event, animal type)
                    zooRunning.createAnimal(1, 5, 1);   //create objects (type, number of babies, born is 1)
                }

                if (bornResult == 2) // tiger gave birth
                {
                    cout << "Love is in the air. Mama tiger gave birth to a healthy cub and is currently looking for baby name suggestions!" << endl;
                    zooRunning.updateAnimalCount(2, 1); //update count to 1 babies (animal type, number)
                    zooRunning.resizeArray(2, 2);       //check capacity to see if array needs to be resized (event, animal type)
                    zooRunning.createAnimal(2, 1, 1);   //create objects (type, number of babies, born is 1)
                }
            }
        }

        if (totalAnimal == 3) //all three animals available to pick from
        {
            if (bornResult == 1) // penguin gave birth
            {
                cout << "Love is in the air. Mama penguin gave birth to 5 healthy penguin and is currently looking for baby name suggestions!" << endl;
                zooRunning.updateAnimalCount(1, 5); //update count to 5 babies (animal type, number)
                zooRunning.resizeArray(2, 1);       //check capacity to see if array needs to be resized (event, animal type)
                zooRunning.createAnimal(1, 5, 1);   //create objects (type, number of babies, born is 1)
            }

            if (bornResult == 2) // tiger gave birth
            {
                cout << "Love is in the air. Mama tiger gave birth to a healthy cub and is currently looking for baby name suggestions!" << endl;
                zooRunning.updateAnimalCount(2, 1); //update count to 1 baby (animal type, number)
                zooRunning.resizeArray(2, 2);       //check capacity to see if array needs to be resized (event, animal type)
                zooRunning.createAnimal(2, 1, 1);   //create objects (type, number of babies, born is 1)
            }

            if (bornResult == 3) //turtle gave birth
            {
                cout << "Love is in the air. Mrs. Squirtle gave birth to whooping 10 baby turtles and is currently looking for a Pokemon Gym to enrol them in!" << endl;
                zooRunning.updateAnimalCount(3, 10); //update count to 10 babies (animal type, number)
                zooRunning.resizeArray(2, 3);        //check capacity to see if array needs to be resized (event, animal type)
                zooRunning.createAnimal(3, 10, 1);   //create objects (type, number of babies, born is 1)
            }
        }
    }
}

void Game::randomEvent4()
{
    ifstream inputFile("random4.txt"); //declare input file to use as function parameter
    string text;
    getline(inputFile, text);
    cout << text << endl;
    inputFile.close(); //close input file when completes reading
    //cout << "As random as it is. Nothingness is part of the random equation and today nothing eventful happened." << endl;
}