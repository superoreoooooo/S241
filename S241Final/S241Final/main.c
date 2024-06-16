#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_ttf.h>

#define MAX_NAME_LEN 30
#define MAX_DATA 4000
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

#pragma warning(disable : 4996)

int clickedData = -1;

typedef struct Date {
    int year;
    int month;
    int day;
    int hour;
    int minute;
} Date;

typedef struct Data {
    char deviceName[MAX_NAME_LEN];
    int pm10;
    int pm25;
    int co2;
    int tvoc;
    int temperature;
    int humidity;
    Date date;
} Data;

SDL_Color colors[] = {
    {255, 69, 0, 255},    // pm10               (orange red)
    {60, 179, 113, 255},  // pm25               (medium sea green)
    {30, 144, 255, 255},  // co2                (dodger blue)
    {218, 165, 32, 255},  // tvoc               (golden rod)
    {138, 43, 226, 255},  // temperature        (blue violet)
    {0, 206, 209, 255},   // humidity           (dark turquoise)
    {0, 0, 0, 255}        // reset              (black)
};

void parse_date_time(const char* dateTimeStr, Date* date) {
    char buffer[100];
    strncpy(buffer, dateTimeStr, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    sscanf(buffer, "%d-%d-%d  %d:%d",
        &date->year, 
        &date->month,
        &date->day,
        &date->hour, 
        &date->minute
    );
}

void read(const char* fileName, Data data[], int* count) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        perror("open error!");
        exit(1);
    }

    char buffer[256];
    *count = 0;

    fgets(buffer, sizeof(buffer), file);

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char* token;
        char deviceName[MAX_NAME_LEN];
        char dateTime[MAX_NAME_LEN];
        int pm10, pm25, co2, tvoc, temperature, humidity;

        token = strtok(buffer, ",");
        if (token != NULL) {
            strncpy(deviceName, token, MAX_NAME_LEN);
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            pm10 = atoi(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            pm25 = atoi(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            co2 = atoi(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            tvoc = atoi(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            temperature = atoi(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            humidity = atoi(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            strncpy(dateTime, token, MAX_NAME_LEN);
        }

        Date date;
        if (dateTime != NULL) {
            char period[3] = { 0 };
            //printf("%s", dateTime);
            parse_date_time(dateTime, &date);
        }

        strncpy(data[*count].deviceName, deviceName, MAX_NAME_LEN);
        data[*count].pm10 = pm10;
        data[*count].pm25 = pm25;
        data[*count].co2 = co2;
        data[*count].tvoc = tvoc;
        data[*count].temperature = temperature;
        data[*count].humidity = humidity;
        data[*count].date = date;

        (*count)++;
        if (*count >= MAX_DATA) break;
    }

    fclose(file);
}

void print_data(Data data[], int cnt) {
    printf("Device Name\t\tPM10\tPM2.5\tCO2\tTVOC\tTemp\tHumidity\tDate\n");
    for (int i = 0; i < cnt; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d-%02d-%02d %02d:%02d\n",
            data[i].deviceName,
            data[i].pm10,
            data[i].pm25,
            data[i].co2,
            data[i].tvoc,
            data[i].temperature,
            data[i].humidity,
            data[i].date.year,
            data[i].date.month,
            data[i].date.day,
            data[i].date.hour,
            data[i].date.minute
        );
    }
}

void draw_line(SDL_Renderer* renderer, int x1, int y1, int x2, int y2, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void render_text(SDL_Renderer* renderer, TTF_Font* font, const char* text, int x, int y, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect dstrect = { x, y, surface->w, surface->h };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void render_graph(SDL_Renderer* renderer, TTF_Font* font, Data data[], int count) {
    int max_val = 0, min_val = INT_MAX;

    int c = 0, k = 5;

    if (clickedData == -1) {
        for (int i = 0; i < count - 1; i++) {
            if (data[i].pm10 > max_val) max_val = data[i].pm10;
            if (data[i].pm25 > max_val) max_val = data[i].pm25;
            if (data[i].co2 > max_val) max_val = data[i].co2;
            if (data[i].tvoc > max_val) max_val = data[i].tvoc;
            if (data[i].temperature > max_val) max_val = data[i].temperature;
            if (data[i].humidity > max_val) max_val = data[i].humidity;

            if (data[i].pm10 < min_val) min_val = data[i].pm10;
            if (data[i].pm25 < min_val) min_val = data[i].pm25;
            if (data[i].co2 < min_val) min_val = data[i].co2;
            if (data[i].tvoc < min_val) min_val = data[i].tvoc;
            if (data[i].temperature < min_val) min_val = data[i].temperature;
            if (data[i].humidity < min_val) min_val = data[i].humidity;
        }
    }

    if (clickedData != -1) {
        c = clickedData;
        k = clickedData;
        for (int i = 0; i < count; i++) {
            switch (clickedData) {
            case 0:
                if (data[i].pm10 > max_val) max_val = data[i].pm10;
                if (data[i].pm10 < min_val) min_val = data[i].pm10;
                break;
            case 1:
                if (data[i].pm25 > max_val) max_val = data[i].pm25;
                if (data[i].pm25 < min_val) min_val = data[i].pm25;
                break;
            case 2:
                if (data[i].co2 > max_val) max_val = data[i].co2;
                if (data[i].co2 < min_val) min_val = data[i].co2;
                break;
            case 3:
                if (data[i].tvoc > max_val) max_val = data[i].tvoc;
                if (data[i].tvoc < min_val) min_val = data[i].tvoc;
                break;
            case 4:
                if (data[i].temperature > max_val) max_val = data[i].temperature;
                if (data[i].temperature < min_val) min_val = data[i].temperature;
                break;
            case 5:
                if (data[i].humidity > max_val) max_val = data[i].humidity;
                if (data[i].humidity < min_val) min_val = data[i].humidity;
                break;
            }
        }
    }


    if (max_val == 0) return;

    int margin = 50;
    //for (int j = 0; j < 6; j++) {
    for (int j = c; j <= k; j++) {
        for (int i = 1; i < count; i++) {
            int x1 = margin + (i - 1) * (WINDOW_WIDTH - 2 * margin) / (count - 1);
            int x2 = margin + i * (WINDOW_WIDTH - 2 * margin) / (count - 1);

            int y1, y2;
            switch (j) {
            case 0:
                y1 = WINDOW_HEIGHT - margin - (data[i - 1].pm10 - min_val) * (WINDOW_HEIGHT - 2 * margin) / (max_val - min_val);
                y2 = WINDOW_HEIGHT - margin - (data[i].pm10 - min_val) * (WINDOW_HEIGHT - 2 * margin) / (max_val - min_val);
                break;
            case 1:
                y1 = WINDOW_HEIGHT - margin - (data[i - 1].pm25 - min_val) * (WINDOW_HEIGHT - 2 * margin) / (max_val - min_val);
                y2 = WINDOW_HEIGHT - margin - (data[i].pm25 - min_val) * (WINDOW_HEIGHT - 2 * margin) / (max_val - min_val);
                break;
            case 2:
                y1 = WINDOW_HEIGHT - margin - (data[i - 1].co2 - min_val) * (WINDOW_HEIGHT - 2 * margin) / (max_val - min_val);
                y2 = WINDOW_HEIGHT - margin - (data[i].co2 - min_val) * (WINDOW_HEIGHT - 2 * margin) / (max_val - min_val);
                break;
            case 3:
                y1 = WINDOW_HEIGHT - margin - (data[i - 1].tvoc - min_val) * (WINDOW_HEIGHT - 2 * margin) / (max_val - min_val);
                y2 = WINDOW_HEIGHT - margin - (data[i].tvoc - min_val) * (WINDOW_HEIGHT - 2 * margin) / (max_val - min_val);
                break;
            case 4:
                y1 = WINDOW_HEIGHT - margin - (data[i - 1].temperature - min_val) * (WINDOW_HEIGHT - 2 * margin) / (max_val - min_val);
                y2 = WINDOW_HEIGHT - margin - (data[i].temperature - min_val) * (WINDOW_HEIGHT - 2 * margin) / (max_val - min_val);
                break;
            case 5:
                y1 = WINDOW_HEIGHT - margin - (data[i - 1].humidity - min_val) * (WINDOW_HEIGHT - 2 * margin) / (max_val - min_val);
                y2 = WINDOW_HEIGHT - margin - (data[i].humidity - min_val) * (WINDOW_HEIGHT - 2 * margin) / (max_val - min_val);
                break;
            }

            draw_line(renderer, x1, y1, x2, y2, colors[j]);
        }
    }

    char buffer[32];
    SDL_Color textColor = { 0, 0, 0, 255 };

    snprintf(buffer, sizeof(buffer), "%d", max_val);
    render_text(renderer, font, buffer, WINDOW_WIDTH - margin, margin / 4, textColor);

    snprintf(buffer, sizeof(buffer), "%d", min_val);
    render_text(renderer, font, buffer, WINDOW_WIDTH - margin, WINDOW_HEIGHT - margin, textColor);

    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", data[0].date.year, data[0].date.month, data[0].date.day);
    render_text(renderer, font, buffer, margin, WINDOW_HEIGHT - margin / 2, textColor);

    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", data[count - 1].date.year, data[count - 1].date.month, data[count - 1].date.day);
    render_text(renderer, font, buffer, WINDOW_WIDTH - margin * 3, WINDOW_HEIGHT - margin / 2, textColor);
}


void render_legend(SDL_Renderer* renderer, TTF_Font* font, SDL_Rect rects[]) {
    const char* labels[] = {
        "PM10",
        "PM2.5",
        "CO2",
        "TVOC",
        "Temperature",
        "Humidity",
        "Reset"
    };

    for (int i = 0; i < 7; i++) {
        SDL_Surface* surface = TTF_RenderText_Solid(font, labels[i], colors[i]);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_Rect dstrect = { 10, 10 + i * 30, surface->w, surface->h };
        rects[i] = dstrect;
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);

        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
    }
}

void handle_click(int x, int y, SDL_Rect rects[]) {
    const char* labels[] = {
        "PM10",
        "PM2.5",
        "CO2",
        "TVOC",
        "Temperature",
        "Humidity",
        "Reset"
    };

    for (int i = 0; i < 7; i++) {
        if (x >= rects[i].x && x <= rects[i].x + rects[i].w && y >= rects[i].y && y <= rects[i].y + rects[i].h) {
            //printf("%s clicked!\n", labels[i]);
            clickedData = i;
            if (i == 6) {
                clickedData = -1;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    Data data[MAX_DATA];
    int count;

    read("data.csv", data, &count);
    print_data(data, count);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() != 0) {
        fprintf(stderr, "TTF_Init Error: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("Data Visualization", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!win) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        SDL_DestroyWindow(win);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    TTF_Font* font = TTF_OpenFont("Pretendard-Thin.ttf", 16);
    if (!font) {
        fprintf(stderr, "TTF_OpenFont Error: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Rect rects[7];

    int quit = 0;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                handle_click(x, y, rects);
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        render_graph(renderer, font, data, count);
        render_legend(renderer, font, rects);

        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    TTF_Quit();
    SDL_Quit();

    return 0;
}