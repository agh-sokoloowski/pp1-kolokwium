#ifdef __cplusplus
#include <iostream>
#include <cstring>

using namespace std;
#else

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#endif

#include "task2Filtering.h"

//    /// pomocna moze okazac sie zaimplementowanie rowniez funkcji:
//bool isPersonAsIWant(const Person* person, PersonField field, const void* fieldValue)
//{
//    return false;
//}

Person *
getFilteredPersons(const Person *personsBegin, const Person *personsEnd, PersonField field, const void *fieldValue) {
    if (personsBegin > personsEnd) return NULL;
    if (personsBegin == NULL) return NULL;
    if (personsEnd == NULL) return NULL;

    Person *person = {0};
    unsigned k = 0;
    while (personsBegin < personsEnd) {
        if (field == PERSON_FIELD_ID)
            if (personsBegin->id == *(int *) fieldValue) {
                person = realloc(person, sizeof(Person) * ++k);
                person[k - 1] = *personsBegin;
                break;
            }
        if (field == PERSON_FIELD_NAME)
            if (strcmp(personsBegin->name, fieldValue) == 0) {
                person = realloc(person, sizeof(Person) * ++k);
                person[k - 1] = *personsBegin;
            }
        if (field == PERSON_FIELD_PROFESSION)
            if (strcmp(personsBegin->profession, fieldValue) == 0) {
                person = realloc(person, sizeof(Person) * ++k);
                person[k - 1] = *personsBegin;
            }
        if (field == PERSON_FIELD_SEX)
            if (personsBegin->sex == *(int *) fieldValue) {
                person = realloc(person, sizeof(Person) * ++k);
                person[k - 1] = *personsBegin;
            }
        if (field == PERSON_FIELD_AGE)
            if (personsBegin->ageInYears == *(int *) fieldValue) {
                person = realloc(person, sizeof(Person) * ++k);
                person[k - 1] = *personsBegin;
            }
        if (field == PERSON_FIELD_ANY)
            if (
                    personsBegin->id == *(int *) fieldValue ||
                    personsBegin->name == fieldValue ||
                    personsBegin->profession == fieldValue ||
                    personsBegin->sex == *(int *) fieldValue ||
                    personsBegin->ageInYears == *(int *) fieldValue
                    ) {
                person = realloc(person, sizeof(Person) * ++k);
                person[k - 1] = *personsBegin;
            }

        *personsBegin++;
    }

    person = realloc(person, sizeof(Person) * ++k);
    Person emptyPerson = {0};
    person[k - 1] = emptyPerson;

    return person;
}
