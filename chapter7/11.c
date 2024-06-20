/*The ABC Mail Order Grocery sells artichokes for $2.05 per pound, beets for $1.15 per 
pound, and carrots for $1.09 per pound. It gives a 5% discount for orders of $100 or 
more prior to adding shipping costs. It charges $6.50 shipping and handling for any 
order of 5 pounds or under, $14.00 shipping and handling for orders over 5 pounds 
and under 20 pounds, and $14.00 plus $0.50 per pound for shipments of 20 pounds or 
more. Write a program that uses a switch statement in a loop such that a response of a
lets the user enter the pounds of artichokes desired, b the pounds of beets, c the pounds 
of carrots, and q allows the user to exit the ordering process. The program should keep 
track of cumulative totals. That is, if the user enters 4 pounds of beets and later enters 
5 pounds of beets, the program should use report 9 pounds of beets. The program then 
should compute the total charges, the discount, if any, the shipping charges, and the 
grand total. The program then should display all the purchase information: the cost per 
pound, the pounds ordered, and the cost for that order for each vegetable, the total cost 
of the order, the discount (if there is one), the shipping charge, and the grand total of all 
the charges. 
*/

#include <stdio.h>

int main (void){
    const float ARTI = 2.05;
    const float BEET = 1.15;
    const float CARR = 1.09;

    const float DISC = 0.05;
    const float DISC_MIN = 100.00;

    const float MINSH_COST = 6.5;
    const float MINSH_WEIGHT = 5.0;

    const float MIDSH_COST = 14.00;
    const float MIDSH_WEIGHT = 20.0;

    const float MAXSH_COST = 0.5;

    char product;
    float weight = 0;
    float price = 0;

    while(1){
        printf("Enter desired product: \n");
        printf("a) artichokes\n");
        printf("b) beets\n");
        printf("c) carrots\n");
        printf("q) Exit ordering\n");

        product = getchar();

        if (product != 'a' && product != 'b' && product != 'c' && product != 'q')
            continue;

        if (product == 'q')
            break;

        printf("Enter weight in pounds: ");
        scanf("%f", &weight);

        switch (product){
            case 'a':
                price += (weight * ARTI);
                break;
            case 'b':
                price += (weight * BEET);
                break;
            case 'c':
                price += (weight * CARR);
                break;
        }
        getchar();
        }

            price = price > DISC_MIN ? price - price * DISC : price;

            if (weight > MIDSH_WEIGHT){
                price += (MIDSH_COST + ((weight - MIDSH_WEIGHT) * MAXSH_COST));
            }
            else if (weight > MINSH_WEIGHT){
                price += MIDSH_COST;
            }
            else {
                price += MINSH_COST;
            }
    

    printf("Total cost is %.2f", price);


}