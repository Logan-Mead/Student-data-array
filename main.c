/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Logan Mead
 * ECE 141-Spring 2020
 * Created on March 29, 2020, 1:55 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[64];
    int age;
    float gpa;
} Student;

// Initializes a student Structure
Student createStudent(char name[], int age, float gpa){
    Student s;
    strcpy(s.name, name);
    s.age = age;
    s.gpa = gpa;
    return s;
}

// Displays the contents of a student structure to the screen
void displayStudent(Student s){
    printf("%s %d %.1f\n", s.name, s.age, s.gpa);
}

// Displays all the student structures in an array to the screen
void displayStudentArray(Student array[], int size){
    for(int i=0;i<size;i++){
        displayStudent(array[i]);
    }
}

//Appends a student (s) to the end of an array.  Size is increased by 1
Student* append(Student* array, int* size, Student s){
    array = realloc(array, (*size+1)*sizeof(Student));
    if (array == NULL){
        printf("ERROR: In Append Function!\n");
        return NULL;
    }
    array[*size] = s;
    *size = *size + 1;
    return array;
}

//Inserts a student (s) to the brought in index in the array. Size is increased by 1
Student* insert(Student* array, int* size, int index, Student s){
    array = realloc(array, (*size+1)*sizeof(Student));
    *size = *size +1;
    
    if(array == NULL){                                                           //checks to see if array is NULL and prints to screen an ERROR in function
        printf("ERROR: In Insert Function!\n");
        return NULL;
    }
    
    for(int i = *size; i >= index; i--){                                          //moves all elements in array to the right from the index
        array[i] = array[i - 1];
    }
    array[index] = s;                                                             //inserts student at index
        
    return array;                                                                
}


int main() {
    
    //runs createStudent if all student info
    Student adam = createStudent("adam", 20, 3.4);
    Student beth = createStudent("beth", 21, 3.7);
    Student chris = createStudent("chris", 19, 2.9);
    
    Student* array = NULL;
    int size = 0;
    
    array = append(array, &size, adam);
    array = append(array, &size, beth);
    array = append(array, &size, chris);
    
    displayStudentArray(array, size);                                            //runs displayArray with array and displays all current students with info
    
    printf("--------------------\n");
    printf("Testing Append Function\n");                                            
    Student dave = createStudent("dave", 22, 3.2);
    array = append(array, &size, dave);
    displayStudentArray(array, size);
    printf("--------------------\n");
    
    printf("Testing Insert Function\n");                                         //tells the user the Insert Function is now testing
    Student erin = createStudent("erin", 21, 3.5);                               //create a student struct named erin with the age 21 and a gpa of 3.5
    array = insert(array, &size, 2, erin);                                       //runs Insert Function with array the address of size 2 as an index and the struct erin
    displayStudentArray(array, size);                                            //display function that displays all the students info
    printf("--------------------\n");
    
    free(array);                                                                 //frees the array in memory in order to prevent memory leaks
    
    return (EXIT_SUCCESS);
}