#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(NULL));
    int randomNumber = rand() % 10 + 1;
    int guess;
    int score = 0;

    std::cout << "                                 Welcome to the Number Guessing Game!                         " << std::endl;
    std::cout<<std::endl;
    std::cout << "************************************************************************************************"<<std::endl;
    std::cout << "Rules: "<<std::endl;
	std::cout << "i)Each Correct Guess Will Reward you +10 points."<<std::endl;
	std::cout << "ii)Each wrong will cut out your -5 points ."<<std::endl;
	std::cout<<std::endl;
	std::cout << "Let's see If you can score positive marks ! "<<std::endl;
	std::cout<<std::endl;
	std::cout << "                                      BEST OF LUCK!                                             "<<std::endl;
	std::cout<<std::endl;
    std::cout << "************************************************************************************************"<<std::endl;
    do {
        std::cout << "Guess a number between 1 and 10: ";
        std::cin >> guess;
		
        if (guess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
            score -= 5;
            std::cout << "Your score: " << score << std::endl;
        } else if (guess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
            score -= 5;
            std::cout << "Your score: " << score << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number." << std::endl;
            score += 10;
        }

    } while (guess != randomNumber);
	
	if(score<0)
	{
		std::cout << "Sorry !\nYou lost the Game! "  << std::endl;
		std::cout << "Your final score: " << score << std::endl;
	}
	else if(score >0)
	{
		std::cout << "Congratulations !\nYou Won the Game! " << std::endl;
		std::cout << "Your final score: " << score << std::endl;
	}
	else
	{
		std::cout << "Congratulations !\nYou Didn't' Lost the Game But Still you Didn't Won The Game'! " << std::endl;
		std::cout << "Your final score: " << score << std::endl;
	}
//    std::cout << "Your final score: " << score << std::endl;

    return 0;
}