#include "../includes/ft_ls.h"

#include<stdlib.h> 
  
#include <stdio.h> 
#include <stdlib.h> 
  
// t_ls { 
//     int data; 
//     t_ls* next; 
// }; 
  
t_ls* SortedMerge(t_ls* a, t_ls* b); 
void FrontBackSplit(t_ls* source, t_ls** frontRef, t_ls** backRef); 
 
void FrontBackSplit(t_ls* source, t_ls** frontRef, t_ls** backRef) 
{ 
    t_ls* fast; 
    t_ls* slow; 
    slow = source; 
    fast = source->next; 
  
   
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 
void MergeSort(t_ls** headRef) 
{ 
    t_ls* head = *headRef; 
    t_ls* a; 
    t_ls* b; 
  
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 
    FrontBackSplit(head, &a, &b); 
    MergeSort(&a); 
    MergeSort(&b); 
    *headRef = SortedMerge(a, b); 
} 
t_ls* SortedMerge(t_ls* a, t_ls* b) 
{ 
    t_ls* result = NULL; 
  
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
    if (-ft_strcmp(a->name, b->name) > 0) {
        result = a;
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
}