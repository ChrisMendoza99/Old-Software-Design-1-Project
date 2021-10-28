/*made by C.A.M*/
//Name: Christopher Mendoza
//Class: EE-2372 "Software Design"
#include <stdio.h> //Standard access libraty for the scanf and printf
/*This array of struct will contain the information for the Exam grade, overall Average, Age of the Student, and First and Last Name*/
struct info 
{
  char FirstName[25]; //An Array is used to store the first names of student
  char LastName[25];  //An Array is used to store the last names
  int Age;            //This data type stores the Age of the Student 
  double Exam;        //Takes the exam grades per student and saves them, and is sent to the fucntions
  double Average;     //Storing the average of the grades of each students, and is to the functions
}extract[250];        //Using one varaible keeps it all consistent without having to resort to multiple varaibles

/*The main only ask the user for the values, everything else is outside of main, in terms of info and calculations, and prints out the the values*/
//while is looping, try a do while?
int main() 
{
    /*These are the condition variables for the loops*/ 
    int numStudents;         //The amount of students being grades
    double numGrades;   //How many grades you wanna read per student
    int i, j, k, h, f, t;     //Counter variables for the For Loops in Main
    /*These declared varaibles are for the functions*/                          
    double avg;            //For the function GetAverage 
    int min;               //For the functions GetMin
    int max;               //For the function GetMax 
    int highest;           //For the function GetHighestGrade 
    int lowest;            //For the function GetLowestGrade
    int stlow;             //stlow is the index equal to the students first and last name n regrads of the lowest grade
    int sthigh;            //sthigh is the index equal to the students first and last name in regrads of the highest grade
    double *ptr;           //The pointer for adding points to any students name
    int choice;            //Int choice is for the switch statements
    int get;               //When the user enters the value of get provided, they call upon the index
    double addpoints;      //addpoints is the extra values added to whatever student 
    /*The prototype functions are placed here to declare them allowing Main to see the Functions*/ 
    double GetAverage(struct info s[], int n, int k);  
    double GetMin(struct info s[], int u);
    double GetMax(struct info s[], int p);
    double GetHighestGrade(struct info s[], int y, int w);
    double GetLowestGrade(struct info s[], int k, int w);
    do //The purpose of this do while loop is to keep it whithin the specified bounds, in between 1 and 25
    {
       printf("How many students will you grade (1-25)? ");
       scanf("%i", &numStudents);
       if(numStudents < 1) //If the value is below 1, then outout an invlid error
       {
           printf("Input not valid\n"); 
       }
       else if(numStudents > 25)//If the value is above 25, then outout an invlid error
       {
           printf("Input not valid\n");
       }
       else //In this else ouput, is where the user inputs their info
       {
           do //This do while loop, is to keep it whithin the specified bounds, in between 1 and 10
           {
               printf("How many grades will you read per student (1-10)?"); //Asking the user to enter how many grades you want to enter
               scanf("%lf", &numGrades);
               if(numGrades < 1)         //If the value is below 1, then it is an error
               {
                   printf("Input not valid\n"); 
               }
               else if(numGrades > 10)   //If the values is above 10, then it is an error
               {
                   printf("Input not valid\n"); 
               }
               else
               {
                 /*This is a Nested For Loop to ask the user the names, grades, and age of the student*/
                    int storeExam = 0;
                    for(i = 0; i < numStudents; ++i)
                    {
                        printf("\nEnter First Name for student %d: ", i + 1); //Ask the user the first name
                        scanf("%s", extract[i].FirstName );
                        printf("Enter Last Name for student %d: ", i + 1);  //Ask the user the last name
                        scanf("%s", extract[i].LastName);
                        printf("Enter age for student %d: ", i + 1);        //Ask for the age of the student
                        scanf("%i", &extract[i].Age);
                        for(j = 0; j < numGrades; ++j)
                        {
                            printf("Enter grade %d of student %d: ", j+1, i+1);//Ask for the grade of the student, dependent on how many the user ask to grade each
                            scanf("%lf", &extract[storeExam].Exam); 

                            if(storeExam < numStudents*numGrades)
                            {
                               storeExam = storeExam + 1; 
                            }   
                        }    
                        avg = GetAverage(extract, numGrades, i);  //This sends the values to the GetAverage fucntion
                        extract[i].Average = avg;                 //Sets the struct memeber Average equal to the avg
                        lowest = GetLowestGrade(extract, numStudents, numGrades); //Sends the exam values to the lowestgrade function
                        stlow = (GetLowestGrade(extract, numStudents, numGrades))/numGrades;  //This is essentially the index position of the students name of whom got lowest exam grade
                        highest = GetHighestGrade(extract, numStudents, numGrades);           //Sends the exam to the highestgrade function
                        sthigh = (GetHighestGrade(extract, numStudents, numGrades))/numGrades;//This is essentially the index position of the student name of whome got highest eaxm grade
                    }
                    /*Under here is the option for whether the user wants to add point to one of the students grades*/
                    do //A do while is placed to allow the program run and check for conditions to make sure the switch statement are in order
                    {  
                        for(k = 0; k < numStudents; ++k) //This for loop displays the average of each student            
                        { //This prints out the previously saved values before making a choice                                                  
                            printf("\n%s %s has a grade average of: %0.2lf", extract[k].FirstName, extract[k].LastName, extract[k].Average);
                            min = GetMin(extract, numStudents); //Here the values are sent back again to confirm the what is minimal average
                            max = GetMax(extract, numStudents); //and what is the maximum average, even after changing the values it gets sent
                        }                                       //to see what the new max and min values are and are displayed.
                        printf("\n\nWould you like to add extra points to any of the students(1=YES 2=NO)? "); //Here it ask whether or not the user wants to change the students overall average
                        scanf("%i", &choice);//User inputs a value of either 1 or 2, anything else would give "Incorrenct selection" until the condition is meet 
                        switch(choice)
                        {
                        case 1:                               //Case 1 deals with the actual modification of the students average
                            for(f = 0; f < numStudents; ++f)  //The for loop prints out the list of students the user wants to chang                   
                            {                                                  
                                printf("%i=> %s %s has a grade average of: %0.2lf\n", f + 1 ,extract[f].FirstName, extract[f].LastName, extract[f].Average);
                            }
                            printf("\nWhich Student would you like to modify?(Enter the number to the left of the student's name) "); 
                            scanf("%i", &get);                //Here the user enters the number associated with the student
                            get = get - 1;                    //However, the user needs to enter the index of the value, so it is subtracted by one, since an array starts, and always start at 0
                            ptr = &extract[get].Average;      //And here the pointer is equal to the value of the extract[get].Average of whatever number the user wants 
                            printf("How many extra points would you like to add to this student? ");
                            scanf("%lf", &addpoints);         //Here the user now can add how many points they want to add
                            *ptr = addpoints + *ptr;          //Here the value of the pointer is added by the addpoints, thus vhanging the value of the pointer 
                        break;                                //A break statement is used to stop it
                        case 2:             //In case 2, if the user enters 2, then the values wont change, and this will display the final resuslts 
                             
                            for(t = 0; t < numStudents; ++t) //This for loop displays either the changed or unchanged values the user entered     
                            {        
                                printf("\n%s %s has a grade average of: %0.2lf", extract[t].FirstName, extract[t].LastName, extract[t].Average);
                            }             
                            printf("\n\n%s %s has the highest average with: %0.2lf\n", extract[max].FirstName, extract[max].LastName ,extract[max].Average); //This displays the student with the maximum average
                            printf("%s %s has the lowest average with: %0.2lf\n\n", extract[min].FirstName, extract[min].LastName, extract[min].Average);    //This displays the student with the minimal average
                            printf("%s %s obtained the highest grade with: %0.2lf\n", extract[sthigh].FirstName ,extract[sthigh].LastName, extract[highest].Exam); //This displays the students the highest average 
                            printf("%s %s obtained the lowest grade with: %0.2lf\n", extract[stlow].FirstName ,extract[stlow].LastName, extract[lowest].Exam);     //This displays the studentt the lowest average
                        break;
                        default: printf("\nIncorrect selection!\n"); //If the user enters a number neither 1 or 2, it returns this print statment until the user selects 1 or 2
                        }
                    }while(choice != 2);     
               } 
           }while (numGrades < 1 || numGrades > 10); //A do while is used to execute the program first, before checking condtions
       } 
    }while(numStudents < 1 || numStudents > 25); //A do while is used to execute the program first, before checking condtions
     
    return 0; //Return status assuming everything was compiled correctly
}
/*Down below are the functions to which main per request to calculate the values it sends*/
double GetAverage(struct info s[], int n, int k)
{
    int i;         //For loop counter
    int j = 0;     //This initialize that value at 0
    float result;  //This variable will return the result of every average of each student 
    float sum = 0; //Sets the value at 0
    for(i = 0; i < n; i++)
    {
        j = (k*n)+i;//The k*n is to figure which grade number it is, the plus i to add the previous number to the j
        sum = sum + s[j].Exam; //This sets sum equal to the previous sum plus the new values
    }
    result = sum / n; //This takes all the values of the exams and divides the number of exams
    return result;
}
/*This function deals with taking lowest average of the student*/
double GetMin(struct info s[], int u)
{
    int i;                 //For Loop counter
    double min;            //Min returns the of minimal average of all the students
    double location = 0;   //This sets the value at 0, which corresponds to the index 
    min = s[0].Average;    //Sets the starting value of min with 0 index of the average, this value only get returned if the value is smaller than the next values in the array
    for(i = 0; i < u; i++) //u is the number of students, which corresponds with number of average grades in total
    {
        if(s[i].Average < min)  //It compares the values of the averages starting from 0
        {
            min = s[i].Average; //If the value is found to minimal, thus saving it
            location = i;       //This value saves the index of the students smallest value
        }
    }
    return location; //
}
/*This function deals with highest average of the student*/
double GetMax(struct info s[], int p)
{
    int i;                  //For Loop counter
    double max;             //Max returns the of minimal average of all the students
    double location = 0;    //This sets the value at 0, which corresponds to the index    
    max = s[0].Average;     //Sets the starting value of min with 0 index of the average, this value only get returned if the value is larger than the next values in the array
    for(i = 0; i < p; i++)  //p is the the number of students, which corresponds to the number of average grades in total
    {
        if(s[i].Average > max) //Like with the GetMin, it compares the values of averages starting from 0
        {
            max = s[i].Average;  //If the value is found to larger, thus saving it 
            location = i;        //This value saves the index of the students largest value
        }
    }
    return location;             //This returns the value of the index
}
/*This function deals with taking the lowest exam of the student*/
double GetLowestGrade(struct info s[], int k, int w)
{
    int i;           //The counter varaible for the For Loop
    double lowest;   //lowest is the starting point 
    double location = 0; //This sets the value at 0, which corresponds to the index 
    lowest = s[0].Exam;  //lowest is equal to the first member of the array value
    for(i = 0; i < k*w; i++) //k*w is the the number of students, which corresponds to the number of exams in total
    {
        if(s[i].Exam < lowest) //This compares all the exam grades and searches for the lowest
        {
            lowest = s[i].Exam; //If the value is found then
            location = i;      //location equal to the index of it
        }
    }
    return location;           //returns location as an index
}
/*This function deals with taking the highest exam of the student*/
double GetHighestGrade(struct info s[], int y, int w)
{
    int i;          //The counter varaible for the For Loop
    double highest; //lowest is the starting point
    double location = 0; //This sets the value at 0, which corresponds to the index
    highest = s[0].Exam; //highest is equal to the first member of the array value
    for(i = 0; i < y*w; i++)
    {
        if(s[i].Exam > highest)
        {
            highest = s[i].Exam; //If the value is found then
            location = i;        //location equal to the index of it  
        }
    }
    return location;           //returns location as an index
}