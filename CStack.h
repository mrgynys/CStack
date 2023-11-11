#ifndef C_STACK
#define C_STACK
#include <stdio.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* arr_;
    int size_;
} Stack;

void StackClear(Stack*);
void StackPush(Stack*, const int);
int StackPull(Stack*);
bool eos(Stack*);

/*
int main() {
    
    Stack new_stack;
    
    for(int i = 0; i < 5; i++)
        StackPush(&new_stack, i+1);
    
    while(!eos(&new_stack))
        printf("%d\t", StackPull(&new_stack));
    
    StackClear(&new_stack);
    
    return 0;
}
*/

void StackClear(Stack* st) {
    if(st->size_ != 0) free(st->arr_);
}

void StackPush(Stack* st, const int n) {
    if(st->size_ == 0) {
        st->arr_ = (int*) calloc(1, sizeof(int));
        st->size_++;
    }
    else {
        int* temp_arr = (int*) calloc(st->size_, sizeof(int));
        for(int i = 0; i < st->size_; i++) temp_arr[i] = st->arr_[i];
        st->size_++;
        st->arr_ = (int*) realloc(st->arr_, st->size_ * sizeof(int));
        for(int i = 0; i < st->size_; i++) st->arr_[i] = temp_arr[i];
        free(temp_arr);
    }
    st->arr_[st->size_ - 1] = n;
}

int StackPull(Stack* st) {
    int temp_num;
    if(st->size_ == 0) {
        return -1;
    }
    else if(st->size_ == 1) {
        temp_num = st->arr_[0];
        st->size_ = 0;
        free(st->arr_);
    }
    else {
        temp_num = st->arr_[st->size_ - 1];
        st->size_--;
        int* temp_arr = (int*) calloc(st->size_, sizeof(int));
        for(int i = 0; i < st->size_; i++) temp_arr[i] = st->arr_[i];
        free(st->arr_);
        st->arr_ = (int*) calloc(st->size_, sizeof(int));
        for(int i = 0; i < st->size_; i++) st->arr_[i] = temp_arr[i];
        free(temp_arr);
    }
    return temp_num;
}

bool eos(Stack* st) {
    if(st->size_ == 0) return true;
    else return false;
}

#endif