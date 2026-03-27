/**

 * Each pattern function uses nested loops to print a specific 2D shape.
 * The outer loop controls rows and the inner loop(s) control columns,
 * spaces, and characters printed per row.

 
 */

#include <iostream>
#include <cstdlib>
using namespace std;

// ─────────────────────────────────────────────────────────────────────────────
// STAR PATTERNS
// ─────────────────────────────────────────────────────────────────────────────

/**
 * Prints a right-angled triangle of stars.
 * Row i prints (i+1) stars, growing from top to bottom.
 *
 * Example (n=4):
 *   *
 *   **
 *   ***
 *   ****
 */
void printRightTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

/**
 * Prints an inverted right-angled triangle of stars.
 * Row i prints (n-i) stars, shrinking from top to bottom.
 *
 * Example (n=4):
 *   ****
 *   ***
 *   **
 *   *
 */
void printInvertedRightTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

/**
 * Prints a full n×n square of stars.
 * Both loops run n times, printing a star every iteration.
 *
 * Example (n=4):
 *   ****
 *   ****
 *   ****
 *   ****
 */
void printSquare(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

/**
 * Prints a hollow square (border only).
 * Stars are printed only on the first/last row or first/last column.
 *
 * Example (n=4):
 *   ****
 *   *  *
 *   *  *
 *   ****
 */
void printHollowSquare(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

/**
 * Prints a right-aligned triangle (staircase with leading spaces).
 * Row i prints (n-i-1) spaces followed by (i+1) stars.
 *
 * Example (n=4):
 *      *
 *     **
 *    ***
 *   ****
 */
void printRightAlignedTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        for (int k = 0; k <= i; k++) {
            cout << "*";
        }
        cout << endl;
    }
}

/**
 * Prints a centered pyramid of stars.
 * Row i has (n-i-1) leading spaces and (2*i+1) stars.
 *
 * Example (n=4):
 *      *
 *     ***
 *    *****
 *   *******
 */
void printPyramid(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        for (int k = 0; k < (2 * i) + 1; k++) {
            cout << "*";
        }
        cout << endl;
    }
}

/**
 * Prints an inverted centered pyramid of stars.
 * Row i has i leading spaces and (2*(n-i-1)+1) stars.
 *
 * Example (n=4):
 *   *******
 *    *****
 *     ***
 *      *
 */
void printInvertedPyramid(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int k = 0; k <= 2 * (n - i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }
}

/**
 * Prints a double pyramid (diamond-like shape without full symmetry).
 * Simply calls printPyramid then printInvertedPyramid.
 *
 * Example (n=3):
 *    *
 *   ***
 *  *****
 *  *****
 *   ***
 *    *
 */
void printDoublePyramid(int n) {
    printPyramid(n);
    printInvertedPyramid(n);
}

/**
 * Prints a full diamond shape.
 * Upper half: row i has (n-i-1) spaces and (2*i+1) stars.
 * Lower half: mirrors the upper half using adjusted counters.
 *
 * Example (n=4):
 *      *
 *     ***
 *    *****
 *   *******
 *    *****
 *     ***
 *      *
 */
void printDiamond(int n) {
    // Upper half
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - i - 1); j++) cout << " ";
        for (int k = 0; k < (2 * i) + 1; k++) cout << "*";
        for (int l = 0; l < (n - i - 1); l++) cout << " ";
        cout << endl;
    }
    // Lower half
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j <= i; j++) cout << " ";
        for (int k = 0; k < (2 * n) - (2 * i) - 3; k++) cout << "*";
        for (int j = 0; j <= i; j++) cout << " ";
        cout << endl;
    }
}

/**
 * Prints a double-sided triangle (hourglass-like merged shape).
 * Upper half is a right triangle; lower half is an inverted triangle (n-1 rows).
 *
 * Example (n=4):
 *   *
 *   **
 *   ***
 *   ****
 *   ***
 *   **
 *   *
 */
void printDoubleTriangle(int n) {
    printRightTriangle(n);
    printInvertedRightTriangle(n - 1);
}

/**
 * Prints a butterfly pattern.
 * Upper half: stars grow outward; lower half: stars shrink inward.
 * Each row has left stars, center spaces, and right stars mirrored.
 *
 * Example (n=4):
 *   ****    ****
 *   ***      ***
 *   **        **
 *   *          *
 *   *          *
 *   **        **
 *   ***      ***
 *   ****    ****
 */
void printButterfly(int n) {
    // Upper half (shrinking)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= (n - i - 1); j++) cout << "*";
        for (int k = 0; k < (2 * i); k++) cout << " ";
        for (int j = 0; j <= (n - i - 1); j++) cout << "*";
        cout << endl;
    }
    // Lower half (growing)
    for (int i = 0; i < n; i++) {
        for (int l = 0; l <= i; l++) cout << "*";
        for (int m = 0; m < (2 * n - (2 * i) - 2); m++) cout << " ";
        for (int l = 0; l <= i; l++) cout << "*";
        cout << endl;
    }
}

/**
 * Prints a butterfly pattern (alternate version — starts growing).
 * Upper half: stars grow with wide center gap.
 * Lower half: stars shrink with narrow center gap.
 *
 * Example (n=4):
 *   *      *
 *   **    **
 *   ***  ***
 *   ********
 *   ***  ***
 *   **    **
 *   *      *
 */
void printButterflyAlt(int n) {
    // Upper half
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) cout << "*";
        for (int m = 0; m < (2 * n - (2 * i) - 2); m++) cout << " ";
        for (int j = 0; j <= i; j++) cout << "*";
        cout << endl;
    }
    // Lower half
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < (n - i - 1); j++) cout << "*";
        for (int m = 0; m < (2 * i) + 2; m++) cout << " ";
        for (int j = 0; j < (n - i - 1); j++) cout << "*";
        cout << endl;
    }
}

/**
 * Prints a symmetric hourglass/bowtie pattern.
 * Uses a single outer loop (1 to 2n-1) to compute stars per row.
 * spaces variable adjusts by -2 going up and +2 coming down.
 *
 * Example (n=4):
 *   *      *
 *   **    **
 *   ***  ***
 *   ********
 *   ***  ***
 *   **    **
 *   *      *
 */
void printSymmetricHourglass(int n) {
    int spaces = (2 * n) - 2;
    for (int i = 1; i < (2 * n); i++) {
        int stars = i;
        if (i > n) stars = (2 * n) - i;
        for (int j = 1; j <= stars; j++) cout << "*";
        for (int j = 1; j <= spaces; j++) cout << " ";
        for (int j = 1; j <= stars; j++) cout << "*";
        cout << endl;
        if (i < n) spaces -= 2;
        else spaces += 2;
    }
}

// ─────────────────────────────────────────────────────────────────────────────
// NUMBER PATTERNS
// ─────────────────────────────────────────────────────────────────────────────

/**
 * Prints a right triangle where each row prints 1, 2, 3, ... up to (i+1).
 *
 * Example (n=4):
 *   1
 *   12
 *   123
 *   1234
 */
void printNumberRightTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << j + 1;
        }
        cout << endl;
    }
}

/**
 * Prints a triangle where every number in row i is (i+1).
 *
 * Example (n=4):
 *   1
 *   22
 *   333
 *   4444
 */
void printRowNumberTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << i + 1;
        }
        cout << endl;
    }
}

/**
 * Prints an inverted number triangle (1 to n-i per row).
 *
 * Example (n=4):
 *   1234
 *   123
 *   12
 *   1
 */
void printInvertedNumberTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - i - 1; j++) {
            cout << j + 1;
        }
        cout << endl;
    }
}

/**
 * Prints a binary triangle alternating 0s and 1s.
 * Cell (i, j) prints 1 if (i+j) is even, else 0.
 *
 * Example (n=4):
 *   1
 *   01
 *   101
 *   0101
 */
void printBinaryTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << ((j + i) % 2 == 0 ? 1 : 0);
        }
        cout << endl;
    }
}

/**
 * Prints Floyd's triangle: consecutive integers row by row.
 * A counter l starts at 1 and increments across all rows.
 *
 * Example (n=4):
 *   1
 *   2 3
 *   4 5 6
 *   7 8 9 10
 */
void printFloydTriangle(int n) {
    int l = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << l << " ";
            l++;
        }
        cout << endl;
    }
}

/**
 * Prints a number mirror triangle with dashes in the center.
 * Each row: ascending numbers, then dashes, then descending numbers.
 * Dash count = 2*(n-i-1) so it shrinks each row.
 *
 * Example (n=4):
 *   1------1
 *   12----21
 *   123--321
 *   12341234
 */
void printNumberMirrorTriangle(int n) {
    for (int i = 0; i < n; i++) {
        // Ascending numbers
        for (int j = 1; j <= i + 1; j++) cout << j;
        // Dashes
        for (int k = 0; k < (2 * n - 2 * i - 2); k++) cout << "-";
        // Descending numbers
        for (int l = i + 1; l >= 1; l--) cout << l;
        cout << endl;
    }
}

/**
 * Prints the "hollow rectangle border" pattern variant.
 * Stars on boundary cells only; inner cells are spaces.
 * Equivalent to printHollowSquare but uses a fixed column width of (n-1).
 *
 * Example (n=4):
 *   ***
 *   * *
 *   * *
 *   ***
 */
void printHollowRectangle(int n) {
    for (int i = 0; i < n; i++) {
        int cols = n - 1;
        for (int j = 0; j <= cols; j++) {
            if (i == 0 || i == (n - 1) || j == 0 || j == cols) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

/**
 * Prints a number spiral/shell pattern.
 * For a (2n-1)×(2n-1) grid, each cell value = n - min(distance from each border).
 * This creates concentric layers numbered from the outside inward.
 *
 * Example (n=3):
 *   33333
 *   32223
 *   32123
 *   32223
 *   33333
 */
void printNumberShell(int n) {
    int cols  = (2 * n) - 1;
    int rows  = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int top    = i;
            int left   = j;
            int right  = (2 * n - 2) - j;
            int bottom = (2 * n - 2) - i;
            int minDist = min(min(top, bottom), min(left, right));
            cout << (n - minDist);
        }
        cout << endl;
    }
}

// ─────────────────────────────────────────────────────────────────────────────
// CHARACTER PATTERNS
// ─────────────────────────────────────────────────────────────────────────────

/**
 * Prints a right triangle of alphabet characters (A, B, C, ...).
 * Each row resets to 'A' and prints up to the i-th letter.
 *
 * Example (n=4):
 *   A
 *   AB
 *   ABC
 *   ABCD
 */
void printCharRightTriangle(int n) {
    for (int i = 0; i < n; i++) {
        char a = 'A';
        for (int j = 0; j <= i; j++) {
            cout << a;
            a++;
        }
        cout << endl;
    }
}

/**
 * Prints an inverted character triangle.
 * Each row resets to 'A' and prints (n-i) letters.
 *
 * Example (n=4):
 *   ABCD
 *   ABC
 *   AB
 *   A
 */
void printInvertedCharTriangle(int n) {
    for (int i = 0; i < n; i++) {
        char b = 'A';
        for (int j = 0; j < n - i - 1; j++) {
            cout << b;
            b++;
        }
        cout << endl;
    }
}

/**
 * Prints a triangle where each row is filled with the same letter (row's letter).
 * Row 0 → 'A', row 1 → 'B', etc.
 *
 * Example (n=4):
 *   A
 *   BB
 *   CCC
 *   DDDD
 */
void printSameCharPerRow(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << char('A' + i);
        }
        cout << endl;
    }
}

/**
 * Prints a character diamond/pyramid.
 * Each row goes A → (midpoint letter) → A, mirrored around center.
 * Row i has (2*i+1) characters with 'A' at both ends and peak at position i.
 *
 * Example (n=4):
 *      A
 *     ABA
 *    ABCBA
 *   ABCDCBA
 */
void printCharDiamond(int n) {
    for (int i = 0; i < n; i++) {
        // Leading spaces
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        // Character sequence: A→peak→A
        char p = 'A';
        int mid = (2 * i + 1) / 2;
        for (int k = 0; k < (2 * i) + 1; k++) {
            cout << p;
            if (k < mid) p++;
            else p--;
        }
        // Trailing spaces
        for (int l = 0; l < n - i - 1; l++) cout << " ";
        cout << endl;
    }
}

/**
 * Prints a reverse character triangle.
 * Row i starts from letter (n-i) and increments forward.
 * This makes each row begin at a higher letter and fill to 'Z' direction.
 *
 * Example (n=4):
 *   D
 *   CD
 *   BCD
 *   ABCD
 */
void printReverseCharTriangle(int n) {
    for (int i = 0; i < n; i++) {
        int start = (n - i);
        for (int j = 0; j <= i; j++) {
            cout << char(64 + start);
            start++;
        }
        cout << endl;
    }
}

// ─────────────────────────────────────────────────────────────────────────────
// MAIN
// ─────────────────────────────────────────────────────────────────────────────

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    cout << "\n1.  printRightTriangle\n";          printRightTriangle(n);
    cout << "\n2.  printInvertedRightTriangle\n";  printInvertedRightTriangle(n);
    cout << "\n3.  printSquare\n";                 printSquare(n);
    cout << "\n4.  printHollowSquare\n";           printHollowSquare(n);
    cout << "\n5.  printRightAlignedTriangle\n";   printRightAlignedTriangle(n);
    cout << "\n6.  printPyramid\n";                printPyramid(n);
    cout << "\n7.  printInvertedPyramid\n";        printInvertedPyramid(n);
    cout << "\n8.  printDoublePyramid\n";          printDoublePyramid(n);
    cout << "\n9.  printDiamond\n";                printDiamond(n);
    cout << "\n10. printDoubleTriangle\n";         printDoubleTriangle(n);
    cout << "\n11. printButterfly\n";              printButterfly(n);
    cout << "\n12. printButterflyAlt\n";           printButterflyAlt(n);
    cout << "\n13. printSymmetricHourglass\n";     printSymmetricHourglass(n);
    cout << "\n14. printNumberRightTriangle\n";    printNumberRightTriangle(n);
    cout << "\n15. printRowNumberTriangle\n";      printRowNumberTriangle(n);
    cout << "\n16. printInvertedNumberTriangle\n"; printInvertedNumberTriangle(n);
    cout << "\n17. printBinaryTriangle\n";         printBinaryTriangle(n);
    cout << "\n18. printFloydTriangle\n";          printFloydTriangle(n);
    cout << "\n19. printNumberMirrorTriangle\n";   printNumberMirrorTriangle(n);
    cout << "\n20. printHollowRectangle\n";        printHollowRectangle(n);
    cout << "\n21. printNumberShell\n";            printNumberShell(n);
    cout << "\n22. printCharRightTriangle\n";      printCharRightTriangle(n);
    cout << "\n23. printInvertedCharTriangle\n";   printInvertedCharTriangle(n);
    cout << "\n24. printSameCharPerRow\n";         printSameCharPerRow(n);
    cout << "\n25. printCharDiamond\n";            printCharDiamond(n);
    cout << "\n26. printReverseCharTriangle\n";    printReverseCharTriangle(n);

    return 0;
}
