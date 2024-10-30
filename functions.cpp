#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coordinate.h"

void add_coordinate(Coordinate *list_end, float x, float y) {
    Coordinate *new_coord = (Coordinate*)malloc(sizeof(Coordinate));
    if (!new_coord) {
        printf("Memory allocation failed\n");
        return;
    }

    new_coord->x = x;
    new_coord->y = y;
    new_coord->coord_id = list_length(list_end) + 1;
    new_coord->next = NULL;
    new_coord->previous = list_end;

    if (list_end != NULL) {
        list_end->next = new_coord;
    }
}

void forward_display(Coordinate *list_beginning) {
    Coordinate *current = list_beginning;
    while (current != NULL) {
        printf("Coordinate ID: %d, x: %.2f, y: %.2f\n", current->coord_id, current->x, current->y);
        current = current->next;
    }
}

void backward_display(Coordinate *list_end) {
    Coordinate *current = list_end;
    while (current != NULL) {
        printf("Coordinate ID: %d, x: %.2f, y: %.2f\n", current->coord_id, current->x, current->y);
        current = current->previous;
    }
}

void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete) {
    Coordinate *current = list_beginning;
    while (current != NULL) {
        if (current->coord_id == coord_id_to_delete) {
            if (current->previous != NULL)
                current->previous->next = current->next;
            if (current->next != NULL)
                current->next->previous = current->previous;
            free(current);
            printf("Coordinate ID %d deleted.\n", coord_id_to_delete);
            return;
        }
        current = current->next;
    }
    printf("Coordinate ID %d not found.\n", coord_id_to_delete);
}

int list_length(Coordinate *list_beginning) {
    int length = 0;
    Coordinate *current = list_beginning;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

void closest_to(Coordinate *list_beginning, float x, float y) {
    Coordinate *current = list_beginning;
    Coordinate *closest = NULL;
    float min_distance = -1.0;

    while (current != NULL) {
        float distance = sqrt(pow(current->x - x, 2) + pow(current->y - y, 2));
        if (min_distance == -1.0 || distance < min_distance) {
            min_distance = distance;
            closest = current;
        }
        current = current->next;
    }

    if (closest != NULL) {
        printf("Closest coordinate: ID %d, x: %.2f, y: %.2f, distance: %.2f\n",
               closest->coord_id, closest->x, closest->y, min_distance);
    } else {
        printf("No coordinates in the list.\n");
    }
}

