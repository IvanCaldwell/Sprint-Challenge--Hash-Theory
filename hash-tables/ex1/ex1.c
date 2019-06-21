#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  /* YOUR CODE HERE */
  for (int i = 0; i < length; i++) {
    // Calculate the weight number needed to equal limit
    int difference = hash_table_retrieve(ht, limit - weights[i]);
    // Check if if key is in the hash table
    if (difference == -1) {
      // If key is not in the hash table, add it
      hash_table_insert(ht, weights[i], i);
    } else {
      // Found a solution - early return
      // Create an Answer struct and set their properties
      Answer *result = malloc(sizeof(Answer));
      result->index_1 = i;
      result->index_2 = difference;
      destroy_hash_table(ht);
      return result;
    }
  }
  // Didn't find a solution return NULL
  destroy_hash_table(ht);
  return NULL;
}

void print_answer(Answer *answer){
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
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
