#include <stdio.h>

int main (void){

    int num_people, slices_per_pizza, slices_each = 0;
    int pizzas_req = 0;
    int remainder = 0;

    scanf("%d", &num_people);

    scanf("%d", &slices_per_pizza);

    scanf("%d", &slices_each);

    pizzas_req = (num_people * slices_each) / slices_per_pizza;
    remainder = (num_people * slices_each) % slices_per_pizza;

    if (remainder != 0){
        pizzas_req ++;
    }
    
    printf("%d\n", pizzas_req);

return 0;
}