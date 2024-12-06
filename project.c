
#include <stdio.h>
#include <string.h>

// Function to display local charge table
void display_chargetable_local() {
    // Print the local telecom charge plans
    printf("    HELLO USER \n\n   WELCOME   ");
    printf("-------------------------------------------------\n");
    printf("Telecom Charges Table \n");
    printf("--------------------------------------------------\n");
    printf("UNLIMITED Plans                     |   Price\n");
    printf("------------------------------------------------------\n");
    printf("1. 1GB/ day + Unlimited call for 30 Days              |   Rs 400\n");
    printf("2. 1.5GB/ day + Unlimited call for 30 Days            |   Rs 600\n");
    printf("3. 2 GB/ day + Unlimited call for 50 Days             |   Rs 800\n");
    printf("4. 3GB/ day + Unlimited call for 180 Days             |   Rs 1000\n");
    printf("5. 2GB/ day + Unlimited call for 365 Days             |   Rs 2500\n");
    printf("6. 1GB/ day + Unlimited call for 20 Days              |   Rs 120\n\n");

    printf("DATA Plans                     |   Price\n");
    printf("-------------------------------------------------------\n");
    printf("7. 1 GB for 1 day                                      | Rs 25\n");
    printf("8. 3 GB for 2 days                                     | Rs 60\n");
    printf("9. 10 GB FOR 10 DAYS                                   | Rs 110\n");

    printf("CALL Plans                     |   Price\n");
    printf("--------------------------------------------------------\n");
    printf("10. 200 MIN                                          | Rs 200\n");
    printf("11. 100 MIN                                          | Rs 150\n");
    printf("12. 1000 MIN                                         | Rs 700\n");
    printf("13. 600 MIN                                          | Rs 600\n");

    printf("------------------------------------------\n");
}

// Structure to store user details
typedef struct {
    char name[50];
    char number[20];
} User;

// Function to load user details from a file
int load_user_details(const char *filename, User users[], int max_users) {
    FILE *file = fopen("userdata.txt", "r");
    if (!file) {
        // Error handling if the file cannot be opened
        printf("Could not open file\n");
        return -1;
    }

    int count = 0;
    // Read user details from the file
    while (count < max_users && fscanf(file, "%s %s", users[count].name, users[count].number) != EOF) {
        count++;
    }

    fclose(file);
    return count; // Return the number of users loaded
}

// Function to verify user details
int verify_user(const char *name, const char *number, User users[], int user_count) {
    // Compare the input name and number with the stored details
    for (int i = 0; i < user_count; i++) {
        if (strcmp(name, users[i].name) == 0 && strcmp(number, users[i].number) == 0) {
            return 1; // User verified
        }
    }
    return 0; // User not found
}

// Function to display ISD charge table
void display_chargetable_isd() {
    // Print the ISD telecom charge plans
    printf("----------------------------------\n");
    printf("Telecom Charges Table \n");
    printf("--------------------------------\n");
    printf(" Plans                     |   Price\n");
    printf("-------------------------------------\n");
    printf("1. 5GB FOR 30 DAYS + 100 MINS CALLING                 | Rs 2000 \n");
    printf("2. 20GB FOR 60 DAYS + 250 MINS CALLING                | Rs 4000 \n");
    printf("3. 5GB FOR 10 DAYS + 50 MINS CALLING                  | Rs 1500 \n");
    printf("4. 20GB FOR 80 DAYS + 500 MINS CALLING                | Rs 10000 \n");
    printf("5. 5GB FOR 5 DAYS + 100 MINS CALLING                  | Rs 1000 \n");
}

// Function to calculate charges for local plans
float calculate_charges_local(int servicetype) {
    // Map service type to its respective cost
    float rate = 0;
    switch (servicetype) {
        case 1: rate = 400; break;
        case 2: rate = 600; break;
        case 3: rate = 800; break;
        case 4: rate = 1000; break;
        case 5: rate = 2500; break;
        case 6: rate = 120; break;
        case 7: rate = 25; break;
        case 8: rate = 60; break;
        case 9: rate = 110; break;
        case 10: rate = 200; break;
        case 11: rate = 150; break;
        case 12: rate = 700; break;
        case 13: rate = 600; break;
        default: printf("Invalid service type\n"); return -1;
    }
    return rate;
}

// Function to calculate charges for ISD plans
float calculate_charges_isd(int servicetype) {
    // Map service type to its respective cost
    float rate = 0;
    switch (servicetype) {
        case 1: rate = 2000; break;
        case 2: rate = 4000; break;
        case 3: rate = 1500; break;
        case 4: rate = 10000; break;
        case 5: rate = 1000; break;
        default: printf("Invalid service type\n"); return -1;
    }
    return rate;
}
// Function to calculate postpaid charges
float calculate_postpaid_charges(float dataUsage, int talkTime) {
    const float DATA_RATE = 10.0; // Rs per GB
    const float CALL_RATE = 0.50; // Rs per minute
    const float FIXED_COST = 500; // Fixed monthly cost
    return FIXED_COST + (dataUsage * DATA_RATE) + (talkTime * CALL_RATE);
}
// Function to calculate fixed costs based on duration
float fixed_costs(int duration) {
    float cost = 0;
    if (duration == 1) {
        cost = 200; // Fixed cost for 1 month
    } else if (duration == 12) {
        cost = 2000; // Fixed cost for 1 year with discount
    } else {
        cost = duration * 200; // Custom fixed cost for more than 1 month
    }
    return cost;
}

// Function to calculate variable costs based on usage
float variable_costs(int usage) {
    return usage * 10; // Variable cost per unit of usage
}

// Function to process debit card payment
void process_debit_card(float amount) {
    char cardNumber[20], expiryDate[10], cvv[5];
    printf("Enter Debit Card Number: ");
    scanf("%s", cardNumber);
    printf("Enter Expiry Date (MM/YY): ");
    scanf("%s", expiryDate);
    printf("Enter CVV: ");
    scanf("%s", cvv);
    printf("Processing Debit Card Payment of Rs %.2f\n", amount);
    printf("Payment Successful!\n");
}

// Function to process credit card payment
void process_credit_card(float amount) {
    char cardNumber[20], expiryDate[10], cvv[5];
    printf("Enter Credit Card Number: ");
    scanf("%s", cardNumber);
    printf("Enter Expiry Date (MM/YY): ");
    scanf("%s", expiryDate);
    printf("Enter CVV: ");
    scanf("%s", cvv);
    printf("Processing Credit Card Payment of Rs %.2f\n", amount);
    printf("Payment Successful!\n");
}

// Function to process UPI payment
void process_upi(float amount) {
    char upiId[50];
    printf("Enter UPI ID: ");
    scanf("%s", upiId);
    printf("Processing UPI Payment of Rs %.2f\n", amount);
    printf("Payment Successful!\n");
}

// Function to process EMI payment
void process_emi(float amount) {
    int tenure;
    printf("Enter EMI Tenure (in months): ");
    scanf("%d", &tenure);
    printf("Processing EMI Payment of Rs %.2f for %d months\n", amount, tenure);
    printf("Payment Successful!\n");
}

// Function to handle payments
void payments(float totalCharges) {
    int choice;
    printf("Payment options\n");
    printf("1. Debit card\n");
    printf("2. Credit card\n");
    printf("3. UPI\n");
    printf("4. EMI\n");
    printf("Enter your choice (1 to 4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            process_debit_card(totalCharges);
            break;
        case 2:
            process_credit_card(totalCharges);
            break;
        case 3:
            process_upi(totalCharges);
            break;
        case 4:
            process_emi(totalCharges);
            break;
        default:
            printf("Invalid payment option\n");
            break;
    }
}

int main() {
    int serviceType, a, duration, usage;
    float totalCharges;
    User users[100]; // Array to hold up to 100 users
    int user_count = load_user_details("user_details.txt", users, 100);

    if (user_count == -1) {
        return 1; // Exit if file could not be loaded
    }

    char name[50], number[20];

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your number: ");
    scanf("%s", number);

    if (verify_user(name, number, users, user_count)) {
        printf("User verified successfully.\n");
        printf("For Local telecom charge table enter 1\nfor ISD enter 2\nfor Postpaid enter 3\n ");
        printf("Enter your choice: ");
        scanf("%d", &a);
        float dataUsage;
        int talkTime;

        switch (a) {
            case 1:
                display_chargetable_local();
                printf("Enter service type: ");
                scanf("%d", &serviceType);
                totalCharges = calculate_charges_local(serviceType);
                printf("Enter duration (in months): ");
                scanf("%d", &duration);
                printf("Enter usage: ");
                scanf("%d", &usage);
                totalCharges += fixed_costs(duration) + variable_costs(usage);
                payments(totalCharges);
                break;

            case 2:
                display_chargetable_isd();
                printf("Enter service type: ");
                scanf("%d", &serviceType);
                totalCharges = calculate_charges_isd(serviceType);
                printf("Enter duration (in months): ");
                scanf("%d", &duration);
                printf("Enter usage: ");
                scanf("%d", &usage);
                totalCharges += fixed_costs(duration) + variable_costs(usage);
                payments(totalCharges);
                break;
            case 3:
                printf("Enter data usage (in GB): ");
                scanf("%f", &dataUsage);
                printf("Enter talk time (in minutes): ");
                scanf("%d", &talkTime);
                float totalCharges = calculate_postpaid_charges(dataUsage, talkTime);
                printf("Total Postpaid charges: Rs%.2f\n", totalCharges);
                payments(totalCharges);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } else {
        printf("Verification failed.\nif you want to enjoy our servies please register your name and number in our database");
    }

    return 0;
}