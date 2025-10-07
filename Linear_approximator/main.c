/*******************************************************************
Linear Approximator in C (First order taylor series)

This program calculates linear(taylor-series) approximations
of pre-defined functions: sin(x), cos(x), tan(x), exp(x),
log(x) and x*x. Program calculates the derivative using the 
central difference method.

Features: 
1. Trigonometric inputs can be entered in both degrees and radians.
2. Input validation for log(x) (x>0).
3. Handles tan(x) discontinuities.
4. Linear approximation formula used is F(x) = F(a) + F'(a)*(x-a).

Usage:
1. Compile with: gcc basic_linear_approximation.c
2. Run with: ./a.exe

Author: Tanish_Victor
Dated: 5-10-2025
********************************************************************/
#include <stdio.h>
#include <math.h>

double fun_select(int choice,double x);
double derivative(int choice,double a);
int main(){
    int choice;
    const double PI=3.14159265358;
    double x,a;
    do{
    printf("1. sinx\n2. cosx\n3. tanx\n4. log\n5. x^2\n6. exp\nEnter choice: ");
    scanf("%d",&choice);
    if(choice>6 || choice<1){
        printf("Invalid choice input, try again\n");
    }
    }while(choice>6 || choice<1);
    if(choice==3){
        printf("Avoid inputs near tan(x) discontinuities like PI/2 + n*PI\n");
    }
    int temp;
    if(choice==1 || choice==2 || choice==3){
        printf("1. Input in radians\n2. Input in degrees\nEnter choice: ");
        scanf("%d",&temp);
        while(temp!=1 && temp!=2){
            printf("Invalid input please enter choice again: ");
            scanf("%d",&temp);
        }
        if(temp==1){
            printf("Enter input in radians: ");
            scanf("%lf",&x);
            printf("Enter point of approximation a in radians: ");
            scanf("%lf",&a);
        }
        else if(temp==2){
            printf("Enter input in degrees: ");
            scanf("%lf",&x);
            printf("Enter point of approximation a in degrees: ");
            scanf("%lf",&a);
            x=x * PI/180.0;
            a=a * PI/180.0;
        }
    }
    else if(choice>4){
    printf("Enter point of approximation: ");
    scanf("%lf",&a);
    printf("Enter value of x for F(x): ");
    scanf("%lf",&x);
    }
    if(choice==3){
        double epsilon=1e-4;
        while(fabs(fmod(x-PI/2,PI))<epsilon){
            printf("Input too close to discontinuity, enter x again: ");
            scanf("%lf",&x);
        }
        while(fabs(fmod(a-PI/2,PI))<epsilon){
            printf("Point of approximation too close to discontinuity, enter a again: ");
            scanf("%lf",&a);
        }
    }
    if(choice==4){
        do{
            printf("Enter value of x for logarithm (x>0): ");
            scanf("%lf",&x);
            if(x<=0){
                printf("Invalid input, x cannot be non-positive for logarithm\n");
            }
        }while(x<=0);
        do{
            printf("Enter point of approximation for log(x), (a>0): ");
            scanf("%lf",&a);
            if(a<=0){
                printf("Invalid input, a cannot be non-positive for logarithm\n");
            }
        }while(a<=0);
    }


    double f_prime=derivative(choice,a);
    double approx=fun_select(choice,a)+f_prime*(x-a);

    printf("Linear approximation at x= %.5lf is %.10lf\n",x,approx);
    printf("Error: %.10lf\n",fabs(fun_select(choice,x)-approx));
    return 0;
}

double fun_select(int choice,double x){
    switch(choice){
        case 1: return sin(x);
        case 2: return cos(x);
        case 3: return tan(x);
        case 4: return log(x);
        case 5: return x*x;
        case 6: return exp(x);
        default: printf("Invalid operator choice\n");
        return 0.0; 
    }
}

double derivative(int choice,double a){
    double h=1e-5;
    double f_positive= fun_select(choice,a+h);
    double f_negative= fun_select(choice,a-h);
    return (f_positive-f_negative)/(2*h);
}