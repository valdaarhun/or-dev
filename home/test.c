#include <stdio.h>
#include <unistd.h>
 
// Helper function with minimal work
void helper() {
    volatile int x = 0;  // Volatile to prevent compiler optimization
    x++;
}
 
// CPU-bound function with a loop
void compute() {
    for (int i = 0; i < 100000000; i++) {  // Busy loop (high CPU)
        helper();  // Call helper occasionally
        if (i % 1000000 == 0) helper();
    }
}
 
// Processes data by calling compute repeatedly
void process_data() {
    for (int j = 0; j < 5; j++) {
        compute();  // Call compute 5 times
    }
}
 
// Main work function
void work() {
    process_data();  // Delegate to process_data
}
 
int main() {
    work();  // Start the workload
    printf("Done!\n");
    return 0;
}
