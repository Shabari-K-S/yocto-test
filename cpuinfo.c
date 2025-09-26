#include <stdio.h>
#include <stdlib.h>

void print_cpu_info() {
    FILE *cpuinfo = fopen("/proc/cpuinfo", "r");
    if (!cpuinfo) {
        perror("Failed to open /proc/cpuinfo");
        return;
    }
    char line[256];
    printf("CPU Info:\n");
    while (fgets(line, sizeof(line), cpuinfo)) {
        printf("%s", line);
    }
    fclose(cpuinfo);
}

void print_mem_info() {
    FILE *meminfo = fopen("/proc/meminfo", "r");
    if (!meminfo) {
        perror("Failed to open /proc/meminfo");
        return;
    }
    char line[256];
    printf("Memory Info:\n");
    while (fgets(line, sizeof(line), meminfo)) {
        printf("%s", line);
    }
    fclose(meminfo);
}

int main() {
    print_cpu_info();
    printf("\n");
    print_mem_info();
    return 0;
}
