#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char debug_mode;
    char file_name[128];
    int unit_size;
    unsigned char mem_buf[10000];
    size_t mem_count;
    /* Any additional fields you deem necessary */
} state;

void toggle_debug_mode(state* s) {
    if (s->debug_mode) {
        printf("Debug flag now off\n");
        s->debug_mode = 0;
    } else {
        printf("Debug flag now on\n");
        s->debug_mode = 1;
    }
}

void set_file_name(state* s) {
    printf("Enter file name: ");
    fgets(s->file_name, sizeof(s->file_name), stdin);
    s->file_name[strcspn(s->file_name, "\n")] = '\0'; // Remove newline character
    if (s->debug_mode) {
        fprintf(stderr, "Debug: file name set to '%s'\n", s->file_name);
    }
}

void set_unit_size(state* s) {
    int size;
    printf("Enter unit size (1, 2, or 4): ");
    scanf("%d", &size);
    getchar(); // Consume newline character left in buffer

    if (size == 1 || size == 2 || size == 4) {
        s->unit_size = size;
        if (s->debug_mode) {
            fprintf(stderr, "Debug: set size to %d\n", s->unit_size);
        }
    } else {
        printf("Invalid size\n");
    }
}

void load_into_memory(state* s) {
    (void)s; // Mark parameter as unused
    printf("Not implemented yet\n");
}

void toggle_display_mode(state* s) {
    (void)s; // Mark parameter as unused
    printf("Not implemented yet\n");
}

void memory_display(state* s) {
    (void)s; // Mark parameter as unused
    printf("Not implemented yet\n");
}

void save_into_file(state* s) {
    (void)s; // Mark parameter as unused
    printf("Not implemented yet\n");
}

void memory_modify(state* s) {
    (void)s; // Mark parameter as unused
    printf("Not implemented yet\n");
}

void quit(state* s) {
    if (s->debug_mode) {
        fprintf(stderr, "quitting\n");
    }
    exit(0);
}

typedef struct {
    char *name;
    void (*func)(state*);
} menu_item;

menu_item menu[] = {
    {"Toggle Debug Mode", toggle_debug_mode},
    {"Set File Name", set_file_name},
    {"Set Unit Size", set_unit_size},
    {"Load Into Memory", load_into_memory},
    {"Toggle Display Mode", toggle_display_mode},
    {"Memory Display", memory_display},
    {"Save Into File", save_into_file},
    {"Memory Modify", memory_modify},
    {"Quit", quit},
    {NULL, NULL}
};

void print_debug_info(state* s) {
    if (s->debug_mode) {
        fprintf(stderr, "Debug:\n");
        fprintf(stderr, "unit_size: %d\n", s->unit_size);
        fprintf(stderr, "file_name: %s\n", s->file_name);
        fprintf(stderr, "mem_count: %zu\n", s->mem_count);
    }
}

void print_menu() {
    for (int i = 0; menu[i].name != NULL; i++) {
        printf("%d-%s\n", i, menu[i].name);
    }
}

int main() {
    state s = {0, "", 1, {0}, 0}; // Initialize state
    while (1) {
        print_debug_info(&s);
        printf("Choose action:\n");
        print_menu();
        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline character left in buffer
        if (choice >= 0 && (size_t)choice < (sizeof(menu) / sizeof(menu_item)) - 1) {
            menu[choice].func(&s);
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
