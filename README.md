# Beep-Christmas-Song
A program that plays Deck the Halls (a famous christmas song).

# Usage

## Default
* base note as 440Hz (A4)
* base beat duration set to 500 (msec?)
* ```$ Beep-Christmas-Song.exe```

## Custom
* ```*``` > optional
* ```$ Beep-Christmas-Song.exe [base_note: C|D|E|F|G|A|B] [*duration: double]``` >set base note as base_note(4), and base beat to duration
* ```-f [freq: double] [*duration: double]``` >set base note as specific frequency
* ```-b [duration: double]``` >set base beat to specific time
* ```-h [base_note: C|D|E|F|G|A|B] [note_pitch: int] [*duration: double]``` >set base note to specific note with specific pitch, and base beat to specific duration

## Examples
```
$ Beep-Christmas-Song.exe -h G 3 400
$ Beep-Christmas-Song.exe -f 442
```

# Song

## Custom
* rewrite function ```music()```
* given 3 array, note, height(pitch), beat(tempo)

## Note
* Equal Temperament
```
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
```

## Example
```
// DeckTheHalls
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
```
