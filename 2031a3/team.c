//
// EECS2031 team.c
//
// Program for maintaining a personal team.
//
//
// Uses a linked list to hold the team players.
//
// Author: Jay Cen 
// Student Info: 215145105


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

//**********************************************************************
// Linked List Definitions 
//  Define your linked list node and pointer types
//  here for use throughout the file.
//
//
//   ADD STATEMENT(S) HERE
struct Node {
	char * family_name;
	char * first_name;
	char position;
	int value;
	struct Node* next;
};


//**********************************************************************
// Linked List Function Declarations
//
// Functions that m
// return head;odify the linked list.
//   Declare your linked list functions here.
//   ADD STATEMENT(S) HERE

//INSERTION
struct Node* INSERT(struct Node *head, char *family_name, char *first_name, char position, int value);

//DELETION
struct Node* DELETE(struct Node *head, char *family_name);

//SEARCH_FamilyName 
struct Node* SEARCH_FAMILY_NAME(struct Node *head, char *family_name);

//SEARCH_WORTHLESS
int SEARCH_WORTHLESS(struct Node *head, int value);

//PRINT the LinkedList (in special order) 
void PRINT_LINKEDLIST(struct Node *head);

//PRINT the NODE
void PRINT_NODE(struct Node *node);

//PRINT message for NULL
void PRINT_NULL(char *family_name);

//Mapping function
int map(char position);

//**********************************************************************
// Support Function Declarations
//

void safegets (char s[], int arraySize);        // gets without buffer overflow
void familyNameDuplicate (char familyName[]);   // marker/tester friendly 
void familyNameFound (char familyName[]);       //   functions to print
void familyNameNotFound (char familyName[]);    //     messages to user
void familyNameDeleted (char familyName[]);
void printTeamEmpty (void);
void printTeamTitle(void);
void printNoPlayersWithLowerValue(int value);

//**********************************************************************
// Program-wide Constants
//

const int MAX_LENGTH = 1023;
const char NULL_CHAR = '\0';
const char NEWLINE = '\n';
const char GOALKEEPER = 'G';
const char DEFENDER = 'D';
const char MIDFIELDER = 'M';
const char STRIKER = 'S';


//**********************************************************************
// Main Program
//

int main (void)
{ 
    const char bannerString[]
        = "Personal Team Maintenance Program.\n\n";
    const char commandList[]
        = "Commands are I (insert), D (delete), S (search by name),\n"
	  " V (search by balue), P (print), Q (quit).\n";
    // Declare linked list head
    //   ADD STATEMENT(S) HERE TO DECLARE LINKED LIST HEAD.
    struct Node *head = NULL;
 
    // announce start of program
    printf("%s",bannerString);
    printf("%s",commandList);
    
    char response;
    char input[MAX_LENGTH+1];

    char *family_name;
    char *first_name;
    char position[2];
    int value[2];

    do
    {
        printf("\nCommand?: ");
        safegets(input,MAX_LENGTH+1);
        // Response is first char entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper(input[0]);

        if (response == 'I')
        {
            // Insert a player entry into the linked list.
            // Maintain the list in correct order (G, D, M, S).
            //   ADD STATEMENT(S) HERE

            // USE THE FOLLOWING PRINTF STATEMENTS WHEN PROMPTING FOR DATA:

	    //allocate memory for family name
	    family_name = (char *)malloc(sizeof(MAX_LENGTH+1));
	    printf("  family name: ");
	    safegets(family_name, MAX_LENGTH+1);
	    printf("%s\n", family_name);

	    //allocate memory for first name
	    first_name = (char *)malloc(sizeof(MAX_LENGTH+1));
            printf("  first name: ");
	    safegets(first_name, MAX_LENGTH+1);
	    printf("%s\n", first_name);
	    
            printf("  position: ");
	    scanf(" %c", &position);
	    printf("%c", position[0]);

	    printf(" value: ");
	    scanf("%d", &value);
	    printf("%d", value[0]);
	    
	    char end = getchar();
	    head = INSERT(head, family_name, first_name, position[0], value[0]);

	    //print the information of the inserted new nodes
	    PRINT_LINKEDLIST(head);

	    //deallocated memory
	    free(family_name);
	    free(first_name);
	    
        }
        else if (response == 'D')
        {
	     printf("\nEnter family name to delete for: ");
	     family_name =(char*)malloc(sizeof(MAX_LENGTH+1));
             safegets(family_name, MAX_LENGTH+1);

             //   ADD STATEMENT(S) HERE
	     struct Node *delete_node = DELETE(head, family_name);
	     
	     if(delete_node == NULL)
		     PRINT_NULL(family_name);
	     free(family_name);

        }
        else if (response == 'S')
        {
            // Search for a player by family name.
            printf("\nEnter family name to search for: ");
	    family_name = (char*)malloc(sizeof(MAX_LENGTH+1));
	    scanf("%s", family_name);
            //   ADD STATEMENT(S) HERE
	    struct Node* player = SEARCH_FAMILY_NAME(head,family_name);

	    if(player == NULL)
		    PRINT_NODE(player);

	    free(family_name);

        }
        else if (response == 'V')
        {
            // Search for players that are worth less than or equal a value.

            printf("\nEnter value: ");
	    scanf("%d", &value);
	    char end = getchar();

            //   ADD STATEMENT(S) HERE
	    int count = SEARCH_WORTHLESS(head, value[0]);

	    if(count == 0)
		    printNoPlayersWithLowerValue(value[0]);

        }
        else if (response == 'P')
        {
            // Print the team.
            //   ADD STATEMENT(S) HERE
	    PRINT_LINKEDLIST(head);

        }
        else if (response == 'Q')
        {
            ; // do nothing, we'll catch this case below
        }
        else 
        {
            // do this if no command matched ...
            printf("\nInvalid command.\n%s\n",commandList);
        }
    } while (response != 'Q');
  
    // Delete the whole linked list that hold the team.
    //   ADD STATEMENT(S) HERE
    

    // Print the linked list to confirm deletion.
    //   ADD STATEMENT(S) HERE
   // PRINT_LINKEDLIST(head);
    return 0;
}

//**********************************************************************
// Support Function Definitions

// Function to get a line of input without overflowing target char array.
void safegets (char s[], int arraySize)
{
    
    int i = 0, maxIndex = arraySize-1;
    char c;
    while (i < maxIndex && (c = getchar()) != NEWLINE)
    {
        s[i] = c;
        i = i + 1;
    }
    s[i] = NULL_CHAR;
}

// Function to call when user is trying to insert a family name 
// that is already in the book.
void familyNameDuplicate (char familyName[])
{
    printf("\nAn entry for <%s> is already in the team!\n"
           "New entry not entered.\n",familyName);
}

// Function to call when a player with this family name was found in the team.
void familyNameFound (char familyName[])
{
    printf("\nThe player with family name <%s> was found in the team.\n",
             familyName);
}

// Function to call when a player with this family name was not found in the team.
void familyNameNotFound (char familyName[])
{
    printf("\nThe player with family name <%s> is not in the team.\n",
             familyName);
	
}

// Function to call when a family name that is to be deleted
// was found in the team.
void familyNameDeleted (char familyName[])
{
    printf("\nDeleting player with family name <%s> from the team.\n",
             familyName);
}


// Function to call when printing an empty team.
void printTeamEmpty (void)
{
    printf("\nThe team is empty.\n");
}

// Function to call to print title when whole team being printed.
void printTeamTitle (void)
{
    printf("\nMy Team: \n");
}

// Function to call when no player in the team has lower or equal value to the given value
void printNoPlayersWithLowerValue(int value)
{
	printf("\nNo player(s) in the team is worth less than or equal to <%d>.\n", value);
}

//**********************************************************************
// Add your functions below this line.

//INSERTION
struct Node* INSERT(struct Node *head, char *family_name, char *first_name, char position , int value)
{	
	printf("INSERTION\n");
	//declare new node 
	struct Node *new_node; 
	new_node = malloc(sizeof(struct Node));

	
	//declare two pointers for current and next pointers
	struct Node *current;
	struct Node *prev;

	//allocate memory 
	new_node -> family_name = malloc(MAX_LENGTH+1);
	new_node -> first_name = malloc(MAX_LENGTH+1);

	//assigning values 
	strcpy(new_node -> family_name, family_name);
	//printf("%s", new_node -> family_name);	
	strcpy(new_node -> first_name, first_name);
	new_node -> position = position;
	new_node -> value = value;

	/*
	if(strcmp(new_node -> first_name, new_node -> family_name) == 0)
		printf("The two string are the same: \nfirst_name: %s, \n family_name: %s", first_name, family_name);
        /*
	//NotFound default to be true 
	int NotFound = 1;
	for(prev = NULL, current = head; current !=NULL; prev = current,  current  = current -> next)
	{


	} 
	*/

	prev = NULL;
	current = head;

	//loop invariant
	int compare = 0;

	//iteration over the linked list
	while(current != NULL && compare == 0)
	{
		//Note that the family_name, first_name and position together
		//distinct each node itself
		char *current_family_name = current -> family_name;
		char *current_first_name = current -> first_name;
		char current_position = current -> position;

		//compare family_name and first_name
		int compareF_N = strcmp(current_family_name, family_name);
		int compareFirst_N = strcmp(current_first_name, first_name);

		//compare position
		int positionAtGiven = map(position);
		int positionAtCurrent = map(current_position);
		int compareP = (positionAtGiven == positionAtCurrent);

		//find the next position
		struct Node* next_node = current -> next;
		int next_position = map(next_node -> position);

		int compareCN = (next_position == positionAtGiven);

		//------------------------------------------------------------
		//------------------------------------------------------------
		if(compareF_N != 0 && compareFirst_N && compareP != 0 && compareCN == 1)
			compare = 1;

		//INCREMENTATION
		prev = current;
		current = current -> next;

		//************************************************************
		//************************************************************
		
		if(compare == 0)
			break;
	}

	//Pointer Manipulation

	//----------------------------------------------------------------------
	//----------------------------------------------------------------------
	
	//the new_node will insert in the beginning of the list
	if(prev == NULL)
	{
		new_node -> next = head;
		head = new_node;
	}

	if(compare != 0)
	{
		prev -> next = new_node;
		new_node -> next = current;
	}

	if(compare == 0)
		familyNameDuplicate(family_name);
        //new_node -> next = head;
        //head = new_node;
	

	return head;
}
//DELETION
struct Node* DELETE(struct Node *head, char *family_name)
{
	struct Node *current, *prev;

	for(prev = NULL, current = head; current != NULL && strcmp(current -> family_name, family_name); prev = current, current = current -> next)

	//printf("Compare : %d", strcmp(current -> family_name, family_name));
	//node with family_name is not found
	if(current == NULL)
		return current;
	//node with family_name is found at the head
	if(prev == NULL)
		head = head -> next;
	else 
		prev -> next = current -> next;

	free(current);
	return head;
}

//SEARCH_FAMILY_NAME
struct Node* SEARCH_FAMILY_NAME(struct Node *head, char *family_name)
{
	struct Node *iterator;
	int isFound = 0;
	

	for(iterator = head; iterator != NULL && isFound == 0; iterator = iterator -> next)
	{
		int compare = strcmp(iterator -> family_name, family_name);

		if(compare == 0)
			isFound = 1;
	}

	if(isFound == 0)
		familyNameNotFound(family_name);
	return iterator;
}

//SEARCH_WORTHLESS
int SEARCH_WORTHLESS(struct Node *head, int value)
{
	struct Node *iterator;
	int count = 0;

	for(iterator = head; iterator != NULL; iterator = iterator -> next)
	{
		int i_value = iterator -> value;

		if(i_value <= value)
		{
			PRINT_NODE(iterator);
			count++;
		}
	}
	return count;
}

//PRINT the LinkedList in special order
void PRINT_LINKEDLIST(struct Node *head)
{
	
	printTeamTitle();
	struct Node *p; 

	for( p = head; p != NULL; p = p -> next)
	{
		PRINT_NODE(p);
	}
}

//PRINT the all the information about the NODE
void PRINT_NODE(struct Node *node)
{
	if(node == NULL)
		printTeamEmpty();
	else 
	{
		printf("%s\n", node -> family_name);
		printf("%s\n", node -> first_name);
		printf("%c\n", node -> position);
		printf("%d\n", node -> value);
		printf("\n");
	}
}

//PRINT the message for NULL
void PRINT_NULL(char *family_name)
{
	familyNameNotFound(family_name);
}

//Map Function
int map(char position)
{
	if(position == 'G'  || position == 'g')
		return 0;
	else if(position == 'D' || position == 'd')
		return 1;
	else if(position == 'M' || position == 'm')
		return 2;
	else if(position == 'S' || position == 's')
		return 3;
	else 
		return -1;
}
