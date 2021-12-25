# include <iostream>
# include <cstdlib>
# include <cmath>
# include <windows.h>

// # define A_4 440
// # define BEAT 500

double A_4 = 440;
double BEAT = 500;

# define a(n, h, d) {\
            Beep(equal_temperament(n, h), beat_gen(d)); \
        }

# define err() {\
            std::cerr << "Argument error!\n"; \
            abort();\
        }

typedef enum {
    A = 0,
    As = 1,
    B = 2,
    C = 3,
    Cs = 4,
    D = 5,
    Ds = 6,
    E = 7,
    F = 8,
    Fs = 9,
    G = 10,
    Gs = 11
} NOTE;

DWORD equal_temperament(NOTE n, int h)
{
    return DWORD(A_4 * pow(2, (double)n/12 + h-4));
}

DWORD beat_gen(double d)
{   
    return DWORD(BEAT * d);
}

void music()
{
    NOTE arr_n[] = {C, As, A, G, F, G, A, F, G, A, As, G, A, G, F, E, F, 
                    C, As, A, G, F, G, A, F, G, A, As, G, A, G, F, E, F,
                    G, A, As, G, A, As, C, G, A, As, C, D, E, F, E, D, C,
                    C, As, A, G, F, G, A, F, G, A, As, G, A, G, F, E, F
                    };
    int arr_h[] = {5, 5, 5, 4, 4, 4, 5, 4, 4, 5, 5, 4, 5, 4, 4, 4, 4,
                    5, 5, 5, 4, 4, 4, 5, 4, 4, 5, 5, 4, 5, 4, 4, 4, 4,
                    4, 5, 5, 4, 5, 5, 5, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                    5, 5, 5, 4, 4, 4, 5, 4, 4, 5, 5, 4, 5, 4, 4, 4, 4
                    };
    double arr_d[] = {1.5, 0.5, 1, 1, 1, 1, 1, 1, 0.25, 0.25, 0.25, 0.25, 1.5, 0.5, 1, 1, 2,
                    1.5, 0.5, 1, 1, 1, 1, 1, 1, 0.25, 0.25, 0.25, 0.25, 1.5, 0.5, 1, 1, 2,
                    1.5, 0.5, 1, 1, 1.5, 0.5, 1, 1, 0.5, 0.5, 1, 0.5, 0.5, 1, 1, 1, 2,
                    1.5, 0.5, 1, 1, 1, 1, 1, 1, 0.25, 0.25, 0.25, 0.25, 1.5, 0.5, 1, 1, 2,
                    };

    for(int i=0; i<sizeof(arr_n); ++i)
    {
        a(arr_n[i], arr_h[i], arr_d[i]);
    }
}

int main(int argc, char *argv[])
{
    // getopt?
    if(argc > 1){
        if(strcmp(argv[1], "-f") == 0){
            if(argc == 3){
                A_4 = atof(argv[2]);
            }
            else if (argc == 4){
                A_4 = atof(argv[2]);
                BEAT = atof(argv[3]);
            }
            else{
                err();
            }
        }
        else if(strcmp(argv[1], "-h") == 0){
            if(argc == 4){
                A_4 = equal_temperament(static_cast<NOTE>(argv[2][0] - 65), atoi(argv[3]));
            }
            else if(argc == 5){
                A_4 = equal_temperament(static_cast<NOTE>(argv[2][0] - 65), atoi(argv[3]));
                BEAT = atof(argv[4]);
            }
            else{
                err();
            }
        }
        else if(strcmp(argv[1], "-b") == 0){
            if(argc == 3){
                BEAT = atof(argv[2]);
            }
            else{
                err();
            }
        }
        else{
            if(argc == 2){
                A_4 = equal_temperament(static_cast<NOTE>(argv[1][0] - 65), 4);
            }
            else if(argc == 3)
            {
                A_4 = equal_temperament(static_cast<NOTE>(argv[1][0] - 65), 4);
                BEAT = atof(argv[2]);
            }
            else{
                err();
            }
        }          
    }

    std::cout << "Start music with base frequency: " << A_4 << "Hz, and base beat: " << BEAT << "\n";
    music();
    return 0;
}

