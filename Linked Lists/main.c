//
//  main.c
//  Linked Lists
//
//  Created by Josh Endter on 6/10/15.
//  Copyright (c) 2015 Josh Endter. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// Define structs
typedef struct LinkedListItem{
    int data;
    struct LinkedListItem *nextItem;
} LinkedListItem;

// Define functions
void printLinkedList (LinkedListItem *item);
LinkedListItem *findLinkedListItemWithData (LinkedListItem *item, int *data);
LinkedListItem *findLastLinkedListItem (LinkedListItem *item);
void insertAtEndOfLinkedList (LinkedListItem *firstItem, int *dataToInsert);
LinkedListItem *makeLinkedListItem(int *data);
void joinLinkedListItemToNextItem (LinkedListItem *initialItem, LinkedListItem *nextItem);
void deleteLinkedListItemsStartingWith (LinkedListItem **item);

int main(int argc, const char * argv[]) {
    
    
    // Part 1
//    LinkedListItem item0;
//    LinkedListItem item1;
//    LinkedListItem item2;
//    LinkedListItem item3;
//    LinkedListItem item4;
//    
//    item0.data = 4;
//    item1.data = 33;
//    item2.data = 26;
//    item3.data = 7;
//    item4.data = 40;
//    
//    item0.nextItem = &item1;
//    item1.nextItem = &item2;
//    item2.nextItem = &item3;
//    item3.nextItem = &item4;
//    item4.nextItem = NULL;
    
    // Part 5
    
    /*
    int dataToUse[] = {4, 33, 26, 7, 40};
    LinkedListItem *item0 = makeLinkedListItem(&dataToUse[0]);
    LinkedListItem *item1 = makeLinkedListItem(&dataToUse[1]);
    LinkedListItem *item2 = makeLinkedListItem(&dataToUse[2]);
    LinkedListItem *item3 = makeLinkedListItem(&dataToUse[3]);
    LinkedListItem *item4 = makeLinkedListItem(&dataToUse[4]);
    joinLinkedListItemToNextItem (item0, item1);
    joinLinkedListItemToNextItem (item1, item2);
    joinLinkedListItemToNextItem (item2, item3);
    joinLinkedListItemToNextItem (item3, item4);
    */
    
    int numOfLinkedListItems = 5;
    int dataToUse[] = {4, 33, 26, 7, 40};
    LinkedListItem *linkedListItems[numOfLinkedListItems];
    for (int counter = 0; counter < numOfLinkedListItems; counter++) {
        linkedListItems[counter] = makeLinkedListItem(&dataToUse[counter]);
        if (counter > 0) {
            linkedListItems[counter-1]->nextItem = linkedListItems[counter];
        }
    }
    
    
//    int dataToUse[] = {4, 33, 26, 7, 40};
//    int numOfDataValues = 5;
//    for (int counter = 0; counter < numOfDataValues; counter++) {
//        makeLinkedListItem(&dataToUse[counter]);
//    }
    
//    int dataToUse[] = {4, 33, 26, 7, 40};
//    int arraySize = 5; // Calculate this dynamically later
//    for (int counter = 0; counter < arraySize; counter++) {
//        makeLinkedListItem
//    }
    
    // Part 2
    printf("Part 1, 2, 5: \n");
    printLinkedList(linkedListItems[0]);
    printf("\n\n");
    
    // Part 3
    printf("Part 3: \n");
    int dataToFind = 26;
    LinkedListItem *foundItem = findLinkedListItemWithData (linkedListItems[0], &dataToFind);
    if (foundItem) {
        printf("Found item data: %d", foundItem->data);
    } else {
        printf("Item not found.");
    }
    printf("\n\n");
    
    // Part 4
    printf("Part 4: \n");
    int dataToAdd = 45;
    insertAtEndOfLinkedList(linkedListItems[0], &dataToAdd);
    printf("Added data %d \n", dataToAdd);
    printf("The new linked list is: ");
    printLinkedList(linkedListItems[0]);
    printf("\n\n");
    
    // Part 7
    printf("Part 7: \n");
    deleteLinkedListItemsStartingWith (&linkedListItems[0]);
    printf("The new linked list is: ");
    printLinkedList(linkedListItems[0]);
    printf("\n\n");
    
    return 0;
}

void printLinkedList (LinkedListItem *item) {
    // Print out the data in the linked list item
    int dataInLinkedListItem = item->data;
    printf("%d ", dataInLinkedListItem);
    
    // Call the function recursively to get the next item
    if (item->nextItem) {
        printLinkedList (item->nextItem);
    }
}

LinkedListItem *findLinkedListItemWithData (LinkedListItem *item, int *data) {
    
    if (item->data == *data) {
        return item;
    } else if (item->nextItem) {
        // Call the function recursively until we find the item
        return findLinkedListItemWithData (item->nextItem, data);
    }
    
    
    return NULL; // We didn't find the item
}

LinkedListItem *findLastLinkedListItem (LinkedListItem *item) {
    
    // Call the function recursively until we find the last item
    if (item->nextItem) {
        return findLastLinkedListItem (item->nextItem);
    }
    
    return item;
}

void insertAtEndOfLinkedList (LinkedListItem *firstItem, int *dataToInsert) {
    
    LinkedListItem *lastItem = findLastLinkedListItem (firstItem);
    
    LinkedListItem *newInsertedItem = makeLinkedListItem(dataToInsert);
    
    lastItem->nextItem = newInsertedItem;
    
    
}

LinkedListItem *makeLinkedListItem(int *data) {
    LinkedListItem *newItem = malloc(sizeof(LinkedListItem));
    newItem->data = *data;
    newItem->nextItem = NULL;
    return newItem;
}

void joinLinkedListItemToNextItem (LinkedListItem *initialItem, LinkedListItem *nextItem) {
    initialItem->nextItem = nextItem;
}

void deleteLinkedListItemsStartingWith (LinkedListItem **item) {
    LinkedListItem *nextItem = (*item)->nextItem;
    free(*item);
    
    // Call the function recursively until we find the last item
    if (nextItem) {
        deleteLinkedListItemsStartingWith(&nextItem);
    }
    
}

//LinkedListItem *makeLinkedListWithData(int *data, ) {
//    LinkedListItem *newItem = malloc(sizeof(LinkedListItem));
//    newItem->data = *data;
//    return newItem;
//}
