#include <stdio.h>
#include <string.h>

typedef enum {
    ROT,
    LILA,
    GELB,
    BLAU,
    GRAU
} color_t;

typedef struct {
    color_t color;
    const char *name;
} color_lookup_t;

static const color_lookup_t COLOR_LOOKUP[] = {
    { ROT, "Rot" },
    { LILA, "Lila" },
    { GELB, "Gelb" },
    { BLAU, "Blau" },
    { GRAU, "Grau" }
};

static const size_t COLOR_LOOKUP_COUNT = sizeof(COLOR_LOOKUP) / sizeof(COLOR_LOOKUP[0]);

const char *color_to_string(color_t color) {
    for (size_t i = 0; i < COLOR_LOOKUP_COUNT; ++i) {
        if (COLOR_LOOKUP[i].color == color) {
            return COLOR_LOOKUP[i].name;
        }
    }

    return "Grau";
}

color_t color_from_string(const char *s) {
    for (size_t i = 0; i < COLOR_LOOKUP_COUNT; ++i) {
        if (strcmp(COLOR_LOOKUP[i].name, s) == 0) {
            return COLOR_LOOKUP[i].color;
        }
    }

    return GRAU;
}

int main(void) {
    char input[64];

    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    color_t c = color_from_string(input);
    const char *output = color_to_string(c);

    printf("%s\n", output);

    return 0;
}
