/*CLASS*/ //this class will check if the user got a right letter or guessed the word correctly, and if not adds a body part to the hangman, and outputs what letters and word they've used so far
//private
    //create a private array that stores all the user's guess on letters and on the word
    //create a private variable that determines the win counter for the game
    //create a private varriable for storing the word that the player will guess
    //create a private variable for the loseCount to determine how many chances they have left for the round
//public
    //SetWord(array that will have the word)
      //will store the word the player will have to guess into a private variable
    //DetermineLetter(variable that has user guess)
      //will check if the letter or word matches the word that player is guessing that is stored in the private variable
      //if letter is right will show letters in the word
      //if guessed word correctly will tell user that they won
        //will add to the win counter private variable
      //if the letter or word guess is not correct then add to the lose counter
    //GetChances()
      //will return the amount of chances they've used and compare to how many chances they have left

/*END OF CLASS*/

/*MAIN*/
//create srand to create a random number using computer time
//declare array to store all the words from the input file
//declare string to input user's name
//declare string to input second user's name
//declare an array to store the word that would be guessed in the round
//declare variable to check index of the letter to guess the letter of the word
//create variable for the the chances the player get to guess letters
//create variable for chance the players guesses for two players
//create array that stores all the user's guesses in the round for the game
//create a variable to determine if its 1 player or 2 players
//declare a variable to determine the difficulty mode
//declare an array to check letters if the user guess the same letter or not
//declare a variable to determine number of rounds
//create array of objects for the 1st player hangman
//create array of object for the 2 player hangman

//declare file input (fin)
//declare file output(fout)

//open input file to get the list of food items that the player can play hangman
//open output file to get the results of the the game either for 1 player, or 2 players in HTML

//checks if 1 player

//create a for loop that would loop determining on how many rounds the user wanted

//every round the array storing a word will be store using a random number to get a random word from the array storing words
  //if easy will loop until the characters are 5 or less using a while loop
  //if normal will loop until the character is between 6 and 10 using a while loop
  //if hard will loop until the characters is greater than 11 using a while loop
//create a loop to change the characters to _ so that the player could get the word using a while loop
//call class function to store the word the player will be guessing 
//get user input to get a word guessed or a letter
//call class function to store user input
//call class function to check user letter guess or word guess of the word 
  //guess right hangman would stay the same or word guess would tell player they won round
  //if guess wrong it would add a body piece and if answer wrong when the whole body is their the player would lose the round
//will determine what words they guessed and what letters they used for hangman

//once the rounds are over the wins or lose will be outputed into a html file to see how many rounds they won

//Checks if 2 player hangman 
  //will work the same as 1 player hangman, there will be double the rounds selected to create turns between the two players
  //the output file will determine rounds won and see who won more rounds
  //the person who got the most wins, wins the whole 2 player game
  //Output file will compare user scores in an HTML file
  
//close the input file
//close the output file
/*END OF MAIN*/