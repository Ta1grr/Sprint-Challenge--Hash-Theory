#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  // YOUR CODE HERE
  // insert all weights into the hash table as the key, and weight's list index as the value
  for (int i = 0; i < length; i++){
    int complement = limit - weights[i];
    // check if the complement exist in the hash table
    int retrieved = hash_table_retrieve(ht, complement);
      if (retrieved != -1) {
        Answer *answer = malloc(sizeof(Answer));
        answer->index_1 = i;
        answer->index_2 = retrieved;
        destroy_hash_table(ht);
        return answer;
      }
      else {
        hash_table_insert(ht, weights[i], i);
      }
    // hash_table_insert(ht, weights, i);
  }
  // loop through the weight and check the difference and retrieve from the hash table
  // if return -1 then it doesn't exist, otherwise return the value
  // index 1 can be the weight
  // index 2 can be the difference from limit - weight.



  return NULL;
}

void print_answer(Answer *answers)
{
  if (answers != NULL) {
    printf("%d %d\n", answers->index_1, answers->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{

  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}

  return 0;
}
#endif
