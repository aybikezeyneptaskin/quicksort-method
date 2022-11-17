#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "books.h"
using namespace std;

void quicksort(Books array[], int low, int high);

int main(int argc, char*argv[]){ 
    int num=0;
    string lines;
    int linecount=0;
    char c;
    ifstream books1file;
    books1file.open("books.txt");
    Books* array;

    if (!books1file){
        cerr << "books.txt file could not be opened!";
        exit(1);
    }
    while(!books1file.eof()){
        //count num of lines to create array of size of lines
        getline(books1file, lines);
        linecount++;
    }
    array = new Books[linecount]; 
    books1file.close();
    ifstream booksfile;
    booksfile.open("books.txt");
    
    //get data that are separated by ","
    char separate = ',';
    float float_data;
    string data[12];
    getline(booksfile, lines); //first line 
    for(int i=0;i<linecount-2;i++){
        // bookId,title, authors, average_rating,isbn,isbn13,language_code,num_pages
        //ratings_count,test_reviews_count,publication_date,publisher
        getline(booksfile,lines);
        stringstream line(lines);

        for(int j=0;j<12;j++){
            getline(line,data[j],separate);  
        }
        array[i].bookId=data[0];
        array[i].title=data[1];  
        array[i].authors=data[2];   
        float_data = stof(data[3]);
        array[i].average_rating=float_data; 
        array[i].isbn=data[4];
        array[i].isbn13=data[5];
        array[i].language_code=data[6]; 
        array[i].num_pages=data[7];
        array[i].ratings_count=data[8];
        array[i].text_reviews_count=data[9];      
        array[i].publication_date=data[10]; 
        array[i].publisher=data[11];   
        getline(line, lines, '\n'); //go to next row and continue iterating   
    }

    booksfile.close();
    //calculate time needed for quicksort:
    clock_t time = clock();
    quicksort(array, 0 , linecount-1);
    time = clock() - time;
    
    
    //create new sorted file
    ofstream outfile("sorted_books.txt");
    if (!outfile){
        cerr << "sorted_books.txt file could not be opened!";
        exit(1);
    }    
    for(int i=0;i<linecount-1;i++){ 
        //outfile << array[i].bookId<<","<< array[i].title<<","<< array[i].authors<<",";
        //outfile << array[i].average_rating<<","<< array[i].isbn<<","<< array[i].isbn13<<","<<array[i].language_code<<","<< array[i].num_pages<<",";
        //outfile << array[i].ratings_count<<","<< array[i].text_reviews_count<<","<< array[i].publication_date<<","<< array[i].publisher<<"\n";
        outfile<< array[i].bookId<<","<<array[i].average_rating<<"\n"<<endl;
    }
    outfile.close();
    //time elapsed:
    float total_time = 1000*(float)time / CLOCKS_PER_SEC;
    cout<<"Time elapsed for quicksort is "<<total_time<<" miliseconds."<<endl;
    cout << "number of swaps: " << num_of_swaps << endl;
    cout << "number of partitions: " << num_of_partitions << endl;
    return 0;
}

