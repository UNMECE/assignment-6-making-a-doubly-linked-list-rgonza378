#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "coordinate.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_coordinates>\n", argv[0]);
        return 1;
    }

    int num_coordinates = atoi(argv[1]);
    srand(time(NULL));

    Coordinate *list_beginning = NULL;
    Coordinate *list_end = NULL;

    for (int i = 0; i < num_coordinates; i++) {
         float x = (float)(rand() % 100);
         float y = (float)(rand() % 100);
         add_coordinate(list_end, x, y);
         if (list_beginning == NULL) {
             list_beginning = list_end;
         }
         list_end = list_end->next;
    }   
    printf("Forward display:\n");
    forward_display(list_beginning);                                                printf("Backward display:\n");                                                  backward_display(list_end);


    delete_coordinate(list_beginning, 3);
    closest_to(list_beginning, 50.0, 50.0);

    return 0;
}
