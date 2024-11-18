#include <iostream>
#include <string>
using namespace std;
//1
struct node{
	string word;
	node* next;
};
//2
string findMostFrequentWord(node* head) {
    node* current = head;
    string mostFrequentWord = "";
    int maxCount = 0;

    while (current != NULL) {
        if (current->count > maxCount) {
            maxCount = current->count;
            mostFrequentWord = current->word;
        }
        current = current->next;
    }

    return mostFrequentWord;
}
//4
int countWord(node* head) {
    node* current = head; 
    int count = 0;        

    while (current != NULL) { 
        count++;              
        current = current->next; 
    }

    return count; 
}
