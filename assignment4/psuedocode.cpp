//PSUEDOCODE FOR GRADING TEST

/*Class for grading test */

//Private:

//private variable to contain the points obtained by the user
//private variable to contain the test size (array size)
//private array to contain the wrong answers given
//private array to contain all user's answers
//private variable to keep the percantage gotten on the test

//Public:

//Sets test size for grading

//Sets user's answer in a private array (create a parameter array to obtain all answers user gave)

//Sets in the user's answer and determine if correct or not, will also give points based on answer(parameter array for answer key to grade the test)
  //If correct gives a point for the test question
    //give point for fill-ins if they give short name for right answer like (variable called var) or (random named rand())
    
  //If ommitted gives no points for the test question
  
  //If wrong takes away 0.25 of a point for the test question
    //Will store answer to for later output to show which answers were wrong
    
//Sets the percantage the user's got on the test
  //divides points earned by total points avaiable and multiples by 100 
  
//Gets the user's answers
  //returns all the user's answers
  
//Gets user's total points recieved for the test
  //returns the points the user recieves from the test
 
//Gets percentage user recieved on the test
  //returns test percentage
  
//Gets grade letter the user recieves on test
  //uses if statements 
  
//Gets all wrong answers (parameter to get all the values from the array)
  //returns all values the wrong answer array contains

/* End of class */

/* MAIN */

//create an array that contains all the answers to the test
//create an array to store all the answers the user gives
//create string variable to store first name
//create string variable to store last name
//declare an array of objects to store all the user tests

//declare the ifstream (fin)
//declare the ofstream (fout)
//open an output file to show the results of the test

//open the answer key file as an input file to store all the answers for the test
  //store answer key inside an array(using a for loop)
  
//close the answer key file

//declare a variable to store in next array object every time it loops(i)

//create a while loop to repeat itself until it reaches end of file

//store user's first name
//store user's last name 

//open the test file as a user file to get all the user answers
  //store user's answers inside an array (using a for loop)
  
//Set the user's answers inside the class object and store in a private variable(parameter will be the array storing all the user's answers)
//use class object to determine the score of the test(parameter will be the array that has the answers to the test)
//use class object to set the percentage the user will recieve on the test

/* file output */
//outputs all wrong answers and which question that answer was wrong on
//outputs the score recieved from the test out of total points avaiable
//outputs the percentage the user recieved on the test
//outputs the gradeletter user recieved on the test
/* end of file output */

//add 1 to the variable that has the next array object for next user

//end of while loop

//close user's answers input file
//close the output file for results

/*end of program */
